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


#ifndef PRISM_FIXED_JOINT_H
#define PRISM_FIXED_JOINT_H

#include "prism_common.h"
#include "constraints/prism_base_joint.h"
#include "allocators/prism_base_allocator.h"
#include "body/prism_body.h"
#include "prism_vec3f.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    prism_joint_type type;
    prism_body_t* body1;
    prism_body_t* body2;
    u32 joint_id;
    vec3f* anchor_point;
} prism_fixed_joint_t;

PRISM_API prism_fixed_joint_t* prism_fixed_joint_create(u32 joint_id, prism_body_t* body1, prism_body_t* body2, vec3f* anchor_point, prism_base_allocator_t* allocator);

#ifdef __cplusplus
}
#endif

#endif