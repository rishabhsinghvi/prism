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

#include "allocators/prism_frame_allocator.h"
#include "allocators/prism_allocator_utils.h"

prism_frame_allocator_t* prism_frame_allocator_create(size_t arena_size)
{
    prism_frame_allocator_t* allocator = (prism_frame_allocator_t*)PRISM_ALLOC(sizeof(prism_frame_allocator_t));

    if(!allocator)
    {
        PRISM_DEBUG_MSG("[ALLOCATOR ERROR]: Unable to allocate prism_frame_allocator_t.\n");
        return NULL;
    }

    void* mem = PRISM_ALLOC(arena_size);

    if(!mem)
    {
        PRISM_DEBUG_MSG("[ALLOCATOR ERROR]: Unable to allocate arena for prism_frame_allocator_t. Size: %d\n", arena_size);
        PRISM_FREE(allocator);
        return NULL;
    }

    allocator->allocator_type = ALLOCATOR_TYPE_FRAME;
    allocator->arena_mem = mem;
    allocator->arena_size = arena_size;
    allocator->arean_cur = mem;
    allocator->free_mem = arena_size;

    return allocator;
}

void prism_frame_allocator_delete(prism_frame_allocator_t* allocator)
{
    if(!allocator || !allocator->arena_mem)
        return;

    PRISM_FREE(allocator->arena_mem);
    PRISM_FREE(allocator);
}


void* prism_frame_allocator_allocate(prism_frame_allocator_t* allocator, size_t bytes, size_t alignment)
{
    if(!allocator || !allocator->arena_mem)
        return NULL;
    

    void* return_ptr = prism_get_aligned_addr(allocator->arena_cur, alignment);

    size_t adjustment = (uintptr_t)return_ptr - (uintptr_t)allocator->arena_cur;
    size_t total_alloc_size = adjustment + bytes;

    if(total_alloc_size > allocator->free_mem)
    {
        PRISM_DEBUG_MSG("[ALLOCATOR ERROR]: Not enough memory to allocate.\n");
        return NULL;
    }

    allocator->arena_cur = (void*)((uintptr_t)allocator->arena_cur + total_alloc_size);

    return return_ptr;
}

void prism_frame_allocator_reset(prism_frame_allocator_t* allocator)
{
    if(!allocator || !allocator->arena_mem)
        return;
    
    allocator->arena_cur = allcator->arena_mem;
    allocator->free_mem = allocator->arena_mem;
}



