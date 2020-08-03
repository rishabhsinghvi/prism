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

#include "math/prism_mat33.h"
#include "allocators/prism_allocator.h"

mat33* prism_mat33_create(f64 _00, f64 _10, f64 _20, f64 _01, f64 _11, f64 _21, f64 _02, f64 _12, f64 _22, prism_base_allocator_t* allocator)
{
    mat33* mat = (mat33*)PRISM_ALLOCATE(allocator, mat33);

    if(!mat)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate mat33.\n");
        return NULL;
    }

    mat->_00 = _00;
    mat->_01 = _01;
    mat->_02 = _02;

    mat->_10 = _10;
    mat->_11 = _11;
    mat->_12 = _12;

    mat->_20 = _20;
    mat->_21 = _21;
    mat->_22 = _22;

    return mat;
}

mat33* prism_mat33_create_from_array(f64* array, prism_base_allocator_t* allocator)
{
    mat33* mat = (mat33*)PRISM_ALLOCATE(allocator, mat33);

    if(!mat)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate mat33.\n");
        return NULL;
    }

    /* Assumes that number of elements in the array >= 9 */

    for(size_t i = 0; i < 9; i++)
    {
        mat->data[i] = array[i];
    }

    return mat;

}

mat33* prism_mat33_add(const mat33* a, const mat33* b, prism_base_allocator_t* allocator)
{
    mat33* mat = (mat33*)PRISM_ALLOCATE(allocator, mat33);

    if(!mat)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate mat33.\n");
        return NULL;
    }

    for(size_t i = 0; i < 9; i++)
    {
        mat->data[i] = a->data[i] + b->data[i];
    }

    return mat;
}

mat33* prism_mat_sub(const mat33* a, const mat33* b, prism_base_allocator_t* allocator)
{
    mat33* mat = (mat33*)PRISM_ALLOCATE(allocator, mat33);

    if(!mat)
    {
        PRISM_DEBUG_MSG("[ALLOCATION ERROR]: Unable to allocate mat33.\n");
        return NULL;
    }

    for(size_t i = 0; i < 9; i++)
    {
        mat->data[i] = a->data[i] - b->data[i];
    }

    return mat;
}


