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

#ifndef PRISM_VEC3F_H
#define PRISM_VEC3F_H

#include "prism_common.h"
#include "allocators/prism_base_allocator.h"

/*
 * TODO: Profile and use SIMD if needed 
*/

#ifdef __cplusplus
extern "C" {
#endif

typedef union
{
    struct
    {
        f64 x;
        f64 y;
        f64 z;
    };
    f64 data[3];
} vec3f;

PRISM_API vec3f* vec3f_create(f64 x, f64 y, f64 z, prism_base_allocator_t* allocator);

PRISM_API vec3f* vec3f_add(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator);
PRISM_API vec3f* vec3f_sub(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator);
PRISM_API vec3f* vec3f_mul(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator);
PRISM_API vec3f* vec3f_div(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator);


PRISM_API void vec3f_update_add_scalar(vec3f* vec, f64 val);


PRISM_API vec3f* vec3f_add_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator);
PRISM_API vec3f* vec3f_sub_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator);
PRISM_API vec3f* vec3f_mul_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator);
PRISM_API vec3f* vec3f_div_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator);

PRISM_API f64 vec3f_dot(const vec3f* a, const vec3f* b);
PRISM_API vec3f* vec3f_cross(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator);

PRISM_API f64 vec3f_mag_sq(const vec3f* vec);
PRISM_API f64 vec3f_mag(const vec3f* vec);

PRISM_API void vec3f_normalize(vec3f* vec);
PRISM_API vec3f* vec3f_normalized(const vec3f* vec, prism_base_allocator_t* allocator);

#ifdef __cplusplus
}
#endif

#endif