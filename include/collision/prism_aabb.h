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

#ifndef PRISM_AABB_H
#define PRISM_AABB_H

#include "prism_common.h"
#include "math/prism_vec3f.h"
#include "allocators/prism_base_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{ 
    vec3f min;
    vec3f max;
} aabb_t;


PRISM_API aabb_t* prism_aabb_create_from_vec(const vec3f* min, const vec3f* max, prism_base_allocator_t* allocator);
PRISM_API aabb_t* prism_aabb_create_from_scalar(f64 mix, f64 miy, f64 miz, f64 max, f64 may, f64 maz, prism_base_allocator_t* allocator);

PRISM_API vec3f* prism_aabb_center(const aabb_t* aabb, prism_base_allocator_t* allocator);

PRISM_API bool prism_aabb_contains_point(const aabb_t* aabb, const vec3f* point);
PRISM_API bool prism_aabb_overlap(const aabb_t* a, const aabb_t* b);

#ifdef __cplusplus
}
#endif

#endif