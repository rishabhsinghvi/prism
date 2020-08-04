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

#include "body/prism_island.h"
#include "allocators/prism_allocator.h"

struct prism_island_t
{
    prism_body_t** body_list;
    u32 body_capacity;
    u32 body_count;

    u32 iterations;
};

prism_island_t* prism_island_create(u32 body_capacity, u32 constraint_capacity, prism_base_allocator_t* allocator)
{
    prism_island_t* island = (prism_island_t*)PRISM_ALLOCATE(allocator, prism_island_t);

    if(!island)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate prism_island_t.\n");
        return NULL;
    }

    island->body_list = (prism_body_t**)PRISM_ALLOCATE(allocator, prism_body_t*);

    if(!island->body_list)
    {
        PRISM_DEBuG_MSG("[ALLOCATION ERROR]: Unable to allocate body_capacity * prism_body_t*\n");
        if(!allocator)
        {
            PRISM_FREE(island);
        }
        return NULL;
    }

    island->body_capacity = body_capacity;
    island->body_count = 0;
}

void prism_island_insert_body(prism_island_t* island, prism_body_t* body)
{
    PRISM_ASSERT(island);
    PRISM_ASSERT(island->body_count < island->body_capacity);

    island->body_list[island->body_count++] = body;
}

bool prism_check_if_island_sleeping(prism_island_t* island)
{   
    PRISM_ASSERT(island);

    bool is_sleeping = false;

    /* An island only needs one body and/or constraint to be awake for it to be awake. */

    for(size_t i = 0; i < island->body_count; i++)
    {
        is_sleeping = is_sleeping || island->body_list[i]->is_sleeping;
    }

    return is_sleeping;
}

/* Enabling randomization can lead to more stable results; however, it incurs a performance penalty */
static bool prism_island_randomize_constraints(prism_island_t* island)
{
    PRISM_ASSERT(island);


}

