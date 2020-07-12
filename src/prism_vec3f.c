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

#include "prism_common.h"
#include "math/prism_vec3f.h"
#include "allocators/prism_allocator.h"

vec3f* vec3f_create(f64 x, f64 y, f64 z, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);
    
    res->x = x;
    res->y = y;
    res->z = z;

    return res;
}

vec3f* vec3f_add(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;

    return res;
}

vec3f* vec3f_sub(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = a->x - b->x;
    res->y = a->y - b->y;
    res->z = a->z - b->z;

    return res;
}

vec3f vec3f_mul(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = a->x * b->x;
    res->y = a->y * b->y;
    res->z = a->z * b->z;

    return res;
}

vec3f vec3f_div(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator)
{
    PRISM_ASSERT(float_equal(b->x, 0.0));
    PRISM_ASSERT(float_equal(b->y, 0.0));
    PRISM_ASSERT(float_equal(b->z, 0.0));

    vec3f* res = prism_allocate(allocator);

    res->x = a->x / b->x;
    res->y = a->y / b->y;
    res->z = a->z / b->z;

    return res;
}

f64 vec3f_dot(const vec3f* a, const vec3f* b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

vec3f vec3f_cross(const vec3f* a, const vec3f* b, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = (a->y * b->z - a->z * b->y);
    res->y = (a->z * b->x - a->x * b->z);
    res->z = (a->x * b->y - a->y * b->x);

    return res;
}

f64 vec3f_mag_sq(const vec3f* vec)
{
    return vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
}

f64 vec3f_mag(const vec3f* vec)
{
    return sqrt(vec3f_mag_sq(vec));
}

void vec3f_normalize(vec3f* vec)
{
    f64 mag = vec3f_mag(vec);
    
    PRISM_ASSERT(!(float_equal(mag, 0.0)));
    
    f64 inv_mag = 1.0/mag;

    vec->x *= inv_mag;
    vec->y *= inv_mag;
    vec->z *= inv_mag;
}

vec3f* vec3f_add_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = vec->x + val;
    res->y = vec->y + val;
    res->z = vec->z + val;

    return res;
}

vec3f* vec3f_sub_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = vec->x - val;
    res->y = vec->y - val;
    res->z = vec->z - val;

    return res;
}
vec3f* vec3f_mul_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);

    res->x = vec->x * val;
    res->y = vec->y * val;
    res->z = vec->z * val;

    return res;
}

vec3f* vec3f_div_scalar(const vec3f* vec, f64 val, prism_base_allocator_t* allocator)
{
    PRISM_ASSERT(!(float_equal(val, 0.0)));

    vec3f* res = prism_allocate(allocator);

    res->x = vec->x / val;
    res->y = vec->y / val;
    res->z = vec->z / val;

    return res;
}

vec3f* vec3f_normalized(const vec3f* vec, prism_base_allocator_t* allocator)
{
    vec3f* res = prism_allocate(allocator);
    *res = *vec;
    vec3f_normalize(res);
    return res;
}

