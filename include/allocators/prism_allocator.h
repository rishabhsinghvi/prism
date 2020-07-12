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

#ifndef PRISM_ALLOCATOR_H
#define PRISM_ALLOCATOR_H

#include "prism_common.h"
#include "allocators/prism_base_allocator.h"
#include "allocators/prism_frame_allocator.h"
#include "allocators/prism_pool_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

PRISM_API void* prism_allocate(prism_base_allocator_t* allocator, size_t bytes, size_t alignment);

#ifdef __cplusplus
}
#endif


#endif