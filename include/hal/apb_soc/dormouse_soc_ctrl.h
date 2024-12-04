/*
 * Copyright 2024 Mosaic SoC Ltd. All rights reserved.
 * Authors: Luca Rufer, luca@mosaic-soc.com
 */

#ifndef __HAL_DORMOUSE_SOC_CTRL_H__
#define __HAL_DORMOUSE_SOC_CTRL_H__

// Compatability Layer for miniPULP

#include "archi/pulp.h"
#include "hal/pulp_io.h"
#define APB_SOC_STATUS_EOC_BIT  31

static inline void apb_soc_bootaddr_set(unsigned int value) {
  pulp_write32(ARCHI_SOC_CTRL_ADDR + SOC_CTRL_BOOTADDR_REG_OFFSET, value);
}

static inline unsigned int apb_soc_bootaddr_get(void) {
  return pulp_read32(ARCHI_SOC_CTRL_ADDR + SOC_CTRL_BOOTADDR_REG_OFFSET);
}

static inline void apb_soc_status_set(unsigned int value) {
  pulp_write32(ARCHI_SOC_CTRL_ADDR + SOC_CTRL_CORESTATUS_REG_OFFSET, value | (1<<APB_SOC_STATUS_EOC_BIT));
}

#endif // __HAL_DORMOUSE_SOC_CTRL_H__
