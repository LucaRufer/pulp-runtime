/*
 * Copyright 2024 Mosaic SoC Ltd. All rights reserved.
 * Authors: Luca Rufer, luca@mosaic-soc.com
 */

#ifndef __ARCHI_CHIPS_DORMOUSE_PROPERTIES_H__
#define __ARCHI_CHIPS_DORMOUSE_PROPERTIES_H__

/*
 * MEMORIES
 */
#define ARCHI_DORMOUSE_BASE_ADDR 0x00000000
#define ARCHI_DORMOUSE_PERIPH_OFFSET 0x01000000
#define ARCHI_DORMOUSE_MEM_OFFSET 0x10000000

#define ARCHI_HAS_L2                   1
#define ARCHI_HAS_L2_MULTI             1
// #define ARCHI_HAS_L1                   1

/*
 * MEMORY ALIAS
 */

#define ARCHI_HAS_L1_ALIAS             0
#define ARCHI_HAS_L2_ALIAS             0

/*
 * IP VERSIONS
 */
#define RISCV_VERSION       5

/*
 * FC
 */

#define ARCHI_FC_CID         0
#define ARCHI_HAS_FC_ITC     1
#define ARCHI_HAS_FC         1
#define ARCHI_CORE_HAS_1_10  1

#endif /* __ARCHI_CHIPS_DORMOUSE_PROPERTIES_H__ */
