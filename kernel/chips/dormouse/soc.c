/*
 * Copyright 2024 Mosaic SoC Ltd. All rights reserved.
 * Authors: Luca Rufer, luca@mosaic-soc.com
 */

#include "pulp.h"
#include "chips/dormouse/soc.h"

void __attribute__((constructor)) __copy_data (void) {
  extern char _sidata, _sdata, _edata;
  size_t *src = (size_t *) &_sidata;
  size_t *dst = (size_t *) &_sdata;
  size_t *end = (size_t *) &_edata;
  while (dst < end) {
    *dst++ = *src++;
  }
}

void pos_soc_init()
{
#if __PLATFORM__ != ARCHI_PLATFORM_FPGA
  pos_freq_domains[PI_FREQ_DOMAIN_FC] = ARCHI_ASIC_FC_FREQUENCY;
  pos_freq_domains[PI_FREQ_DOMAIN_PERIPH] = ARCHI_ASIC_PER_FREQUENCY;
  pos_freq_domains[PI_FREQ_DOMAIN_CL] = ARCHI_ASIC_CL_FREQUENCY;
#else
  pos_freq_domains[PI_FREQ_DOMAIN_FC] = ARCHI_FPGA_FC_FREQUENCY;
  pos_freq_domains[PI_FREQ_DOMAIN_PERIPH] = ARCHI_FPGA_PER_FREQUENCY;
  pos_freq_domains[PI_FREQ_DOMAIN_CL] = ARCHI_FPGA_CL_FREQUENCY;
#endif
}

