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

#ifndef PRISM_POOL_ALLOCATOR_H
#define PRISM_POOL_ALLOCATOR_H

#include "prism_common.h"
#include "allocators/prism_base_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pool_internal_node_t pool_internal_node_t;

typedef struct
{
    prism_allocator_type allocator_type;
    void* arena_mem;
    pool_internal_node_t* node_head;
    size_t pool_object_size;
    size_t max_pool_objects;
    size_t free_pool_objects;
} prism_pool_allocator_t;

PRISM_API prism_pool_allocator_t* prism_pool_allocator_create(size_t object_size, size_t max_pool_size);
PRISM_API void prism_pool_allocator_delete(prism_pool_allocator_t* allocator);

PRISM_API void* prism_pool_allocator_allocate(prism_frame_allocator_t* allocator);
PRISM_API void* prism_frame_allocator_free(prism_frame_allocator_t* allocator, void* pool_object);

#ifdef __cplusplus
}
#endif

#endif