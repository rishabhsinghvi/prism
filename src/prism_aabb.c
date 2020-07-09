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
#include "collision/prism_aabb.h"

aabb_t* prism_aabb_create_from_vec(const vec3f* min, const vec3f* max)
{
    aabb_t* aabb = (aabb_t*)PRISM_ALLOC(sizeof(aabb_t));

    if(!aabb)
    {
        PRISM_DEBUG_MSG("[ERROR]: Unable to allocate aabb_t.\n");
        return NULL;
    }

    aabb->min = *min;
    aabb->max = *max;

    return aabb;
}

aabb_t* prism_aabb_create_from_scalar(f64 mix, f64 miy, f64 miz, f64 max, f64 may, f64 maz)
{
    aabb_t* aabb = (aabb_t*)PRISM_ALLOC(sizeof(aabb_t));

    if(!aabb)
    {
        PRISM_DEBUG_MSG("[ERROR]: Unable to allocate aabb_t.\n");
        return NULL;
    }

    aabb->min = vec3f_create(mix, miy, miz);
    aabb->max = vec3f_create(max, may, maz);

    return aabb;
}

vec3f prism_aabb_center(const aabb_t* aabb)
{
    vec3f res;

    vec3f sum = vec3f_add(&aabb->min, &aabb->max);
    res = vec3f_div_scalar(&sum, 2.0);

    return res;
}

bool prism_aabb_contains_point(const aabb_t* aabb, const vec3f* point)
{
    const vec3f* min = &aabb->min;
    const vec3f* max = &aabb->max;

    return point->x >= min->x && point->x <= max->x && 
           point->y >= min->y && point->y <= max->y &&
           point->z >= min->z && point->z <= max->z;
}

bool prism_aabb_overlap(const aabb_t* a, const aabb_t* b)
{
    const vec3f* amin = &a->min;
    const vec3*f amax = &b->max;

    const vec3f* bmin = &b->min;
    const vec3f* bmax = &b->max;

    return amin->x <= bmax->x && amax->x >= bmin->x &&
           amin->y <= bmax->y && amax->y >= bmin->y &&
           amin->z <= bmax->z && amax->z >= bmin->z;
}

