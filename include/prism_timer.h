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

#ifndef PRISM_ALLOCATOR_UTILS_H
#define PRISM_ALLOCATOR_UTILS_H

#include "prism_common.h"
#include "allocators/prism_base_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
#ifdef PRISM_PLATFORM_WINDOWS
    f64 start;
#else
    u64 start;
#endif
} prism_timer_t;

PRISM_API prism_timer_t* prism_timer_create(prism_base_allocator_t* allocator);
PRISM_API void prism_timer_reset(prism_timer_t* timer);
PRISM_API f64 prism_timer_dt(prism_timer_t* timer);

#ifdef __cplusplus
}
#endif

#endif