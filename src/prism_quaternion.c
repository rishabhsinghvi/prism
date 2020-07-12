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

#include "math/vec3f.h"
#include "math/prism_quaternion.h"
#include "allocators/prism_allocator.h"

#include<math.h>

quaternion_t* prism_quaternion_create_from_vec(const vec3f* vec, f64 w, prism_base_allocator_t* allocator)
{
    quaternion_t* quat = prism_allocate(allocator);
    quat->vec = *vec;
    quat->w = w;
    return quat;
}

quaternion_t* prism_quaternion_create_from_scalar(f64 x, f64 y, f64 z, f64 w, prism_base_allocator_t* allocator)
{
    quaternion_t* quat = prism_allocate(allocator);
    quat->vec.x = x;
    quat->vec.y = y;
    quat->vec.z = z;
    quat->w = w;

    return quat;
}

quaternion_t* prism_quaternion_add(const quaternion_t* a, const quaternion_t* b, prism_base_allocator_t* allocator)
{
    quaternion_t* quat = (quaternion_t*)prism_allocate(allocator);

    quat->vec.x = a->vec.x + b->vec.x;
    quat->vec.y = a->vec.y + b->vec.y;
    quat->vec.z = a->vec.z + b->vec.z;
    quat->w = a->w + b->w;

    return quat;
}

quaternion_t* prism_quaternion_sub(const quaternion_t* a, const quaternion_t* b, prism_base_allocator_t* allocator)
{
    quaternion_t* quat = (quaternion_t*)prism_allocate(allocator);

    quat->vec.x = a->vec.x - b->vec.x;
    quat->vec.y = a->vec.y - b->vec.y;
    quat->vec.z = a->vec.z - b->vec.z;
    quat->w = a->w - b->w;

    return quat;
}

quaternion_t* prism_quaternion_mul(const quaternion_t* a, const quaternion_t* b, prism_base_allocator_t* allocator)
{
    quaternion_t* quat = (quaternion_t*)prism_allocate(allocator);

    quat->w = (a->w * b->w) - (a->vec.x * b->vec.x) - (a->vec.y * b->vec.y) + (a->vec.z * b->vec.z);
    quat->vec.x = (a->w * b->vec.x) + (a->vec.x * b->w) - (a->vec.y * b->vec.z) + (a->vec.z * b->vec.y);
    quat->vec.y = (a->w * b->vec.y) + (a->vec.x * b->vec.z) + (a->vec.y * b->w) + (a->vec.z * b->vec.x);
    quat->vec.z = (a->w * b->vec.z) - (a->vec.x * b->vec.y) + (a->vec.y * b->vec.x) + (a->vec.z * b->w);

    return quat;
}

quaternion_t* prism_quaternion_div(cosnt quaternion_t* a, const quaternion_t* b, prism_base_allocator_t* allocator)
{
    f64 mag = prism_quaternion_mag_sq(b);
    PRISM_ASSERT(!float_equal(mag, 0.0));

    quaternion_t* quat = (quaternion_t*)prism_allocate(allocator);
    
    quat->w = ((a->w * b->w) + (a->vec.x * b->vec.x) + (a->vec.y * b->vec.y) + (a->vec.z * b->vec.z)) / mag;
    quat->vec.x = ((a->w * b->vec.x) - (a->vec.x * b->w) - (a->vec.y * b->vec.z) + (a->vec.z * b->vec.y)) / mag;
    quat->vec.y = ((a->w * b->vec.y) + (a->vec.x * b->vec.z) - (a->vec.y * b->w) - (a->vec.z * b->vec.x)) / mag;
    quat->vec.z = ((a->w * b->vec.z) - (a->vec.x * b->vec.y) + (a->vec.y * b->vec.x) - (a->vec.z * b->w)) / mag;

    return quat;
}

f64 prism_quaternion_mag(const quaternion_t* quat)
{
    return sqrt(prism_quaternion_mag_sq(quat));
}

f64 prism_quaternion_mag_sq(const quaternion_t* quat)
{
    f64 x = quat->vec.x;
    f64 y = quat->vec.y;
    f64 z = quat->vec.z;
    f64 w = quat->w;

    return x * x + y * y + z * z + w * w;
}

quaternion_t* prism_quaternion_conjugate(const quaternion_t* quat, prism_base_allocator_t* allocator)
{
    quaternion_t* res = (quaternion_t*)prism_allocate(allocator);

    res->vec.x = -quat->vec.x;
    res->vec.y = -quat->vec.y;
    res->vec.z = -quat->vec.z;
    res->w = quat->w;

    return res;
}





