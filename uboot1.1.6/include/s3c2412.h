
/************************************************
 * NAME	    : s3c2412.h
 *
 * Based on S3C2412X User's manual Rev 1.06
 ************************************************/
 
/*
 * (C) Copyright 2007
 * Byungjae Lee, Samsung Erectronics, bjlee@samsung.com.
 *
 * (C) Copyright 2003
 * David M?ller ELSOFT AG Switzerland. d.mueller@elsoft.ch
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */


#ifndef __S3C2412_H__
#define __S3C2412_H__

#ifndef CONFIG_S3C2412
#define CONFIG_S3C2412		1
#endif

#define S3C24X0_UART_CHANNELS	2
#define S3C24X0_SPI_CHANNELS	2

#include <asm/hardware.h>

#ifndef __ASSEMBLY__
typedef enum {
	S3C24X0_UART0,
	S3C24X0_UART1,
} S3C24X0_UARTS_NR;

#include <s3c24x0.h>
#endif

/* S3C2412 device base addresses */
#define ELFIN_DMA_BASE		0x40400000
#define ELFIN_USB_HOST_BASE	0x41000000
#define ELFIN_USB_DEVICE_BASE	0x44a00000
#define ELFIN_I2C_BASE		0x54000000
#define ELFIN_I2S_BASE		0x55000000
#define ELFIN_ADC_BASE		0x58000000
#define ELFIN_SPI_BASE		0x59000000

/*
 * Clock and power management
 */
#define ELFIN_CLOCK_POWER_BASE	0x4C000000

/* Clock & Power Controller */
#define LOCKTIME_OFFSET		0x00
#define MPLLCON_OFFSET		0x04
#define UPLLCON_OFFSET		0x08
#define CLKCON_OFFSET		0x0c
#define CLKDIVN_OFFSET		0x14
#define OSCSET_OFFSET		0x18
#define CLKSRC_OFFSET		0x1c
#define PWRMODECON_OFFSET	0x20
#define PWRCFG_OFFSET		0x24
#define ENDIAN_OFFSET		0x2c
#define SWRSTCON_OFFSET		0x30
#define RST_OFFSET		0x34
#define INFORM0_OFFSET		0x70
#define INFORM1_OFFSET		0x74
#define INFORM2_OFFSET		0x78
#define INFORM3_OFFSET		0x7c

#define LOCKTIME_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x00)
#define MPLLCON_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x04)
#define UPLLCON_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x08)
#define CLKCON_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x0c)
#define CLKDIVN_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x14)
#define OSCSET_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x18)
#define CLKSRC_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x1c)
#define PWRMODECON_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x20)
#define PWRCFG_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x24)
#define ENDIAN_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x2c)
#define SWRSTCON_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x30)
#define RST_REG			__REG(ELFIN_CLOCK_POWER_BASE+0x34)
#define INFORM0_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x70)
#define INFORM1_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x74)
#define INFORM2_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x78)
#define INFORM3_REG		__REG(ELFIN_CLOCK_POWER_BASE+0x7c)


/* for 0x20 CLKSRC */
#define I2S_CLK_SRC		0x00008000
#define CSI_CLK_SRC		0x00004000
#define CAM_CLK_SRC		0x00002000
#define FORTY8_CLK_SRC		0x00001000
#define I2S_CLK_DIV_SRC		0x00000800
#define UART_CLK_DIV_SRC	0x00000400
#define SelEPLL			0x00000040
#define SelUPLL			0x00000020
#define SelMPLL			0x00000010
#define SelExtDiv		0x00000008


/*
 * GPIO
 */

#define ELFIN_GPIO_BASE		0x56000000

#define GPACON_OFFSET		0x00
#define GPADAT_OFFSET		0x04
#define GPAPU_OFFSET		0x08
#define GPASLPCON_OFFSET	0x0C
#define GPBCON_OFFSET		0x10
#define GPBDAT_OFFSET		0x14
#define GPBPU_OFFSET		0x18
#define GPBSLPCON_OFFSET	0x1C
#define GPCCON_OFFSET		0x20
#define GPCDAT_OFFSET		0x24
#define GPCPU_OFFSET		0x28
#define GPCSLPCON_OFFSET	0x2C
#define GPDCON_OFFSET		0x30
#define GPDDAT_OFFSET		0x34
#define GPDPU_OFFSET		0x38
#define GPDSLPCON_OFFSET	0x3C
#define GPECON_OFFSET		0x40
#define GPEDAT_OFFSET		0x44
#define GPEPU_OFFSET		0x48
#define GPESLPCON_OFFSET	0x4C
#define GPFCON_OFFSET		0x50
#define GPFDAT_OFFSET		0x54
#define GPFPU_OFFSET		0x58
#define GPFSLPCON_OFFSET	0x5C
#define GPGCON_OFFSET		0x60
#define GPGDAT_OFFSET		0x64
#define GPGPU_OFFSET		0x68
#define GPGSLPCON_OFFSET	0x6C
#define GPHCON_OFFSET		0x70
#define GPHDAT_OFFSET		0x74
#define GPHPU_OFFSET		0x78
#define GPHSLPCON_OFFSET	0x7C
#define GPJCON_OFFSET		0x80
#define GPJDAT_OFFSET		0x84
#define GPJPU_OFFSET		0x88
#define GPJSLPCON_OFFSET	0x8C
#define MISCCR_OFFSET		0x90
#define DCLKCON_OFFSET		0x94
#define EINTCON0_OFFSET		0x98
#define EINTCON1_OFFSET		0x9C
#define EINTCON2_OFFSET		0xA0
#define EINTFLT0_OFFSET		0xA4
#define EINTFLT1_OFFSET		0xA8
#define EINTFLT2_OFFSET		0xAC
#define EINTFLT3_OFFSET		0xB0
#define EINTMASK_OFFSET		0xB4
#define EINTPEND_OFFSET		0xB8
#define GSTATUS0_OFFSET		0xBC
#define GSTATUS1_OFFSET		0xC0
#define GSTATUS2_OFFSET		0xC4
#define GSTATUS3_OFFSET		0xC8
#define GSTATUS4_OFFSET		0xCC
#define GSTATUS5_OFFSET		0xD0

#define GPACON_REG		__REG(0x56000000)
#define GPADAT_REG		__REG(0x56000004)
#define GPAPU_REG		__REG(0x56000008)
#define GPASLPCON_REG		__REG(0x5600000C)
#define GPBCON_REG		__REG(0x56000010)
#define GPBDAT_REG		__REG(0x56000014)
#define GPBPU_REG		__REG(0x56000018)
#define GPBSLPCON_REG		__REG(0x5600001C)
#define GPCCON_REG		__REG(0x56000020)
#define GPCDAT_REG		__REG(0x56000024)
#define GPCPU_REG		__REG(0x56000028)
#define GPCSLPCON_REG		__REG(0x5600002C)
#define GPDCON_REG		__REG(0x56000030)
#define GPDDAT_REG		__REG(0x56000034)
#define GPDPU_REG		__REG(0x56000038)
#define GPDSLPCON_REG		__REG(0x5600003C)
#define GPECON_REG		__REG(0x56000040)
#define GPEDAT_REG		__REG(0x56000044)
#define GPEPU_REG		__REG(0x56000048)
#define GPESLPCON_REG		__REG(0x5600004C)
#define GPFCON_REG		__REG(0x56000050)
#define GPFDAT_REG		__REG(0x56000054)
#define GPFPU_REG		__REG(0x56000058)
#define GPFSLPCON_REG		__REG(0x5600005C)
#define GPGCON_REG		__REG(0x56000060)
#define GPGDAT_REG		__REG(0x56000064)
#define GPGPU_REG		__REG(0x56000068)
#define GPGSLPCON_REG		__REG(0x5600006C)
#define GPHCON_REG		__REG(0x56000070)
#define GPHDAT_REG		__REG(0x56000074)
#define GPHPU_REG		__REG(0x56000078)
#define GPHSLPCON_REG		__REG(0x5600007C)
#define GPJCON_REG		__REG(0x56000080)
#define GPJDAT_REG		__REG(0x56000084)
#define GPJPU_REG		__REG(0x56000088)
#define GPJSLPCON_REG		__REG(0x5600008C)
#define MISCCR_REG		__REG(0x56000090)
#define DCLKCON_REG		__REG(0x56000094)
#define EINTCON0_REG		__REG(0x56000098)
#define EINTCON1_REG		__REG(0x5600009C)
#define EINTCON2_REG		__REG(0x560000A0)
#define EINTFLT0_REG		__REG(0x560000A4)
#define EINTFLT1_REG		__REG(0x560000A8)
#define EINTFLT2_REG		__REG(0x560000AC)
#define EINTFLT3_REG		__REG(0x560000B0)
#define EINTMASK_REG		__REG(0x560000B4)
#define EINTPEND_REG		__REG(0x560000B8)
#define GSTATUS0_REG		__REG(0x560000BC)
#define GSTATUS1_REG		__REG(0x560000C0)
#define GSTATUS2_REG		__REG(0x560000C4)
#define GSTATUS3_REG		__REG(0x560000C8)
#define GSTATUS4_REG		__REG(0x560000CC)
#define GSTATUS5_REG		__REG(0x560000D0)

/*
 * Memory controller
 */

#define ELFIN_SROM_BASE	0x40c20000

#define SROM_BW_REG		__REG(0x40C20000)
#define SROM_BC0_REG		__REG(0x40C20004)
#define SROM_BC1_REG		__REG(0x40C20008)
#define SROM_BC2_REG		__REG(0x40C2000C)

/*
 * SDRAM Controller
 */

#define ELFIN_MEMCTL_BASE	0x48000000
#define BANKCFG_OFFSET	0x00
#define BANKCON1_OFFSET	0x04
#define BANKCON2_OFFSET	0x08
#define BANKCON3_OFFSET	0x0c
#define REFRESH_OFFSET	0x10
#define TIMEOUT_OFFSET	0x14

#define INIT_NORMAL	0x0
#define INIT_PALL	0x1
#define INIT_MRS	0x2
#define INIT_EMRS	0x3
#define INIT_MASK	0x3


/*
 * Nand flash controller
 */

#define ELFIN_NAND_BASE	0x4e000000

#define NFCONF_OFFSET		0x00
#define NFCONT_OFFSET		0x04
#define NFCMMD_OFFSET		0x08
#define NFADDR_OFFSET		0x0c
#define NFDATA_OFFSET		0x10
#define NFMECCDATA0_OFFSET	0x14
#define NFMECCDATA1_OFFSET	0x18
#define NFSECCDATA0_OFFSET	0x1c
#define NFSBLK_OFFSET		0x20
#define NFEBLK_OFFSET		0x24
#define NFSTAT_OFFSET		0x28
#define NFESTAT0_OFFSET		0x2c
#define NFESTAT1_OFFSET		0x30
#define NFMECC0_OFFSET		0x34
#define NFMECC1_OFFSET		0x38
#define NFSECC_OFFSET		0x3c

#define NFCONF		(0x4e000000)
#define NFCONT		(0x4e000004)
#define NFCMMD		(0x4e000008)
#define NFADDR		(0x4e00000c)
#define NFDATA		(0x4e000010)
#define NFMECCDATA0	(0x4e000014)
#define NFMECCDATA1	(0x4e000018)
#define NFSECCDATA0	(0x4e00001c)
#define NFSBLK		(0x4e000020)
#define NFEBLK		(0x4e000024)
#define NFSTAT		(0x4e000028)
#define NFESTAT0	(0x4e00002c)
#define NFESTAT1	(0x4e000030)
#define NFMECC0		(0x4e000034)
#define NFMECC1		(0x4e000038)
#define NFSECC		(0x4e00003c)
#define NFMLCBITPT	(0x4e000040)

#define NFCONF_REG		__REG(0x4e000000)
#define NFCONT_REG		__REG(0x4e000004)
#define NFCMD_REG		__REG(0x4e000008)
#define NFADDR_REG		__REG(0x4e00000c)
#define NFDATA_REG		__REG(0x4e000010)
#define NFDATA8_REG		__REGb(0x4e000010)
#define NFMECCDATA0_REG		__REG(0x4e000014)
#define NFMECCDATA1_REG		__REG(0x4e000018)
#define NFSECCDATA0_REG		__REG(0x4e00001c)
#define NFSBLK_REG		__REG(0x4e000020)
#define NFEBLK_REG		__REG(0x4e000024)
#define NFSTAT_REG		__REG(0x4e000028)
#define NFESTAT0_REG		__REG(0x4e00002c)
#define NFESTAT1_REG		__REG(0x4e000030)
#define NFMECC0_REG		__REG(0x4e000034)
#define NFMECC1_REG		__REG(0x4e000038)
#define NFSECC_REG		__REG(0x4e00003c)
#define NFMLCBITPT_REG		__REG(0x4e000040)

#define NFCONF_ECC_MLC		(1<<24)
#define NFCONT_ECC_ENC		(1<<18)
#define NFCONT_WP		(1<<16)
#define NFCONT_MECCLOCK		(1<<7)
#define NFCONT_SECCLOCK		(1<<6)
#define NFCONT_INITMECC		(1<<5)
#define NFCONT_INITSECC		(1<<4)
#define NFCONT_INITECC		(NFCONT_INITMECC | NFCONT_INITSECC)
#define NFCONT_CS_ALT		(1<<2)
#define NFCONT_CS		(1<<1)
#define NFSTAT_ECCENCDONE	(1<<7)
#define NFSTAT_ECCDECDONE	(1<<6)
#define NFSTAT_RnB		(1<<0)
#define NFESTAT0_ECCBUSY	(1<<31)

/*
 * Interrupt
 */
#define ELFIN_INTERRUPT_BASE	0x4a000000

#define SRCPND_OFFSET		0x00
#define INTMOD_OFFSET		0x04
#define INTMSK_OFFSET		0x08
#define INTPND_OFFSET		0x10
#define INTOFFSET_OFFSET	0x14
#define SUBSRCPND_OFFSET	0x18
#define INTSUBMSK_OFFSET	0x1C

#define SRCPND_REG		__REG(0x4a000000)
#define INTMOD_REG		__REG(0x4a000004)
#define INTMSK_REG		__REG(0x4a000008)
#define INTPND_REG		__REG(0x4a000010)
#define INTOFFSET_REG		__REG(0x4a000014)
#define SUBSRCPND_REG		__REG(0x4a000018)
#define INTSUBMSK_REG		__REG(0x4a00001C)
#define SUBSRCPND2_REG		__REG(0x4a000030)
#define INTSUBMSK2_REG		__REG(0x4a000034)
#define PRIORITY_MODE_REG	__REG(0x4a000038)
#define PRIORITY_UPDATE_REG	__REG(0x4a00003c)

/*
 * LCD Controller
 */
#define ELFIN_LCD_BASE		0x4d000000
#define LCDINTMSK_OFFSET	0x2c


/*
 * Watchdog timer
 */
#define ELFIN_WATCHDOG_BASE	0x53000000

#define WTCON_REG		__REG(0x53000000)
#define WTDAT_REG		__REG(0x53000004)
#define WTCNT_REG		__REG(0x53000008)

/*
 * EBI(External Bus Interface)
 */
#define EBIPR_REG		__REG(0x48800000)
#define BANK_CFG_REG		__REG(0x48800004)

/*
 * SSMC
 */
#define SMBIDCYR0_REG	__REG(0x4F000000)
#define SMBIDCYR1_REG	__REG(0x4F000020)
#define SMBIDCYR2_REG	__REG(0x4F000040)
#define SMBIDCYR3_REG	__REG(0x4F000060)
#define SMBIDCYR4_REG	__REG(0x4F000080)
#define SMBIDCYR5_REG	__REG(0x4F0000A0)

#define SMBWSTRDR0_REG	__REG(0x4F000004)
#define SMBWSTRDR1_REG	__REG(0x4F000024)
#define SMBWSTRDR2_REG	__REG(0x4F000044)
#define SMBWSTRDR3_REG	__REG(0x4F000064)
#define SMBWSTRDR4_REG	__REG(0x4F000084)
#define SMBWSTRDR5_REG	__REG(0x4F0000A4)

#define SMBWSTWRR0_REG	__REG(0x4F000008)
#define SMBWSTWRR1_REG	__REG(0x4F000028)
#define SMBWSTWRR2_REG	__REG(0x4F000048)
#define SMBWSTWRR3_REG	__REG(0x4F000068)
#define SMBWSTWRR4_REG	__REG(0x4F000088)
#define SMBWSTWRR5_REG	__REG(0x4F0000A8)

#define SMBWSTOENR0_REG __REG(0x4F00000C)
#define SMBWSTOENR1_REG __REG(0x4F00002C)
#define SMBWSTOENR2_REG __REG(0x4F00004C)
#define SMBWSTOENR3_REG __REG(0x4F00006C)
#define SMBWSTOENR4_REG __REG(0x4F00008C)
#define SMBWSTOENR5_REG __REG(0x4F0000AC)

#define SMBWSTWENR0_REG	__REG(0x4F000010)
#define SMBWSTWENR1_REG	__REG(0x4F000030)
#define SMBWSTWENR2_REG	__REG(0x4F000050)
#define SMBWSTWENR3_REG __REG(0x4F000070)
#define SMBWSTWENR4_REG __REG(0x4F000090)
#define SMBWSTWENR5_REG __REG(0x4F0000B0)

#define SMBCR0_REG	__REG(0x4F000014)
#define SMBCR1_REG	__REG(0x4F000034)
#define SMBCR2_REG	__REG(0x4F000054)
#define SMBCR3_REG	__REG(0x4F000074)
#define SMBCR4_REG	__REG(0x4F000094)
#define SMBCR5_REG	__REG(0x4F0000B4)

#define SMBSR0_REG	__REG(0x4F000018)
#define SMBSR1_REG	__REG(0x4F000038)
#define SMBSR2_REG	__REG(0x4F000058)
#define SMBSR3_REG	__REG(0x4F000078)
#define SMBSR4_REG	__REG(0x4F000098)
#define SMBSR5_REG	__REG(0x4F0000B8)

#define SMBWSTBDR0_REG	__REG(0x4F00001C)
#define SMBWSTBDR1_REG	__REG(0x4F00003C)
#define SMBWSTBDR2_REG	__REG(0x4F00005C)
#define SMBWSTBDR3_REG	__REG(0x4F00007C)
#define SMBWSTBDR4_REG	__REG(0x4F00009C)
#define SMBWSTBDR5_REG	__REG(0x4F0000BC)

#define SSMCSR_REG	__REG(0x4F000200)
#define SSMCCR_REG	__REG(0x4F000204)

/*
 * UART
 */
#define ELFIN_UART_BASE	0x50000000

#define ULCON0_REG		__REG(0x50000000)
#define UCON0_REG		__REG(0x50000004)
#define UFCON0_REG		__REG(0x50000008)
#define UMCON0_REG		__REG(0x5000000C)
#define UTRSTAT0_REG		__REG(0x50000010)
#define UERSTAT0_REG		__REG(0x50000014)
#define UFSTAT0_REG		__REG(0x50000018)
#define UMSTAT0_REG		__REG(0x5000001C)
#define UTXH0_REG		__REG(0x50000020)
#define URXH0_REG		__REG(0x50000024)
#define UBRDIV0_REG		__REG(0x50000028)

#define ULCON1_REG		__REG(0x50004000)
#define UCON1_REG		__REG(0x50004004)
#define UFCON1_REG		__REG(0x50004008)
#define UMCON1_REG		__REG(0x5000400C)
#define UTRSTAT1_REG		__REG(0x50004010)
#define UERSTAT1_REG		__REG(0x50004014)
#define UFSTAT1_REG		__REG(0x50004018)
#define UMSTAT1_REG		__REG(0x5000401C)
#define UTXH1_REG		__REG(0x50004020)
#define URXH1_REG		__REG(0x50004024)
#define UBRDIV1_REG		__REG(0x50004028)

#define ULCON2_REG		__REG(0x50008000)
#define UCON2_REG		__REG(0x50008004)
#define UFCON2_REG		__REG(0x50008008)
#define UMCON2_REG		__REG(0x5000800C)
#define UTRSTAT2_REG		__REG(0x50008010)
#define UERSTAT2_REG		__REG(0x50008014)
#define UFSTAT2_REG		__REG(0x50008018)
#define UMSTAT2_REG		__REG(0x5000801C)
#define UTXH2_REG		__REG(0x50008020)
#define URXH2_REG		__REG(0x50008024)
#define UBRDIV2_REG		__REG(0x50008028)

#define ULCON_OFFSET		0x00
#define UCON_OFFSET		0x04
#define UFCON_OFFSET		0x08
#define UMCON_OFFSET		0x0C
#define UTRSTAT_OFFSET		0x10
#define UERSTAT_OFFSET		0x14
#define UFSTAT_OFFSET		0x18
#define UMSTAT_OFFSET		0x1C
#define UTXH_OFFSET		0x20
#define URXH_OFFSET		0x24
#define UBRDIV_OFFSET		0x28


#define UTRSTAT_TX_EMPTY	(1 << 2)
#define UTRSTAT_RX_READY	(1 << 0)
#define UART_ERR_MASK		0xF

/*
 * PWM timer
 */
#define ELFIN_TIMER_BASE	0x51000000

#define TCFG0_REG		__REG(0x51000000)
#define TCFG1_REG		__REG(0x51000004)
#define TCON_REG		__REG(0x51000008)
#define TCNTB0_REG		__REG(0x5100000C)
#define TCMPB0_REG		__REG(0x51000010)
#define TCNTO0_REG		__REG(0x51000014)
#define TCNTB1_REG		__REG(0x51000018)
#define TCMPB1_REG		__REG(0x5100001C)
#define TCNTO1_REG		__REG(0x51000020)
#define TCNTB2_REG		__REG(0x51000024)
#define TCMPB2_REG		__REG(0x51000028)
#define TCNTO2_REG		__REG(0x5100002C)
#define TCNTB3_REG		__REG(0x51000030)
#define TCMPB3_REG		__REG(0x51000034)
#define TCNTO3_REG		__REG(0x51000038)
#define TCNTB4_REG		__REG(0x5100003C)
#define TCNTO4_REG		__REG(0x51000040)

/* Fields */
#define fTCFG0_DZONE		Fld(8,16)       /* the dead zone length (= timer 0) */
#define fTCFG0_PRE1		Fld(8,8)        /* prescaler value for time 2,3,4 */
#define fTCFG0_PRE0		Fld(8,0)        /* prescaler value for time 0,1 */
#define fTCFG1_MUX4		Fld(4,16)
/* bits */
#define TCFG0_DZONE(x)		FInsrt((x), fTCFG0_DZONE)
#define TCFG0_PRE1(x)		FInsrt((x), fTCFG0_PRE1)
#define TCFG0_PRE0(x)		FInsrt((x), fTCFG0_PRE0)
#define TCON_4_AUTO		(1 << 22)       /* auto reload on/off for Timer 4 */
#define TCON_4_UPDATE		(1 << 21)       /* manual Update TCNTB4 */
#define TCON_4_ONOFF		(1 << 20)       /* 0: Stop, 1: start Timer 4 */
#define COUNT_4_ON		(TCON_4_ONOFF*1)
#define COUNT_4_OFF		(TCON_4_ONOFF*0)
#define TCON_3_AUTO		(1 << 19)       /* auto reload on/off for Timer 3 */
#define TIMER3_ATLOAD_ON	(TCON_3_AUTO*1)
#define TIMER3_ATLAOD_OFF	FClrBit(TCON, TCON_3_AUTO)
#define TCON_3_INVERT		(1 << 18)       /* 1: Inverter on for TOUT3 */
#define TIMER3_IVT_ON		(TCON_3_INVERT*1)
#define TIMER3_IVT_OFF		(FClrBit(TCON, TCON_3_INVERT))
#define TCON_3_MAN		(1 << 17)       /* manual Update TCNTB3,TCMPB3 */
#define TIMER3_MANUP		(TCON_3_MAN*1)
#define TIMER3_NOP		(FClrBit(TCON, TCON_3_MAN))
#define TCON_3_ONOFF		(1 << 16)       /* 0: Stop, 1: start Timer 3 */
#define TIMER3_ON		(TCON_3_ONOFF*1)
#define TIMER3_OFF		(FClrBit(TCON, TCON_3_ONOFF))
/* macros */
#define GET_PRESCALE_TIMER4(x)	FExtr((x), fTCFG0_PRE1)
#define GET_DIVIDER_TIMER4(x)	FExtr((x), fTCFG1_MUX4)

/*
 * RTC Controller
 */
#define ELFIN_RTC_BASE	0x57000000
#define RTCCON_REG		__REG(0x57000040)
#define TICNT_REG		__REG(0x57000044)
#define RTCALM_REG		__REG(0x57000050)
#define ALMSEC_REG		__REG(0x57000054)
#define ALMMIN_REG		__REG(0x57000058)
#define ALMHOUR_REG		__REG(0x5700005c)
#define ALMDATE_REG		__REG(0x57000060)
#define ALMMON_REG		__REG(0x57000064)
#define ALMYEAR_REG		__REG(0x57000068)
#define BCDSEC_REG		__REG(0x57000070)
#define BCDMIN_REG		__REG(0x57000074)
#define BCDHOUR_REG		__REG(0x57000078)
#define BCDDATE_REG		__REG(0x5700007c)
#define BCDDAY_REG		__REG(0x57000080)
#define BCDMON_REG		__REG(0x57000084)
#define BCDYEAR_REG		__REG(0x57000088)

/*
 * SD/MMC Interface (chapter 27)
 */
#define ELFIN_SDI_BASE		0x5a000000

#define SDICON			(ELFIN_SDI_BASE+0x00)	/* SDI Control */
#define SDIPRE			(ELFIN_SDI_BASE+0x04)	/* SDI baud rate prescaler */
#define SDICARG			(ELFIN_SDI_BASE+0x08)	/* SDI command argument */
#define SDICCON			(ELFIN_SDI_BASE+0x0c)	/* SDI command control */
#define SDICSTA			(ELFIN_SDI_BASE+0x10)	/* SDI command status */
#define SDIRSP0			(ELFIN_SDI_BASE+0x14)	/* SDI response 0 */
#define SDIRSP1			(ELFIN_SDI_BASE+0x18)	/* SDI response 1 */
#define SDIRSP2			(ELFIN_SDI_BASE+0x1c)	/* SDI response 2 */
#define SDIRSP3			(ELFIN_SDI_BASE+0x20)	/* SDI response 3 */
#define SDIDTIMER		(ELFIN_SDI_BASE+0x24)	/* SDI data/busy timer */
#define SDIBSIZE		(ELFIN_SDI_BASE+0x28)	/* SDI block size */
#define SDIDCON			(ELFIN_SDI_BASE+0x2c)	/* SDI data control */
#define SDIDCNT			(ELFIN_SDI_BASE+0x30)	/* SDI data remain counter */
#define SDIDSTA			(ELFIN_SDI_BASE+0x34)	/* SDI data status */
#define SDIFSTA			(ELFIN_SDI_BASE+0x38)	/* SDI FIFO status */
#define SDIIMSK			(ELFIN_SDI_BASE+0x3c)	/* SDI Interrupt Mask */
#define SDIDAT			(ELFIN_SDI_BASE+0x40)	/* SDI Data register */

#define SDICON_REG		__REG(0x5a000000)	/* SDI Control */
#define SDIPRE_REG		__REG(0x5a000004)	/* SDI baud rate prescaler */
#define SDICARG_REG		__REG(0x5a000008)	/* SDI command argument */
#define SDICCON_REG		__REG(0x5a00000c)	/* SDI command control */
#define SDICSTA_REG		__REG(0x5a000010)	/* SDI command status */
#define SDIRSP0_REG		__REG(0x5a000014)	/* SDI response 0 */
#define SDIRSP1_REG		__REG(0x5a000018)	/* SDI response 1 */
#define SDIRSP2_REG		__REG(0x5a00001c)	/* SDI response 2 */
#define SDIRSP3_REG		__REG(0x5a000020)	/* SDI response 3 */
#define SDIDTIMER_REG		__REG(0x5a000024)	/* SDI data/busy timer */
#define SDIBSIZE_REG		__REG(0x5a000028)	/* SDI block size */
#define SDIDCON_REG		__REG(0x5a00002c)	/* SDI data control */
#define SDIDCNT_REG		__REG(0x5a000030)	/* SDI data remain counter */
#define SDIDSTA_REG		__REG(0x5a000034)	/* SDI data status */
#define SDIFSTA_REG		__REG(0x5a000038)	/* SDI FIFO status */
#define SDIIMSK_REG		__REG(0x5a00003c)	/* SDI Interrupt Mask */
#define SDIDAT_REG		__REG(0x5a000040)	/* SDI Data register */

/*
 * USB Device - Little Endian :
 * (B) : byte(8 bit) access
 * (W) : word(32 bit) access
 */
#define USB_DEVICE_PHYS_ADR	0x52000000

#define bUD(Nb)		__REG(USB_DEVICE_PHYS_ADR + (Nb))
#define UD_FUNC		bUD(0x140) // Function address  (B)
#define UD_PWR		bUD(0x144) // Power management (B)
#define UD_INT		bUD(0x148) // Endpoint interrupt pending/clear (B)
#define UD_USBINT	bUD(0x158) // USB interrupt pending/clear (B)
#define UD_INTE		bUD(0x15c) // Endpoint interrupt enable (B)
#define UD_USBINTE	bUD(0x16c) // USB interrupt enable (B)
#define UD_FRAMEL	bUD(0x170) // Frame number low-byte (B)
#define UD_FRAMEH	bUD(0x174) // Frame number high-byte (B)
#define UD_INDEX	bUD(0x178) // Index (B)
#define UD_FIFO0	bUD(0x1c0) // Endpoint 0 FIFO (B)
#define UD_FIFO1	bUD(0x1c4) // Endpoint 1 FIFO (B)
#define UD_FIFO2	bUD(0x1c8) // Endpoint 2 FIFO (B)
#define UD_FIFO3	bUD(0x1cc) // Endpoint 3 FIFO (B)
#define UD_FIFO4	bUD(0x1d0) // Endpoint 4 FIFO (B)
#define UD_DMACON1	bUD(0x200) // Endpoint 1 DMA control (B)
#define UD_DMAUC1	bUD(0x204) // Endpoint 1 DMA unit counter (B)
#define UD_DMAFC1	bUD(0x208) // Endpoint 1 DMA FIFO counter
#define UD_DMATCL1	bUD(0x20c) // Endpoint 1 DMA Transfer counter low-byte
#define UD_DMATCM1	bUD(0x210) // Endpoint 1 DMA Transfer counter middle-byte
#define UD_DMATCH1	bUD(0x214) // Endpoint 1 DMA Transfer counter high-byte
#define UD_DMACON2	bUD(0x218) // Endpoint 2 DMA control (B)
#define UD_DMAUC2	bUD(0x21c) // Endpoint 2 DMA unit counter (B)
#define UD_DMAFC2	bUD(0x220) // Endpoint 2 DMA FIFO counter
#define UD_DMATCL2	bUD(0x224) // Endpoint 2 DMA Transfer counter low-byte
#define UD_DMATCM2	bUD(0x228) // Endpoint 2 DMA Transfer counter middle-byte
#define UD_DMATCH2	bUD(0x22c) // Endpoint 2 DMA Transfer counter high-byte
#define UD_DMACON3	bUD(0x240) // Endpoint 3 DMA control (B)
#define UD_DMAUC3	bUD(0x244) // Endpoint 3 DMA unit counter (B)
#define UD_DMAFC3	bUD(0x248) // Endpoint 3 DMA FIFO counter
#define UD_DMATCL3	bUD(0x24c) // Endpoint 3 DMA Transfer counter low-byte
#define UD_DMATCM3	bUD(0x250) // Endpoint 3 DMA Transfer counter middle-byte
#define UD_DMATCH3	bUD(0x254) // Endpoint 3 DMA Transfer counter high-byte
#define UD_DMACON4	bUD(0x258) // Endpoint 4 DMA control (B)
#define UD_DMAUC4	bUD(0x25c) // Endpoint 4 DMA unit counter (B)
#define UD_DMAFC4	bUD(0x260) // Endpoint 4 DMA FIFO counter
#define UD_DMATCL4	bUD(0x264) // Endpoint 4 DMA Transfer counter low-byte
#define UD_DMATCM4	bUD(0x268) // Endpoint 4 DMA Transfer counter middle-byte
#define UD_DMATCH4	bUD(0x26c) // Endpoint 4 DMA Transfer counter high-byte
#define UD_MAXP		bUD(0x180) // Endpoint MAX Packet
#define UD_ICSR1	bUD(0x184) // EP In control status register 1 (B)
#define UD_ICSR2	bUD(0x188) // EP In control status register 2 (B)
#define UD_OCSR1	bUD(0x190) // EP Out control status register 1 (B)
#define UD_OCSR2	bUD(0x194) // EP Out control status register 2 (B)
#define UD_OFCNTL	bUD(0x198) // EP Out Write counter low-byte (B)
#define UD_OFCNTH	bUD(0x19c) // EP Out Write counter high-byte (B)

#define UD_FUNC_UD	(1 << 7)
#define fUD_FUNC_ADDR	Fld(7,0)	/* USB Device Addr. assigned by host */
#define UD_FUNC_ADDR	FMsk(fUD_FUNC_ADDR)

#define UD_PWR_ISOUP	(1<<7) // R/W
#define UD_PWR_RESET	(1<<3) // R
#define UD_PWR_RESUME	(1<<2) // R/W
#define UD_PWR_SUSPND	(1<<1) // R
#define UD_PWR_ENSUSPND	(1<<0) // R/W

#define UD_PWR_DEFAULT	0x00

#define UD_INT_EP4	(1<<4)	// R/W (clear only)
#define UD_INT_EP3	(1<<3)	// R/W (clear only)
#define UD_INT_EP2	(1<<2)	// R/W (clear only)
#define UD_INT_EP1	(1<<1)	// R/W (clear only)
#define UD_INT_EP0	(1<<0)	// R/W (clear only)

#define UD_USBINT_RESET	(1<<2) // R/W (clear only)
#define UD_USBINT_RESUM	(1<<1) // R/W (clear only)
#define UD_USBINT_SUSPND (1<<0) // R/W (clear only)

#define UD_INTE_EP4	(1<<4) // R/W
#define UD_INTE_EP3	(1<<3) // R/W
#define UD_INTE_EP2	(1<<2) // R/W
#define UD_INTE_EP1	(1<<1) // R/W
#define UD_INTE_EP0	(1<<0) // R/W

#define UD_USBINTE_RESET	(1<<2) // R/W
#define UD_USBINTE_SUSPND	(1<<0) // R/W

#define fUD_FRAMEL_NUM	Fld(8,0) // R
#define UD_FRAMEL_NUM	FMsk(fUD_FRAMEL_NUM)

#define fUD_FRAMEH_NUM	Fld(8,0) // R
#define UD_FRAMEH_NUM	FMsk(fUD_FRAMEH_NUM)

#define UD_INDEX_EP0		(0x00)
#define UD_INDEX_EP1		(0x01) // ??
#define UD_INDEX_EP2		(0x02) // ??
#define UD_INDEX_EP3		(0x03) // ??
#define UD_INDEX_EP4		(0x04) // ??

#define UD_ICSR1_CLRDT		(1<<6)   // R/W
#define UD_ICSR1_SENTSTL	(1<<5)  // R/W (clear only)
#define UD_ICSR1_SENDSTL	(1<<4)  // R/W
#define UD_ICSR1_FFLUSH		(1<<3)  // W	(set only)
#define UD_ICSR1_UNDRUN		(1<<2)  // R/W (clear only)
#define UD_ICSR1_PKTRDY		(1<<0)  // R/W (set only)

#define UD_ICSR2_AUTOSET	(1<<7) // R/W
#define UD_ICSR2_ISO		(1<<6)	// R/W
#define UD_ICSR2_MODEIN		(1<<5) // R/W
#define UD_ICSR2_DMAIEN		(1<<4) // R/W

#define UD_OCSR1_CLRDT		(1<<7) // R/W
#define UD_OCSR1_SENTSTL	(1<<6)	// R/W (clear only)
#define UD_OCSR1_SENDSTL	(1<<5)	// R/W
#define UD_OCSR1_FFLUSH		(1<<4) // R/W
#define UD_OCSR1_DERROR		(1<<3) // R
#define UD_OCSR1_OVRRUN		(1<<2) // R/W (clear only)
#define UD_OCSR1_PKTRDY		(1<<0) // R/W (clear only)

#define UD_OCSR2_AUTOCLR	(1<<7) // R/W
#define UD_OCSR2_ISO		(1<<6) // R/W
#define UD_OCSR2_DMAIEN		(1<<5) // R/W

#define fUD_FIFO_DATA	Fld(8,0) // R/W
#define UD_FIFO0_DATA	FMsk(fUD_FIFO_DATA)
#define UD_FIFO1_DATA	FMsk(fUD_FIFO_DATA)
#define UD_FIFO2_DATA	FMsk(fUD_FIFO_DATA)
#define UD_FIFO3_DATA	FMsk(fUD_FIFO_DATA)
#define UD_FIFO4_DATA	FMsk(fUD_FIFO_DATA)

#define UD_MAXP_8	(1<<0)
#define UD_MAXP_16	(1<<1)
#define UD_MAXP_32	(1<<2)
#define UD_MAXP_64	(1<<3)

#define fUD_OFCNT_DATA	Fld(8,0)
#define UD_OFCNTL_DATA	FMsk(fUD_OFCNT_DATA) //R
#define UD_OFCNTH_DATA	FMsk(fUD_OFCNT_DATA) //R

#define UD_DMACONx_INRUNOB	(1<<7) // R
#define fUD_DMACON_STATE	Fld(3,4) // R
#define UD_DMACONx_STATE	FMsk(fUD_DMACON_STATE) // R/W
#define UD_DMACONx_DEMEN	(1<<3) // R/W
#define UD_DMACONx_ORUN		(1<<2) // R/W
#define UD_DMACONx_IRUN		(1<<1) // R/W
#define UD_DMACONx_DMAMODE	(1<<0) // R/W

#define fUD_DMAUC_DATA	Fld(8,0)
#define UD_DMAUCx_DATA	FMsk(fUD_DMAUC_DATA)

#define fUD_DMAFC_DATA	Fld(8,0)
#define UD_DMAFCx_DATA	FMsk(fUD_DMAFC_DATA)

#define fUD_DMATC_DATA	Fld(8,0)
#define UD_DMATCL_DATA	FMsk(fUD_DMATC_DATA)
#define UD_DMATCM_DATA	FMsk(fUD_DMATC_DATA)
#define UD_DMATCH_DATA	FMsk(fUD_DMATC_DATA)

#define EP0_CSR_OPKRDY	(1<<0)
#define EP0_CSR_IPKRDY	(1<<1)
#define EP0_CSR_SENTSTL	(1<<2)
#define EP0_CSR_DE	(1<<3)
#define EP0_CSR_SE	(1<<4)
#define EP0_CSR_SENDSTL	(1<<5)
#define EP0_CSR_SOPKTRDY (1<<6)
#define EP0_CSR_SSE	(1<<7)

#define CLKCON_USBD			(1<< 16)
#define BIT25                           0x02000000
#define BIT_USBD			BIT25

#define S3C_USBD_DETECT_IRQ()	(SRCPND_REG & BIT_USBD)
#define S3C_USBD_CLEAR_IRQ()	do { \
					SRCPND_REG = BIT_USBD; \
				} while (0)
				
/* include common stuff */
#ifndef __ASSEMBLY__
static inline S3C24X0_MEMCTL * S3C24X0_GetBase_MEMCTL(void)
{
	return (S3C24X0_MEMCTL *)(ELFIN_MEMCTL_BASE);
}
static inline S3C24X0_USB_HOST * S3C24X0_GetBase_USB_HOST(void)
{
	return (S3C24X0_USB_HOST *)ELFIN_USB_HOST_BASE;
}
static inline S3C24X0_INTERRUPT * S3C24X0_GetBase_INTERRUPT(void)
{
	return (S3C24X0_INTERRUPT *)ELFIN_INTERRUPT_BASE;
}
static inline S3C24X0_DMAS * S3C24X0_GetBase_DMAS(void)
{
	return (S3C24X0_DMAS *)ELFIN_DMA_BASE;
}
static inline S3C24X0_CLOCK_POWER * S3C24X0_GetBase_CLOCK_POWER(void)
{
	return (S3C24X0_CLOCK_POWER *)ELFIN_CLOCK_POWER_BASE;
}
static inline S3C24X0_LCD * S3C24X0_GetBase_LCD(void)
{
	return (S3C24X0_LCD *)ELFIN_LCD_BASE;
}
static inline S3C2410_NAND * S3C2410_GetBase_NAND(void)
{
	return (S3C2410_NAND *)ELFIN_NAND_BASE;
}
static inline S3C24X0_UART * S3C24X0_GetBase_UART(S3C24X0_UARTS_NR nr)
{
	return (S3C24X0_UART *)(ELFIN_UART_BASE + (nr * 0x4000));
}
static inline S3C24X0_TIMERS * S3C24X0_GetBase_TIMERS(void)
{
	return (S3C24X0_TIMERS *)ELFIN_TIMER_BASE;
}
static inline S3C24X0_USB_DEVICE * S3C24X0_GetBase_USB_DEVICE(void)
{
	return (S3C24X0_USB_DEVICE *)ELFIN_USB_DEVICE_BASE;
}
static inline S3C24X0_WATCHDOG * S3C24X0_GetBase_WATCHDOG(void)
{
	return (S3C24X0_WATCHDOG *)ELFIN_WATCHDOG_BASE;
}
static inline S3C24X0_I2C * S3C24X0_GetBase_I2C(void)
{
	return (S3C24X0_I2C *)ELFIN_I2C_BASE;
}
static inline S3C24X0_I2S * S3C24X0_GetBase_I2S(void)
{
	return (S3C24X0_I2S *)ELFIN_I2S_BASE;
}
static inline S3C24X0_GPIO * S3C24X0_GetBase_GPIO(void)
{
	return (S3C24X0_GPIO *)ELFIN_GPIO_BASE;
}
static inline S3C24X0_RTC * S3C24X0_GetBase_RTC(void)
{
	return (S3C24X0_RTC *)ELFIN_RTC_BASE;
}
static inline S3C2410_ADC * S3C2410_GetBase_ADC(void)
{
	return (S3C2410_ADC *)ELFIN_ADC_BASE;
}
static inline S3C24X0_SPI * S3C24X0_GetBase_SPI(void)
{
	return (S3C24X0_SPI *)ELFIN_SPI_BASE;
}
static inline S3C2410_SDI * S3C2410_GetBase_SDI(void)
{
	return (S3C2410_SDI *)ELFIN_SDI_BASE;
}
#else /* #ifndef __ASSEMBLY__ */

/* watchdog */
#define WTCON_OFFSET		0x00

/* LCD controller */
#define LCDBGCON_OFFSET		0x5c

#endif /* #ifndef __ASSEMBLY__ */

/* PENDING BIT */
#define BIT_EINT0		(0x1)
#define BIT_EINT1		(0x1<<1)
#define BIT_EINT2		(0x1<<2)
#define BIT_EINT3		(0x1<<3)
#define BIT_EINT4_7		(0x1<<4)
#define BIT_EINT8_23		(0x1<<5)
#define BIT_BAT_FLT		(0x1<<7)
#define BIT_TICK		(0x1<<8)
#define BIT_WDT			(0x1<<9)
#define BIT_TIMER0		(0x1<<10)
#define BIT_TIMER1		(0x1<<11)
#define BIT_TIMER2		(0x1<<12)
#define BIT_TIMER3		(0x1<<13)
#define BIT_TIMER4		(0x1<<14)
#define BIT_UART2		(0x1<<15)
#define BIT_LCD			(0x1<<16)
#define BIT_DMA0		(0x1<<17)
#define BIT_DMA1		(0x1<<18)
#define BIT_DMA2		(0x1<<19)
#define BIT_DMA3		(0x1<<20)
#define BIT_SDI			(0x1<<21)
#define BIT_SPI0		(0x1<<22)
#define BIT_UART1		(0x1<<23)
#define BIT_USBH		(0x1<<26)
#define BIT_IIC			(0x1<<27)
#define BIT_UART0		(0x1<<28)
#define BIT_SPI1		(0x1<<29)
#define BIT_RTC			(0x1<<30)
#define BIT_ADC			(0x1<<31)
#define BIT_ALLMSK		(0xFFFFFFFF)

#define ClearPending(bit) {\
		 rSRCPND = bit;\
		 rINTPND = bit;\
		 rINTPND;\
		 }
/* Wait until rINTPND is changed for the case that the ISR is very short. */

#endif /*__S3C2412_H__*/
