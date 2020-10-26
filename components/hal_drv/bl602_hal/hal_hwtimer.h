/*
 * Copyright (c) 2020 Bouffalolab.
 *
 * This file is part of
 *     *** Bouffalolab Software Dev Kit ***
 *      (see www.bouffalolab.com).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *   3. Neither the name of Bouffalo Lab nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __HAL_HWTIMER_H__
#define __HAL_HWTIMER_H__

#include <FreeRTOS.h>
#include <stdint.h>
#include <timers.h>
#include <utils_list.h>

typedef void (*hw_t)(void);

#ifdef HAL_USE_HW_TIMER
typedef struct hw_timer {
  utils_dlist_t dlist_item;
  int repeat;
  hw_t handler;
  uint32_t triggle_time;
  uint32_t calc_time;
} hw_timer_t;

int hal_hwtimer_init(void);
hw_timer_t *hal_hwtimer_create(uint32_t period, hw_t handler, int repeat);
int hal_hwtimer_delete(hw_timer_t *pstnode);
int hal_hwtimer_change_period(hw_timer_t *pstnode, uint32_t period);
#else
/*HW Timer based on FreeRTOS Software timer which using 64Bit mtimer on RISC-V
 * platform*/

/*fake struct only for pointer*/
typedef struct {
  void *null;
} hw_timer_t;
int hal_hwtimer_init(void);
hw_timer_t *hal_hwtimer_create(uint32_t period, hw_t handler, int repeat);
int hal_hwtimer_delete(hw_timer_t *pstnode);
int hal_hwtimer_change_period(hw_timer_t *pstnode, uint32_t period);
#endif

#endif
