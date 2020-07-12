/*
* MIT License
*
* Copyright (c) 2020 Rishabh Singhvi
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "allocators/prism_pool_allocator.h"

struct pool_internal_node_t
{
    pool_internal_node_t* next;
};

static void prism_internal_build_pool_representation(prism_pool_allocator_t* allocator)
{
    // TODO
}

static void* prism_internal_allocate_single_node(prism_pool_allocator_t* allocator)
{
    pool_internal_node_t* node = allocator->node_head;
    allocator->node_head = allocator->node_head->next;
    return (void*)node;
}

static bool prism_internal_bounds_check(prism_pool_allocator_t* allocator, void* object)
{
    void* arena_end = (void*)((uintptr_t)allocator->arena_mem + allocator->max_pool_objects * allocator->pool_object_size);
    return object >= allocator->arena_mem && object < allocator->arena_end;
}

void prism_internal_free_single_node(prism_pool_allocator_t* allocator, void* object)
{
    pool_internal_node_t* new_node = (pool_internal_node_t*)object;
    new_node->next = allocator->node_head;
    allocator->node_head = new_node;
}


prism_pool_allocator_t* prism_pool_allocator_create(size_t object_size, size_t max_pool_size)
{
    prism_pool_allocator_t* allocator = (prism_pool_allocator_t*)PRISM_ALLOC(sizeof(prism_pool_allocator_t));

    if(!allocator)
    {
        PRISM_DEBUG_MSG("[ALLOCATOR ERROR]: Unable to allocate prism_pool_allocator_t.\n");
        return NULL;
    }

    void* mem = PRISM_ALLOC(object_size * max_pool_size);

    if(!mem)
    {
        PRISM_DEBUG_MSG("[ALLOCATOR ERROR]: Unable to allocate arena for prism_pool_allocator_t.\n");
        PRISM_FREE(allocator);
        return NULL;
    }

    allocator->allocator_type = ALLOCATOR_TYPE_POOl;
    allocator->arena_mem = mem;
    allocator->pool_object_size = object_size;
    allocator->max_pool_objects = max_pool_size;
    allocator->free_pool_objects = max_pool_size;
    
    prism_internal_build_pool_representation(allocator);

    return allocator;
}


void prism_pool_allocator_delete(prism_pool_allocator_t* allocator)
{
    if(!allocator || !allocator->arena_mem)
        return;
    
    allocator->free_pool_objects = 0;
    allocator->max_pool_objects = 0;

    PRISM_FREE(allocator->arena_mem);
    PRISM_FREE(allocator);
}

void* prism_pool_allocator_allocate(prism_frame_allocator_t* allocator)
{
    if(!allocator || !allocator->arena_mem || allocator->free_pool_objects == 0)
        return NULL;
    
    allocator->free_pool_objects -= 1;
    return prism_internal_allocate_single_node(allocator);
}

void prism_frame_allocator_free(prism_frame_allocator_t* allocator, void* pool_object)
{
    if(!prism_internal_bounds_check(allocator, object))
        return;

    allocator->free_pool_objects += 1;
    prism_internal_free_single_node(allocator, pool_object);
}