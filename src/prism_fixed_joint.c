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

#include "constraints/prism_fixed_joint.h"
#include "allocators/prism_allocator.h"

prism_fixed_joint_t* prism_fixed_joint_create(u32 joint_id, prism_body_t* body1, prism_body_t* body2, vec3f* anchor_point, prism_base_allocator_t* allocator)
{
    prism_fixed_joint_t* joint = (prism_fixed_joint_t*)PRISM_ALLOCATE(allocator, prism_fixed_joint_t);

    if(!joint)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_fixed_joint_t.\n");
        return NULL;
    }

    joint->joint_id = joint_id;
    joint->body1 = body1;
    joint->body2 = body2;
    joint->anchor_point = anchor_point;
    joint->type = PRISM_JOINT_BALL_AND_SOCKET;

    return joint;
}