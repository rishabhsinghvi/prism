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

#include "prism_world.h"

#define DEFAUT_TIMESTEP 1000.0/60.0
#define DEFAULT_GRAVITY_X 0.0
#define DEFAULT_GRAVITY_Y -10.0
#define DEFAULT_GRAVITY_Z 0.0
#define DEFAULT_ITERATIONS 5
#define DEFAULT_FRAME_ALLOCATOR_SIZE 1024

prism_world_t* prism_world_create(prism_base_allocator_t* allocator)
{
    prism_world_t* world = PRISM_ALLOCATE(allocator, prism_world_t);

    if(!world)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_world_t.\n");
        return NULL;
    }

    world->default_timestep = DEFAUT_TIMESTEP;
    world->iterations = DEFAULT_ITERATIONS;

    world->gravity.x  = DEFAULT_GRAVITY_X;
    world->gravity.y  = DEFAULT_GRAVITY_Y;
    world->gravity.z  = DEFAULT_GRAVITY_Z;

    world->frame_allocator = prism_frame_allocator_create(DEFAULT_FRAME_ALLOCATOR_SIZE);
    return world;
}

prism_world_t* prism_world_create_from_config(const prism_world_config_t* config, prism_base_allocator_t* allocator)
{

    prism_world_t* world = PRISM_ALLOCATE(allocator, prism_world_t);

    if(!world)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_world_t.\n");
        return NULL;
    }
}

void prism_world_simulate_fixed_timestep(prism_world_t* world)
{
    prism_world_step(world, world->default_timestep);
}

void prism_world_simulate(prism_world_t* world, f64 timestep)
{
    if(!world)
        return;

    /* Create island */

    prism_island_t* island = prism_island_create(world->body_count, 0, (prism_base_allocator_t*)world->frame_allocator);
    
    for(size_t i = 0; i < world->body_count; i++)
    {
        
    }

}