/*
 * Copyright 2024 Mosaic SoC Ltd. All rights reserved.
 * Authors: Luca Rufer, luca@mosaic-soc.com
 */

#ifndef __DORMOUSE_SOC_H__
#define __DORMOUSE_SOC_H__


/* TODO To be updated once clock domains are defined */
#define POS_FLL_CL 2
#define POS_FLL_PERIPH 1
#define POS_FLL_FC 0

int pos_freq_domains[PI_FREQ_NB_DOMAINS];


void pos_soc_init();

static inline int pos_freq_get_fll(int domain)
{
    switch (domain)
    {
        case PI_FREQ_DOMAIN_FC:
            return POS_FLL_FC;

        case PI_FREQ_DOMAIN_PERIPH:
            return POS_FLL_PERIPH;

        case PI_FREQ_DOMAIN_CL:
        default:
            return POS_FLL_CL;
    }
}

#endif /* __DORMOUSE_SOC_H__ */
