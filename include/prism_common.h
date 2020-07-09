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

#ifndef PRISM_COMMON_H
#define PRISM_COMMON_H

#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>

#if defined(_WIN32) || defined(_WIN64)
    #define PRISM_PLATFORM_WINDOWS
    #define PRISM_PLATFORM "Windows"
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PRISM_PLATFORM_WINDOWS
    #define PRISM_PLATFORM "Windows"
#elif defined(__linux__)
    #define PRISM_PLATFORM_LINUX
    #define PRISM_PLATFORM "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
    #define PRISM_PLATFORM_APPLE
    #define PRISM_PLATFORM "Apple"
#else
    #error "Cannot recognize build platform..."
#endif 

#if defined(PRISM_PLATFORM_WINDOWS)
    #define PRISM_SHARED_IMPORT __declspec(dllimport)
    #define PRISM_SHARED_EXPORT __declspec(dllexport)
    #define PRISM_SHARED_LOCAL 
#else
    #if __GNUC__ >= 4
        #define PRISM_SHARED_IMPORT __attribute__ ((visibility ("default")))
        #define PRISM_SHARED_EXPORT __attribute__ ((visibility ("default")))
        #define PRISM_SHARED_LOCAL __attribute__ ((visibility ("hidden")))
    #else
        #define PRISM_SHARED_IMPORT __declspec(dllimport)
        #define PRISM_SHARED_EXPORT __declspec(dllexport)
        #define PRISM_SHARED_LOCAL
    #endif
#endif


#if defined(PRISM_BUILD_SHARED)
    #ifdef PRISM_BUILD_LIB
        #define PRISM_API PRISM_SHARED_EXPORT
    #else
        #define PRISM_API PRISM_SHARED_IMPORT
    #endif
    #define PRISM_LOCAL PRISM_SHARED_LOCAL
#else
    #define PRISM_API 
    #define PRISM_LOCAL
#endif


#define PRISM_ASSERT(cond) assert(cond)
#define PRISM_DEBUG_MSG(...) fprintf(stderr, __VA_ARGS__)

#define BIT(x) 1 << x

#define PRISM_UNREACHABLE PRISM_ASSERT(false)

typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef uint32_t ui32;
typedef uint16_t ui16;
typedef uint8_t ui8;

typedef float f32;
typedef double f64;

#define PRISM_EPS 1e-5

#ifdef __cplusplus
extern "C" {
#endif

/* NOTE: Should I use an absolute scale for comparison? What are the odds of it breaking? */
static inline bool float_equal(f64 x, f64 y)
{
    return fabs(x - y) <= PRISM_EPS * (fabs(x) + fabs(y) + 1.0); 
}

#ifdef __cplusplus
}
#endif

#define PRISM_ALLOC(mem) malloc(mem)
#define PRISM_FREE(mem) free(mem)

#endif