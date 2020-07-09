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

#ifndef PRISM_STACK_ALLOCATOR_H
#define PRISM_STACK_ALLOCATOR_H

#include "prism_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    void* arena;
    void* cur;
    size_t arena_size;
    size_t free_size;
    size_t allocations;
} frame_allocator_t;


PRISM_API frame_allocator_t frame_allocator_create(size_t arena_size);

PRISM_API void* frame_allocator_allocate(frame_allocator_t* allocator, size_t allocation_size, size_t alignment);
PRISM_API void frame_allocator_reset(frame_allocator_t* allocator);

PRISM_API void frame_allocator_delete(frame_allocator_t* allocator);

#ifdef __cplusplus
}
#endif

#endif