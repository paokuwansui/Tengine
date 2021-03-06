/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2019, Open AI Lab
 * Author: zpluo@openailab.com
 */

#ifndef __PRELU_KERNEL_H__
#define __PRELU_KERNEL_H__

#include <stdint.h>
#include <math.h>
#include "compiler_fp16.h"

#ifdef __cplusplus
extern "C" {
#endif


struct prelu_param;

struct prelu_param
{
    int layout;
    float scale;
    int zero;
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef int (*prelu_t)(void * data,void * out_data, int dim0,int dim1,int dim2,int dim3,float* slope,const prelu_param* param);


#ifdef CONFIG_KERNEL_FP32
#include "prelu_fp32.c"
#endif

#ifdef CONFIG_KERNEL_FP16
#include "prelu_fp16.c" 
#endif

#ifdef CONFIG_KERNEL_INT8
#include "prelu_int8.c"
#endif

#ifdef CONFIG_KERNEL_UINT8
#include "prelu_uint8.c"
#endif




#ifdef __cplusplus
}
#endif

#endif