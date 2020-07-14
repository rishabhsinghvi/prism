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

#ifndef PRISM_BOX_SHAPE_H
#define PRISM_BOX_SHAPE_H

#include "prism_common.h"
#include "shapes/prism_base_shape.h"
#include "math/prism_vec3f.h"
#include "allocators/prism_base_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 Defines a sphere shape. The position of the shape is derived from the transform of the body it is attached to.
*/
typedef struct
{
    prism_shape_type shape_type;
    vec3f dim;
} prism_box_t;

PRISM_API prism_box_t* prism_box_create_from_vec(const vec3f* dim, prism_base_allocator_t* allocator);
PRISM_API prism_box_t* prism_box_create_from_scalar(f64 x, f64 y, f64 z, prism_base_allocator_t* allocator);


#ifdef __cplusplus
}
#endif

#endif