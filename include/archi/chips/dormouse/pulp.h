/*
 * Copyright 2024 Mosaic SoC Ltd. All rights reserved.
 * Authors: Luca Rufer, luca@mosaic-soc.com
 */

#ifndef __ARCHI_CHIPS_DORMOUSE_H__
#define __ARCHI_CHIPS_DORMOUSE_H__

#include "archi/chips/dormouse/properties.h"
#include "archi/chips/dormouse/aon_soc_ctrl.h"
#include "archi/chips/dormouse/soc_ctrl.h"

// Host Core
#include "archi/cv32e40p/cv32e40p.h"
#include "archi/riscv/priv_1_12.h"

// Memory Map
#include "archi/chips/dormouse/memory_map.h"

// Peripherals
#include "archi/stdout/stdout_v3.h"
#include "archi/bus_err_unit/bus_err_unit_v1.h"

#endif /* __ARCHI_CHIPS_DORMOUSE_H__ */
