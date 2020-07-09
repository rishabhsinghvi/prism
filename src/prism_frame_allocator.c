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

frame_allocator_t frame_allocator_create(size_t arena_size)
{
    frame_allocator_t allocator;

    void* mem = PRISM_ALLOC(arena_size);

    if(!mem)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate arena for frame allocator.\n");
        /* TODO: Something more robust */
    }

    allocator.arena = mem;
    allocator.cur = mem;
    allocator.arena_size = arena_size;
    allocator.free_size = arena_size;
    allocator.allocations = 0;
    
    return allocator;
}


void* frame_allocator_allocate(frame_allocator_t* allocator, size_t allocation_size, size_t alignment)
{
    /* Make sure alignment is a power of 2 */
    PRISM_ASSERT((alignment & (alignment - 1)) == 0);

    if(!allocator)
        return NULL;

    if(allocation_size > allocator->free_size)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Requested allocation size exceeds arena size.\n");
        return NULL;
    }

    void* return_ptr = prism_get_aligned_addr(allocator->cur, alignment);
    
    /* TODO: We are recalculating misalignment here. Maybe return from aligned address calculation? */
    size_t misalignment = (uintptr_t)return_ptr + (uintptr_t)allocator->cur;
    size_t usage = misalignment + allocation_size;
    
    allocator->free_size -= usage;
    allocator->allocations += 1;
    
    return return_ptr;
}


void frame_allocator_reset(frame_allocator_t* allocator)
{
    if(!allocator)
        return;
    
    allocator->cur = allocator->arena;
    allocator->allocations = 0;
    allocator->free_size = allocator->arena_size;
}


void frame_allocator_delete(frame_allocator_t* allocator)
{
    if(!allocator)
        return;
    
    PRISM_FREE(allocator->arena);
    PRISM_FREE(allocator);
    memset(allocator, 0, sizeof(frame_allocator_t));
}