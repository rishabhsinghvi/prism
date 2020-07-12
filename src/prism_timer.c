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

#include "prism_timer.h"

#if defined(PRISM_PLATFORM_WINDOWS)

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include<windows.h>

#elif defined(PRISM_PLATFORM_LINUX)|| defined(PRISM_PLATFORM_APPLE)

#include<sys/time.h>

#endif

#ifdef PRISM_PLATFORM_WINDOWS
static f64 prism_internal_win32_get_inv_freq()
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return 1000000.0/(f64)freq.QuadPart;
}
static f64 inv_freq = prism_internal_win32_get_inv_freq();
#endif


prism_timer_t* prism_timer_create(prism_base_allocator_t* allocator)
{
    prism_timer_t* timer = (prism_timer_t*)PRISM_ALLOCATE(allocator, prism_timer_t);
    
    if(!timer)
    {
        PRISM_DEBUG_MSG("[TIMER ERROR]: Unable to allocate prism_timer_t");
        return NULL;
    }

    prism_timer_reset(timer);
    return timer;
}

void prism_timer_reset(prism_timer_t* timer)
{
    #ifdef PRISM_PLATFORM_WINDOWS
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    timer->start = (f64)counter.QuadPart;
#else
    timeval time;
    gettimeofday(&time, 0);
    timer->start = time.tv_usec;
#endif
}

f64 prism_timer_dt(prism_timer_t* timer)
{
#ifdef PRISM_PLATFORM_WINDOWS
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    f64 count = (f64)counter.QuadPart;
    f64 dt = inv_freq * (count - timer->start);
    return dt;
#endif
}

