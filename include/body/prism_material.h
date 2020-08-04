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

#ifndef PRISM_MATERIAL_H
#define PRISM_MATERIAL_H

#include "prism_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Describes how the friction and bounciness of two colliding bodies are combined 
 * In case of two colliding materials having different combine strategies,
 * priority is given in order: AVG < MIN < MULT < MAX
 */
typedef enum
{
    COMBINE_AVERAGE = 0,
    COMBINE_MINIMUM,
    COMBINE_MULTIPLY,
    COMBINE_MAXIMUM,
} combine_strategy;

typedef struct
{
    f64 dynamic_friction;
    f64 static_friction;
    f64 bounciness;
    combine_strategy friction_combine_strategy;
    combine_strategy bounciness_combine_strategy;
} prism_material_t;

#ifdef __cplusplus
}
#endif

#endif