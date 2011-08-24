/*
 * Copyright (c) 2010 Broadcom Corporation
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _BRCM_TYPES_H_
#define _BRCM_TYPES_H_

#include <linux/types.h>
#include <linux/io.h>

#if 0
/* Bus types */
#define SDIO_BUS		3	/* SDIO target */
#define USB_BUS			5	/* USB (does not support R/W REG) */
#define SPI_BUS			6	/* gSPI target */
#define RPC_BUS			7	/* RPC target */
#endif

#define WL_CHAN_FREQ_RANGE_2G      0
#define WL_CHAN_FREQ_RANGE_5GL     1
#define WL_CHAN_FREQ_RANGE_5GM     2
#define WL_CHAN_FREQ_RANGE_5GH     3

#define MAX_DMA_SEGS 4

/* boardflags */

/* Board has gpio 9 controlling the PA */
#define	BFL_PACTRL		0x00000002
/* Not ok to power down the chip pll and oscillator */
#define	BFL_NOPLLDOWN		0x00000020
/* Board supports the Front End Module */
#define BFL_FEM			0x00000800
/* Board has an external LNA in 2.4GHz band */
#define BFL_EXTLNA		0x00001000
/* Board has no PA */
#define BFL_NOPA		0x00010000
/* Power topology uses BUCKBOOST */
#define BFL_BUCKBOOST		0x00200000
/* Board has FEM and switch to share antenna w/ BT */
#define BFL_FEM_BT		0x00400000
/* Power topology doesn't use CBUCK */
#define BFL_NOCBUCK		0x00800000
/* Power topology uses PALDO */
#define BFL_PALDO		0x02000000
/* Board has an external LNA in 5GHz band */
#define BFL_EXTLNA_5GHz		0x10000000

/* boardflags2 */

/* Board has an external rxbb regulator */
#define BFL2_RXBB_INT_REG_DIS	0x00000001
/* Flag to implement alternative A-band PLL settings */
#define BFL2_APLL_WAR		0x00000002
/* Board permits enabling TX Power Control */
#define BFL2_TXPWRCTRL_EN	0x00000004
/* Board supports the 2X4 diversity switch */
#define BFL2_2X4_DIV		0x00000008
/* Board supports 5G band power gain */
#define BFL2_5G_PWRGAIN		0x00000010
/* Board overrides ASPM and Clkreq settings */
#define BFL2_PCIEWAR_OVR	0x00000020
#define BFL2_LEGACY		0x00000080
/* 4321mcm93 board uses Skyworks FEM */
#define BFL2_SKWRKFEM_BRD	0x00000100
/* Board has a WAR for clock-harmonic spurs */
#define BFL2_SPUR_WAR		0x00000200
/* Flag to narrow G-band PLL loop b/w */
#define BFL2_GPLL_WAR		0x00000400
/* Tx CCK pkts on Ant 0 only */
#define BFL2_SINGLEANT_CCK	0x00001000
/* WAR to reduce and avoid clock-harmonic spurs in 2G */
#define BFL2_2G_SPUR_WAR	0x00002000
/* Flag to widen G-band PLL loop b/w */
#define BFL2_GPLL_WAR2	        0x00010000
#define BFL2_IPALVLSHIFT_3P3    0x00020000
/* Use internal envelope detector for TX IQCAL */
#define BFL2_INTERNDET_TXIQCAL  0x00040000
/* Keep the buffered Xtal output from radio "ON". Most drivers will turn it
 * off without this flag to save power. */
#define BFL2_XTALBUFOUTEN       0x00080000

/*
 * board specific GPIO assignment, gpio 0-3 are also customer-configurable
 * led
 */

/* bit 9 controls the PA on new 4306 boards */
#define	BOARD_GPIO_PACTRL	0x200
#define BOARD_GPIO_12		0x1000
#define BOARD_GPIO_13		0x2000

/* **** Core type/rev defaults **** */
#define D11CONF		0x0fffffb0	/* Supported  D11 revs: 4, 5, 7-27
					 * also need to update wlc.h MAXCOREREV
					 */

#define NCONF		0x000001ff	/* Supported nphy revs:
					 *      0       4321a0
					 *      1       4321a1
					 *      2       4321b0/b1/c0/c1
					 *      3       4322a0
					 *      4       4322a1
					 *      5       4716a0
					 *      6       43222a0, 43224a0
					 *      7       43226a0
					 *      8       5357a0, 43236a0
					 */

#define LCNCONF		0x00000007	/* Supported lcnphy revs:
					 *      0       4313a0, 4336a0, 4330a0
					 *      1
					 *      2       4330a0
					 */

#define SSLPNCONF	0x0000000f	/* Supported sslpnphy revs:
					 *      0       4329a0/k0
					 *      1       4329b0/4329C0
					 *      2       4319a0
					 *      3       5356a0
					 */

/********************************************************************
 * Phy/Core Configuration.  Defines macros to to check core phy/rev *
 * compile-time configuration.  Defines default core support.       *
 * ******************************************************************
 */

/* Basic macros to check a configuration bitmask */

#define CONF_HAS(config, val)	((config) & (1 << (val)))
#define CONF_MSK(config, mask)	((config) & (mask))
#define MSK_RANGE(low, hi)	((1 << ((hi)+1)) - (1 << (low)))
#define CONF_RANGE(config, low, hi) (CONF_MSK(config, MSK_RANGE(low, high)))

#define CONF_IS(config, val)	((config) == (1 << (val)))
#define CONF_GE(config, val)	((config) & (0-(1 << (val))))
#define CONF_GT(config, val)	((config) & (0-2*(1 << (val))))
#define CONF_LT(config, val)	((config) & ((1 << (val))-1))
#define CONF_LE(config, val)	((config) & (2*(1 << (val))-1))

/* Wrappers for some of the above, specific to config constants */

#define NCONF_HAS(val)	CONF_HAS(NCONF, val)
#define NCONF_MSK(mask)	CONF_MSK(NCONF, mask)
#define NCONF_IS(val)	CONF_IS(NCONF, val)
#define NCONF_GE(val)	CONF_GE(NCONF, val)
#define NCONF_GT(val)	CONF_GT(NCONF, val)
#define NCONF_LT(val)	CONF_LT(NCONF, val)
#define NCONF_LE(val)	CONF_LE(NCONF, val)

#define LCNCONF_HAS(val)	CONF_HAS(LCNCONF, val)
#define LCNCONF_MSK(mask)	CONF_MSK(LCNCONF, mask)
#define LCNCONF_IS(val)		CONF_IS(LCNCONF, val)
#define LCNCONF_GE(val)		CONF_GE(LCNCONF, val)
#define LCNCONF_GT(val)		CONF_GT(LCNCONF, val)
#define LCNCONF_LT(val)		CONF_LT(LCNCONF, val)
#define LCNCONF_LE(val)		CONF_LE(LCNCONF, val)

#define D11CONF_HAS(val) CONF_HAS(D11CONF, val)
#define D11CONF_MSK(mask) CONF_MSK(D11CONF, mask)
#define D11CONF_IS(val)	CONF_IS(D11CONF, val)
#define D11CONF_GE(val)	CONF_GE(D11CONF, val)
#define D11CONF_GT(val)	CONF_GT(D11CONF, val)
#define D11CONF_LT(val)	CONF_LT(D11CONF, val)
#define D11CONF_LE(val)	CONF_LE(D11CONF, val)

#define PHYCONF_HAS(val) CONF_HAS(PHYTYPE, val)
#define PHYCONF_IS(val)	CONF_IS(PHYTYPE, val)

#define NREV_IS(var, val) \
	(NCONF_HAS(val) && (NCONF_IS(val) || ((var) == (val))))

#define NREV_GE(var, val) \
	(NCONF_GE(val) && (!NCONF_LT(val) || ((var) >= (val))))

#define NREV_GT(var, val) \
	(NCONF_GT(val) && (!NCONF_LE(val) || ((var) > (val))))

#define NREV_LT(var, val) \
	(NCONF_LT(val) && (!NCONF_GE(val) || ((var) < (val))))

#define NREV_LE(var, val) \
	(NCONF_LE(val) && (!NCONF_GT(val) || ((var) <= (val))))

#define LCNREV_IS(var, val) \
	(LCNCONF_HAS(val) && (LCNCONF_IS(val) || ((var) == (val))))

#define LCNREV_GE(var, val) \
	(LCNCONF_GE(val) && (!LCNCONF_LT(val) || ((var) >= (val))))

#define LCNREV_GT(var, val) \
	(LCNCONF_GT(val) && (!LCNCONF_LE(val) || ((var) > (val))))

#define LCNREV_LT(var, val) \
	(LCNCONF_LT(val) && (!LCNCONF_GE(val) || ((var) < (val))))

#define LCNREV_LE(var, val) \
	(LCNCONF_LE(val) && (!LCNCONF_GT(val) || ((var) <= (val))))

#define D11REV_IS(var, val) \
	(D11CONF_HAS(val) && (D11CONF_IS(val) || ((var) == (val))))

#define D11REV_GE(var, val) \
	(D11CONF_GE(val) && (!D11CONF_LT(val) || ((var) >= (val))))

#define D11REV_GT(var, val) \
	(D11CONF_GT(val) && (!D11CONF_LE(val) || ((var) > (val))))

#define D11REV_LT(var, val) \
	(D11CONF_LT(val) && (!D11CONF_GE(val) || ((var) < (val))))

#define D11REV_LE(var, val) \
	(D11CONF_LE(val) && (!D11CONF_GT(val) || ((var) <= (val))))

#define PHYTYPE_IS(var, val)\
	(PHYCONF_HAS(val) && (PHYCONF_IS(val) || ((var) == (val))))

/* Finally, early-exit from switch case if anyone wants it... */

#define CASECHECK(config, val)	if (!(CONF_HAS(config, val))) break
#define CASEMSK(config, mask)	if (!(CONF_MSK(config, mask))) break

/* Set up PHYTYPE automatically: (depends on PHY_TYPE_X, from d11.h) */

#define _PHYCONF_N (1 << PHY_TYPE_N)
#define _PHYCONF_LCN (1 << PHY_TYPE_LCN)
#define _PHYCONF_SSLPN (1 << PHY_TYPE_SSN)

#define PHYTYPE (_PHYCONF_N | _PHYCONF_LCN | _PHYCONF_SSLPN)

/* Utility macro to identify 802.11n (HT) capable PHYs */
#define PHYTYPE_11N_CAP(phytype) \
	(PHYTYPE_IS(phytype, PHY_TYPE_N) ||	\
	 PHYTYPE_IS(phytype, PHY_TYPE_LCN) || \
	 PHYTYPE_IS(phytype, PHY_TYPE_SSN))

/* Last but not least: shorter wlc-specific var checks */
#define BRCMS_ISNPHY(band)		PHYTYPE_IS((band)->phytype, PHY_TYPE_N)
#define BRCMS_ISLCNPHY(band)	PHYTYPE_IS((band)->phytype, PHY_TYPE_LCN)
#define BRCMS_ISSSLPNPHY(band)	PHYTYPE_IS((band)->phytype, PHY_TYPE_SSN)

#define BRCMS_PHY_11N_CAP(band)	PHYTYPE_11N_CAP((band)->phytype)

/**********************************************************************
 * ------------- End of Core phy/rev configuration. ----------------- *
 * ********************************************************************
 */

/*************************************************
 * Defaults for tunables (e.g. sizing constants)
 *
 * For each new tunable, add a member to the end
 * of struct brcms_tunables in brcms_c_pub.h to enable
 * runtime checks of tunable values. (Directly
 * using the macros in code invalidates ROM code)
 *
 * ***********************************************
 */

/* Max # of entries in Tx FIFO based on 4kb page size */
#define NTXD		256
/* Max # of entries in Rx FIFO based on 4kb page size */
#define NRXD		256
/* try to keep this # rbufs posted to the chip */
#define	NRXBUFPOST	32
/* Maximum SCBs in cache for STA */
#define MAXSCB		32

/* max allowed number of mpdus in an ampdu (2 streams) */
#define AMPDU_NUM_MPDU		16

/* Count of packet callback structures. either of following
 * 1. Set to the number of SCBs since a STA
 * can queue up a rate callback for each IBSS STA it knows about, and an AP can
 * queue up an "are you there?" Null Data callback for each associated STA
 * 2. controlled by tunable config file
 */
#define MAXPKTCB	MAXSCB	/* Max number of packet callbacks */

/* NetBSD also needs to keep track of this */

/* Number of BSS handled in ucode bcn/prb */
#define BRCMS_MAX_UCODE_BSS	(16)
/* Number of BSS handled in sw bcn/prb */
#define BRCMS_MAX_UCODE_BSS4	(4)
/* max # BSS configs */
#define BRCMS_MAXBSSCFG		(1)
/* max # available networks */
#define MAXBSS		64
/* data msg txq hiwat mark */
#define BRCMS_DATAHIWAT		50
#define BRCMS_AMPDUDATAHIWAT 255

/* bounded rx loops */
#define RXBND		8 /* max # frames to process in brcms_c_recv() */
#define TXSBND		8 /* max # tx status to process in wlc_txstatus() */

#define BAND_5G(bt)	((bt) == BRCM_BAND_5G)
#define BAND_2G(bt)	((bt) == BRCM_BAND_2G)

#define BCMMSG(dev, fmt, args...)		\
do {						\
	if (brcm_msg_level & LOG_TRACE_VAL)	\
		wiphy_err(dev, "%s: " fmt, __func__, ##args);	\
} while (0)

#define WL_ERROR_ON()		(brcm_msg_level & LOG_ERROR_VAL)

/*
 * Register access macros.
 *
 * These macro's take a pointer to the address to read as one of their
 * arguments. The macro itself deduces the size of the IO transaction (u8, u16
 * or u32). Advantage of this approach in combination with using a struct to
 * define the registers in a register block, is that access size and access
 * location are defined in only one spot. This reduces the risk of the
 * programmer trying to use an unsupported transaction size on a register.
 *
 */

#define R_REG(r) \
	({ \
		__typeof(*(r)) __osl_v; \
		switch (sizeof(*(r))) { \
		case sizeof(u8): \
			__osl_v = readb((u8 *)(r)); \
			break; \
		case sizeof(u16): \
			__osl_v = readw((u16 *)(r)); \
			break; \
		case sizeof(u32): \
			__osl_v = readl((u32 *)(r)); \
			break; \
		} \
		__osl_v; \
	})

#define W_REG(r, v) do { \
		switch (sizeof(*(r))) { \
		case sizeof(u8):	\
			writeb((u8)(v), (u8 *)(r)); \
			break; \
		case sizeof(u16):	\
			writew((u16)(v), (u16 *)(r)); \
			break; \
		case sizeof(u32):	\
			writel((u32)(v), (u32 *)(r)); \
			break; \
		} \
	} while (0)

#ifdef CONFIG_BCM47XX
/*
 * bcm4716 (which includes 4717 & 4718), plus 4706 on PCIe can reorder
 * transactions. As a fix, a read after write is performed on certain places
 * in the code. Older chips and the newer 5357 family don't require this fix.
 */
#define W_REG_FLUSH(r, v)	({ W_REG((r), (v)); (void)R_REG(r); })
#else
#define W_REG_FLUSH(r, v)	W_REG((r), (v))
#endif				/* CONFIG_BCM47XX */

#define AND_REG(r, v)	W_REG((r), R_REG(r) & (v))
#define OR_REG(r, v)	W_REG((r), R_REG(r) | (v))

#define SET_REG(r, mask, val) \
		W_REG((r), ((R_REG(r) & ~(mask)) | (val)))

/* multi-bool data type: set of bools, mbool is true if any is set */

/* set one bool */
#define mboolset(mb, bit)		((mb) |= (bit))
/* clear one bool */
#define mboolclr(mb, bit)		((mb) &= ~(bit))
/* true if one bool is set */
#define mboolisset(mb, bit)		(((mb) & (bit)) != 0)
#define	mboolmaskset(mb, mask, val)	((mb) = (((mb) & ~(mask)) | (val)))

/* forward declarations */
struct wiphy;
struct ieee80211_sta;
struct ieee80211_tx_queue_params;
struct brcms_info;
struct brcms_c_info;
struct brcms_hardware;
struct brcms_c_if;
struct brcmu_iovar;
struct brcmu_strbuf;
struct brcms_txq_info;
struct brcms_band;
struct dma_pub;
struct si_pub;
struct tx_status;
struct d11rxhdr;
struct brcms_d11rxhdr;
struct txpwr_limits;

/* brcm_msg_level is a bit vector with defs in defs.h */
extern u32 brcm_msg_level;

#endif				/* _BRCM_TYPES_H_ */