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

#ifndef PRISM_WORLD_H
#define PRISM_WORLD_H

#include "prism_common.h"
#include "math/prism_math.h"
#include "shapes/prism_shapes.h"
#include "constraints/prism_joint.h"
#include "body/prism_body.h"
#include "body/prism_island.h"
#include "allocators/prism_frame_allocator.h"
#include "prism_world_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
    f64 default_timestep;
    
    vec3f gravity;

    prism_body_t** body_list;
    u32 body_count;
    
    u32 iterations;

    prism_frame_allocator_t* frame_allocator;
} prism_world_t;

PRISM_API prism_world_t* prism_world_create(prism_base_allocator_t* allocator);
PRISM_API prism_world_t* prism_world_create_from_config(const prism_world_config_t* config);

PRISM_API void prism_world_simulate_fixed_timestep(prism_world_t* world);
PRISM_API void prism_world_simulate(prism_world_t* world, f64 timestep);


#ifdef __cplusplus
}
#endif

#endif