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
#ifndef __RWNX_TX_H__
#define __RWNX_TX_H__
#include <lwip/mem.h>
#include <lwip/opt.h>
#include <utils_list.h>

#include "bl_utils.h"
#include "hal_desc.h"
#include "ipc_shared.h"
#include "lmac_types.h"

/**
***********
*
* @file bl_tx.h
* Copyright (C) Bouffalo Lab 2016-2018
*
***********
*/

/**
 * struct bl_txhdr - Stucture to control transimission of packet
 * (Added in skb headroom)
 *
 * @sw_hdr: Information from driver
 * @hw_hdr: Information for/from hardware
 */
struct bl_txhdr {
  struct utils_list_hdr item;
  union bl_hw_txstatus status;
  uint32_t *p;
  struct hostdesc host;
};
err_t bl_output(struct bl_hw *bl_hw, struct netif *netif, struct pbuf *p,
                int is_sta);
int bl_txdatacfm(void *pthis, void *host_id);
void bl_tx_notify();
void bl_tx_try_flush();
void bl_irq_handler();
#endif
