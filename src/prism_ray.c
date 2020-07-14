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

#include "collision/prism_ray.h"
#include "allocators/prism_allocator.h"

prism_ray_t* prism_ray_create_from_vec(const vec3f* origin, const vec3f* dir, prism_base_allocator_t* allocator)
{
    prism_ray_t* ray = (prism_ray_t*)PRISM_ALLOCATE(allocator, prism_ray_t);

    if(!ray)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_ray_t.\n");
        return NULL;
    }
    
    ray->origin = *origin;
    ray->dir = *dir;

    return ray;
}

prism_ray_t* prism_ray_create_from_scalar(f64 or_x, f64 or_y, f64 or_z, f64 dir_x, f64 dir_y, f64 dir_z, prism_base_allocator_t* allocator)
{
    prism_ray_t* ray = (prism_ray_t*)PRISM_ALLOCATE(allocator, prism_ray_t);

    if(!ray)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_ray_t.\n");
        return NULL;
    }

    ray->origin.x = or_x;
    ray->origin.y = or_y;
    ray->origin.z = or_z;

    ray->dir.x = dir_x;
    ray->dir.y = dir_y;
    ray->dir.z = dir_z;

    return ray;
}

