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


#ifndef PRISM_BODY_H
#define PRISM_BODY_H

#include "prism_common.h"
#include "math/prism_math.h"
#include "allocators/prism_base_allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    BODY_TYPE_DYNAMIC,
    BODY_TYPE_STATIC,
    BODY_TYPE_KINEMATIC
} prism_body_type;

typedef struct 
{
    prism_body_type body_type;

    transform_t transform;
    
    mat33 inv_inertia_model;
    mat33 inv_inertia_world;
    
    vec3f linear_vel;
    vec3f ang_vel;
    vec3f force;
    vec3f torque;

    vec3f local_center;
    vec3f world_center;

    f64 mass;
    f64 invmass;

    f64 lin_damping;
    f64 ang_damping;

    void* user_data;

    bool enable_sleeping;
    bool is_sleeping;
} prism_body_t;


PRISM_API prism_body_t* prism_body_create(prism_body_type type, prism_base_allocator_t* allocator);

PRISM_API void prism_body_set_sleeping(prism_body_t* body, bool state);
PRISM_API void prism_body_allow_sleeping(prism_body_t* body, bool state);


#ifdef __cplusplus
}
#endif

#endif