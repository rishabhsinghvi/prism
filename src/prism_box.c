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

#include "shapes/prism_box.h"
#include "allocators/prism_allocator.h"

prism_box_t* prism_box_create_from_vec(const vec3f* dim, prism_base_allocator_t* allocator)
{
    prism_box_t* box = (prism_box_t*)PRISM_ALLOCATE(allocator, prism_box_t);

    if(!box)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_box_t.\n");
        return NULL;
    }

    box->dim = *dim;
    return box;
}

prism_box_t* prism_box_create_from_scalar(f64 x, f64 y, f64 z, prism_base_allocator_t* allocator)
{
    prism_box_t* box = (prism_box_t*)PRISM_ALLOCATE(allocator, prism_box_t);

    if(!box)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_box_t.\n");
        return NULL;
    }

    box->dim.x = x;
    box->dim.y = y;
    box->dim.z = z;

    return box;
}

