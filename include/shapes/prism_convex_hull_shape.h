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

#ifndef PRISM_CONVEX_HULL_SHAPE_H
#define PRISM_CONVEX_HULL_SHAPE_H

#include "prism_common.h"
#include "allocators/prism_base_allocator.h"
#include "math/prism_vec3f.h"
#include "shapes/prism_base_shape.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct prism_half_edge_t prism_half_edge_t;
typedef struct prism_face_t prism_face_t;
typedef struct prism_convex_hull_shape_t prism_convex_hull_shape_t;

struct prism_half_edge_t
{
    u32 vertex;
    u32 face;
    u32 next;
    u32 prev;
    u32 opp;
};

struct prism_face_t
{
    u32 vertices[3];
    u32 normal;
    u32 centroid;
    u32 half_edge;
};


struct prism_convex_hull_shape_t
{
    prism_shape_type shape_type;
    vec3f* vertices;
    prism_half_edge_t* half_edges;
    prism_face_t* prism_face_t;
    vec3f* normals;
    vec3f* centroid;
    u32 vertices_count;
    u32 half_edges_count;
    u32 face_count; // Number of faces = number of normals = number of centroids
};


PRISM_API prism_convex_hull_shape_t* prism_convex_shape_create(vec3f* vertices, u32 count, prism_base_allocator_t* allocator);

#ifdef __cplusplus
}
#endif

#endif