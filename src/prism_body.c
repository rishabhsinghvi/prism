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

#include "body/prism_body.h"
#include "allocators/prism_allocator.h"

prism_body_t* prism_body_create(prism_body_type type, prism_base_allocator_t* allocator)
{
    prism_body_t* body = (prism_body_t*)PRISM_ALLOCATE(allocator, prism_body_t);

    if(!body)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_body_t.\n");
        return NULL;
    }  

    memset(body, 0, sizeof(prism_body_t));

    body->body_type = type;
    return body;
}

void prism_body_set_sleeping(prism_body_t* body, bool state)
{
    if(!body)
        return;
    
    body->is_sleeping = state;
}


void prism_body_allow_sleeping(prism_body_t* body, bool state)
{
    if(!body)
        return;

    body->enable_sleeping = state;
}

