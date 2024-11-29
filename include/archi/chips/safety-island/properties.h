/*
 * Copyright (C) 2023 ETH Zurich, University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef __ARCHI_CHIPS_SAFETY_ISLAND_PROPERTIES_H__
#define __ARCHI_CHIPS_SAFETY_ISLAND_PROPERTIES_H__

/*
 * FPGA
 */


/*
 * MEMORIES
 */
#define ARCHI_SAFETY_ISLAND_BASE_ADDR 0x00000000
#define ARCHI_SAFETY_ISLAND_PERIPH_OFFSET 0x01000000
#define ARCHI_SAFETY_ISLAND_MEM_OFFSET 0x10000000

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


#endif
