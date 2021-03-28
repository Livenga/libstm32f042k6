/** PM0091
 * 13.12.11 ADC register map p.267/1004
 */

#ifndef _ADC_H
#define _ADC_H

#include <stdint.h>
#include "io.h"

#define ADC_ADDR (volatile uint32_t)0x40012400
#define ADC ((struct adc_t *)ADC_ADDR)

struct adc_t {
  __IO uint32_t ISR;
  __IO uint32_t IER;
  __IO uint32_t CR;
  __IO uint32_t CFGR1;
  __IO uint32_t CFGR2;
  __IO uint32_t SMPR;

  __RO uint32_t _reserved0[2];

  __IO uint32_t TR;

  __RO uint32_t _reserved1;

  __IO uint32_t CHSELR;

  __RO uint32_t _reserved2[5];

  __RO uint32_t DR;

  __RO uint32_t _reserved3[177];

  __IO uint32_t CCR;
};


/** ADC interrupt and status regsiter(ADC_ISR)
 * offset: 0x0000
 * reset value: 0x0000 0000
 */
#define ADC_ISR_AWD   (0x00000080)
#define ADC_ISR_OVR   (0x00000010)
#define ADC_ISR_EOSEQ (0x00000008)
#define ADC_ISR_EOC   (0x00000004)
#define ADC_ISR_EOSMP (0x00000002)
#define ADC_ISR_ADRDY (0x00000001)


/** ADC interrupt enable register(ADC_IER)
 * offset: 0x0004
 * reset value: 0x0000 0000
 */
#define ADC_IER_AWDIE   (0x00000080)
#define ADC_IER_OVRIE   (0x00000010)
#define ADC_IER_EOSEQIE (0x00000008)
#define ADC_IER_EOCIE   (0x00000004)
#define ADC_IER_EOSMPIE (0x00000002)
#define ADC_IER_ADRYIE  (0x00000001)


/** ADC control register(ADC_CR)
 * offset: 0x0008
 * reset value: 0x0000 0000
 */
#define ADC_CR_ADCAL   (0x80000000)
#define ADC_CR_ADSTP   (0x00000010)
#define ADC_CR_ADSTART (0x00000004)
#define ADC_CR_ADDIS   (0x00000002)
#define ADC_CR_ADEN    (0x00000001)


/** ADC configuration register 1(ADC_CFGR1)
 * offset: 0x000c
 * reset value: 0x0000 0000
 */
#define ADC_CFGR1_AWDCH   (0x7c000000)
#define ADC_CFGR1_AWDEN   (0x00800000)
#define ADC_CFGR1_AWDSGL  (0x00400000)
#define ADC_CFGR1_DISCEN  (0x00010000)
#define ADC_CFGR1_AUTOFF  (0x00008000)
#define ADC_CFGR1_WAIT    (0x00004000)
#define ADC_CFGR1_CONT    (0x00002000)
#define ADC_CFGR1_OVRMOD  (0x00001000)
#define ADC_CFGR1_EXTEN   (0x00000c00)
#define ADC_CFGR1_EXTSEL  (0x000001c0)
#define ADC_CFGR1_ALIGN   (0x00000020)
#define ADC_CFGR1_RES     (0x00000018)
#define ADC_CFGR1_SCANDIR (0x00000004)
#define ADC_CFGR1_DMACF   (0x00000002)
#define ADC_CFGR1_DMAEN   (0x00000001)


/** ADC configuration register 2(ADC_CFGR2)
 * offset: 0x0010
 * reset value: 0x0000 0000
 */
#define ADC_CFGR2_CKMODE (0xc0000000)


/** ADC sampling time register(ADC_SMPC)
 * offset: 0x0014
 * reset value: 0x0000 0000
 */
#define ADC_SMPR_SMP (0x00000007)


/** ADC watchdoc threshold register(ADC_TR)
 * offset: 0x0020
 * reset value: 0x0fff 0000
 */
#define ADC_TR_HT (0x0fff0000)
#define ADC_TR_LT (0x00000fff)


/** AC channel selection register(ADC_CHSELR)
 * offset: 0x0028
 * reset value: 0x0000 0000
 */
#define ADC_CHSELR_CHSEL18 (0x00040000)
#define ADC_CHSELR_CHSEL17 (0x00020000)
#define ADC_CHSELR_CHSEL16 (0x00010000)
#define ADC_CHSELR_CHSEL15 (0x00008000)
#define ADC_CHSELR_CHSEL14 (0x00004000)
#define ADC_CHSELR_CHSEL13 (0x00002000)
#define ADC_CHSELR_CHSEL12 (0x00001000)
#define ADC_CHSELR_CHSEL11 (0x00000800)
#define ADC_CHSELR_CHSEL10 (0x00000400)
#define ADC_CHSELR_CHSEL9  (0x00000200)
#define ADC_CHSELR_CHSEL8  (0x00000100)
#define ADC_CHSELR_CHSEL7  (0x00000080)
#define ADC_CHSELR_CHSEL6  (0x00000040)
#define ADC_CHSELR_CHSEL5  (0x00000020)
#define ADC_CHSELR_CHSEL4  (0x00000010)
#define ADC_CHSELR_CHSEL3  (0x00000008)
#define ADC_CHSELR_CHSEL2  (0x00000004)
#define ADC_CHSELR_CHSEL1  (0x00000002)
#define ADC_CHSELR_CHSEL0  (0x00000001)


/** ADC data register(ADC_DR)
 * offset: 0x0040
 * reset value: 0x0000 0000
 */
#define ADC_DR_DATA (0x0000ffff)


/** ADC common configuration regsiter(ADC_CCR)
 * offset: 0x0308
 * reset value: 0x0000 0000
 */
#define ADC_CCR_VBATEN (0x01000000)
#define ADC_CCR_TSEN   (0x00800000)
#define ADC_CCR_VREFEN (0x00400000)

#endif
