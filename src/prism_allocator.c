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

#include "allocators/prism_allocator.h"

void* prism_allocate(prism_base_allocator_t* allocator, size_t bytes, size_t alignment)
{
    if(!allocator)
        return PRISM_ALLOC(bytes);
    
    switch(allocator->allocator_type)
    {
        case ALLOCATOR_TYPE_FRAME:
            return prism_frame_allocator_allocate((prism_frame_allocator_t*)allocator, bytes, alignment);
        
        case ALLOCATOR_TYPE_POOL:    
        {  
            prism_pool_allocator_t* pool_allocator = (prism_pool_allocator_t*)allocator;
            PRISM_ASSERT(bytes == pool_allocator->pool_object_size);
            return prism_pool_allocator_allocate(pool_allocator);
        }

        case ALLOCATOR_TYPE_LINEAR:
        default:
            PRISM_UNREACHABLE;
    }

    PRISM_UNREACHABLE;
}