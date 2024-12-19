// Generated register defines for aon_soc_ctrl

// Copyright information found in source file:
// Copyright 2024 Mosaic SoC Ltd. All rights reserved.

#ifndef _AON_SOC_CTRL_REG_DEFS_
#define _AON_SOC_CTRL_REG_DEFS_

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define AON_SOC_CTRL_PARAM_REG_WIDTH 32

// Core Boot Address
#define AON_SOC_CTRL_BOOTADDR_REG_OFFSET 0x0

// Core Boot Mode
#define AON_SOC_CTRL_BOOTMODE_REG_OFFSET 0x4
#define AON_SOC_CTRL_BOOTMODE_BOOTMODE_MASK 0x3
#define AON_SOC_CTRL_BOOTMODE_BOOTMODE_OFFSET 0
#define AON_SOC_CTRL_BOOTMODE_BOOTMODE_FIELD \
  ((bitfield_field32_t) { .mask = AON_SOC_CTRL_BOOTMODE_BOOTMODE_MASK, .index = AON_SOC_CTRL_BOOTMODE_BOOTMODE_OFFSET })

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _AON_SOC_CTRL_REG_DEFS_
// End generated register defines for aon_soc_ctrl