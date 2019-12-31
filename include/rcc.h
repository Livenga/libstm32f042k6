#ifndef _RCC_H
#define _RCC_H

#include <stdint.h>
#include "io.h"


#define RCC_ADDRESS (0x40021000)
#define RCC ((volatile rcc_t *)RCC_ADDRESS)


typedef struct _rcc_t rcc_t;
struct _rcc_t {
  __IO uint32_t CR;       // 0x0000
  __IO uint32_t CFGR;     // 0x0004
  __IO uint32_t CIR;      // 0x0008
  __IO uint32_t APB2RSTR; // 0x000c
  __IO uint32_t APB1RSTR; // 0x0010
  __IO uint32_t AHBENR;   // 0x0014
  __IO uint32_t APB2ENR;  // 0x0018
  __IO uint32_t APB1ENR;  // 0x001c
  __IO uint32_t BDCR;     // 0x0020
  __IO uint32_t CSR;      // 0x0024
  __IO uint32_t AHBRSTR;  // 0x0028
  __IO uint32_t CFGR2;    // 0x002c
  __IO uint32_t CFGR3;    // 0x0030
  __IO uint32_t CR2;      // 0x0034
};


/** Clock control register(RCC_CR)
 * offset:      0x0000
 * reset value: 0x0000 xx83
 */
#define RCC_CR_PLLRDY  (0x02000000)
#define RCC_CR_PLLON   (0x01000000)
#define RCC_CR_CSSON   (0x00080000)
#define RCC_CR_HSEBYP  (0x00040000)
#define RCC_CR_HSERDY  (0x00020000)
#define RCC_CR_HSEON   (0x00010000)
#define RCC_CR_HSICALL (0x0000ff00)
#define RCC_CR_HSITRIM (0x000000f8)
#define RCC_CR_HSIRDY  (0x00000002)
#define RCC_CR_HSION   (0x00000001)


/** Clock configuration register(RCC_CFGR)
 * offset: 0x0004
 * reset value: 0x0000 0000
 */
#define RCC_CFGR_PLLNODIV (0x80000000)
#define RCC_CFGR_MCPRE    (0x70000000)
#define RCC_CFGR_MCO      (0x0f000000)
#define RCC_CFGR_PLLMUL   (0x003c0000)
#define RCC_CFGR_PLLXTPRE (0x00020000)
#define RCC_CFGR_PLLSRC   (0x00018000)
#define RCC_CFGR_ADCPRE   (0x00004000)
#define RCC_CFGR_PPRE     (0x00000700)
#define RCC_CFGR_HPRE     (0x000000f0)
#define RCC_CFGR_SWS      (0x0000000c)
#define RCC_CFGR_SW       (0x00000003)

// System clock switch status
#define RCC_CFGR_SWS_HSI   (0x00000000)
#define RCC_CFGR_SWS_HSE   (0x00000004)
#define RCC_CFGR_SWS_PLL   (0x00000008)
#define RCC_CFGR_SWS_HSI48 (0x0000000c)

// System clock switch
#define RCC_CFGR_SW_HSI   (0x00000000)
#define RCC_CFGR_SW_HSE   (0x00000001)
#define RCC_CFGR_SW_PLL   (0x00000002)
#define RCC_CFGR_SW_HSI48 (0x00000003)


/** Clock interupt register(RCC_CIR)
 * offset: 0x0008
 * reset value: 0x0000 0000
 */
#define RCC_CIR_CSSC       (0x00800000)
#define RCC_CIR_HSI48RDYC  (0x00400000)
#define RCC_CIR_HSI14RDYC  (0x00200000)
#define RCC_CIR_PLLRDYC    (0x00100000)
#define RCC_CIR_HSERDYC    (0x00080000)
#define RCC_CIR_HSIRDYC    (0x00040000)
#define RCC_CIR_LSERDYC    (0x00020000)
#define RCC_CIR_LSIRDYC    (0x00010000)
#define RCC_CIR_HSI48RDYIE (0x00004000)
#define RCC_CIR_HSI14RDYIE (0x00002000)
#define RCC_CIR_PLLRDYIE   (0x00001000)
#define RCC_CIR_HSERDYIE   (0x00000800)
#define RCC_CIR_HSIRDYIE   (0x00000400)
#define RCC_CIR_LSERDYIE   (0x00000200)
#define RCC_CIR_LSIRDYIE   (0x00000100)
#define RCC_CIR_CSSF       (0x00000080)
#define RCC_CIR_HSI48RDYF  (0x00000040)
#define RCC_CIR_HSI14RDYF  (0x00000020)
#define RCC_CIR_PLLRDYF    (0x00000010)
#define RCC_CIR_HSERDYF    (0x00000008)
#define RCC_CIR_HSIRDYF    (0x00000004)
#define RCC_CIR_LSERDYF    (0x00000002)
#define RCC_CIR_LSIRDYF    (0x00000001)


/** APB peripheral reset register 2 (RCC_APB2RSTR)
 * offset: 0x000c
 * reset value: 0x0000 0000
 */
#define RCC_APB2RSTR_DBGMCURST (0x00400000)
#define RCC_APB2RSTR_TIM17RST  (0x00040000)
#define RCC_APB2RSTR_TIM16RST  (0x00020000)
#define RCC_APB2RSTR_TIM15RST  (0x00010000)
#define RCC_APB2RSTR_USART1RST (0x00004000)
#define RCC_APB2RSTR_SPI1RST   (0x00001000)
#define RCC_APB2RSTR_TIM1RST   (0x00000800)
#define RCC_APB2RSTR_ADCRST    (0x00000200)
#define RCC_APB2RSTR_USART8RST (0x00000080)
#define RCC_APB2RSTR_USART7RST (0x00000040)
#define RCC_APB2RSTR_USART6RST (0x00000020)
#define RCC_APB2RSTR_SYSCFGRST (0x00000001)


/** APB peripheral reset register 1 (RCC_APB1RSTR)
 * offset: 0x0010
 * reset value: 0x0000 0000
 */
#define RCC_APB1RSTR_CECRST    (0x40000000)
#define RCC_APB1RSTR_DACRST    (0x20000000)
#define RCC_APB1RSTR_PWRRST    (0x10000000)
#define RCC_APB1RSTR_CRSRST    (0x08000000)
#define RCC_APB1RSTR_CANRST    (0x02000000)
#define RCC_APB1RSTR_USBRST    (0x00800000)
#define RCC_APB1RSTR_I2C2RST   (0x00400000)
#define RCC_APB1RSTR_I2C1RST   (0x00200000)
#define RCC_APB1RSTR_USART5RST (0x00100000)
#define RCC_APB1RSTR_USART4RST (0x00080000)
#define RCC_APB1RSTR_USART3RST (0x00040000)
#define RCC_APB1RSTR_USART2RST (0x00020000)
#define RCC_APB1RSTR_SPI2RST   (0x00004000)
#define RCC_APB1RSTR_WWDGRST   (0x00000800)
#define RCC_APB1RSTR_TIM14RST  (0x00000100)
#define RCC_APB1RSTR_TIM7RST   (0x00000020)
#define RCC_APB1RSTR_TIM6RST   (0x00000010)
#define RCC_APB1RSTR_TIM3RST   (0x00000002)
#define RCC_APB1RSTR_TIM2RST   (0x00000001)


/** AHB peripheral clock enable register(RCC_AHBENR)
 * offset: 0x0014
 * reset value: 0x0000 0014
 */
#define RCC_AHBENR_TSCEN   (0x01000000)
#define RCC_AHBENR_IOPFEN  (0x00400000)
#define RCC_AHBENR_IOPEEN  (0x00200000)
#define RCC_AHBENR_IOPDEN  (0x00100000)
#define RCC_AHBENR_IOPCEN  (0x00080000)
#define RCC_AHBENR_IOPBEN  (0x00040000)
#define RCC_AHBENR_IOPAEN  (0x00020000)
#define RCC_AHBENR_CRCEN   (0x00000040)
#define RCC_AHBENR_FLITFEN (0x00000010)
#define RCC_AHBENR_SRAMEN  (0x00000004)
#define RCC_AHBENR_DMA2EN  (0x00000002)
#define RCC_AHBENR_DMAEN   (0x00000001)


/** APB peripheral clock enable register 2 (RCC_APB2ENR)
 * offset: 0x0018
 * reset value: 0x0000 0000
 */
#define RCC_APB2ENR_DBGMCUEN     (0x00400000)
#define RCC_APB2ENR_TIM17EN      (0x00040000)
#define RCC_APB2ENR_TIM16EN      (0x00020000)
#define RCC_APB2ENR_TIM15EN      (0x00010000)
#define RCC_APB2ENR_USART1EN     (0x00004000)
#define RCC_APB2ENR_SPI1EN       (0x00001000)
#define RCC_APB2ENR_TIM1EN       (0x00000800)
#define RCC_APB2ENR_ADCEN        (0x00000200)
#define RCC_APB2ENR_USART8EN     (0x00000080)
#define RCC_APB2ENR_USART7EN     (0x00000040)
#define RCC_APB2ENR_USART6EN     (0x00000020)
#define RCC_APB2ENR_SYSCFGCOMPEN (0x00000001)


/** APB peripheral clock enable register 1 (RCC_APB1ENR)
 * offset: 0x001c
 * reset value: 0x0000 0000
 */
#define RCC_APB1ENR_CECEN    (0x40000000)
#define RCC_APB1ENR_DACEN    (0x20000000)
#define RCC_APB1ENR_PWREN    (0x10000000)
#define RCC_APB1ENR_CRSEN    (0x08000000)
#define RCC_APB1ENR_CANEN    (0x02000000)
#define RCC_APB1ENR_USBEN    (0x00800000)
#define RCC_APB1ENR_I2C2EN   (0x00400000)
#define RCC_APB1ENR_I2C1EN   (0x00200000)
#define RCC_APB1ENR_USART5EN (0x00100000)
#define RCC_APB1ENR_USART4EN (0x00080000)
#define RCC_APB1ENR_USART3EN (0x00040000)
#define RCC_APB1ENR_USART2EN (0x00020000)
#define RCC_APB1ENR_SPI2EN   (0x00004000)
#define RCC_APB1ENR_WWDGEN   (0x00000800)
#define RCC_APB1ENR_TIM14EN  (0x00000100)
#define RCC_APB1ENR_TIM7EN   (0x00000020)
#define RCC_APB1ENR_TIM6EN   (0x00000010)
#define RCC_APB1ENR_TIM3EN   (0x00000002)
#define RCC_APB1ENR_TIM2EN   (0x00000001)


/** RTC domain control register(RCC_BDCR)
 * offset: 0x0020
 * reset value: 0x0000 0018
 */
#define RCC_BDCR_BDRST  (0x00010000)
#define RCC_BDCR_RTCEN  (0x00008000)
#define RCC_BDCR_RTCSEL (0x00000300)
#define RCC_BDCR_LSEDRV (0x00000018)
#define RCC_BDCR_LSEBYP (0x00000004)
#define RCC_BDCR_LSERDY (0x00000002)
#define RCC_BDCR_LSEON  (0x00000001)


/** Control/status register(RCC_CSR)
 * offset: 0x0024
 * reset value: 0xxxx0 0000
 */
#define RCC_CSR_LPWRRSTF   (0x80000000)
#define RCC_CSR_WWDGRSTF   (0x40000000)
#define RCC_CSR_IWDGRSTF   (0x20000000)
#define RCC_CSR_SFTRSTF    (0x10000000)
#define RCC_CSR_PORRSTF    (0x08000000)
#define RCC_CSR_PINRSTF    (0x04000000)
#define RCC_CSR_OBLRSTF    (0x02000000)
#define RCC_CSR_RMVF       (0x01000000)
#define RCC_CSR_V18PWRRSTF (0x00800000)
#define RCC_CSR_LSIRDY     (0x00000002)
#define RCC_CSR_LSION      (0x00000001)


/** AHB peripheral reset register(RCC_AHBRSTR)
 * offset: 0x0028
 * reset value: 0x0000 0000
 */
#define RCC_AHBRSTR_TSCRST  (0x01000000)
#define RCC_AHBRSTR_IOPFRST (0x00400000)
#define RCC_AHBRSTR_IOPERST (0x00200000)
#define RCC_AHBRSTR_IOPDRST (0x00100000)
#define RCC_AHBRSTR_IOPCRST (0x00080000)
#define RCC_AHBRSTR_IOPBRST (0x00040000)
#define RCC_AHBRSTR_IOPARST (0x00020000)


/** Clock configuration register 2(RCC_CFGR2)
 * offset: 0x002c
 * reset value: 0x0000 0000
 */
#define RCC_CFGR2_PREDIV (0x0000000f)


/** Clock configuration register 3(RCC_CFGR3)
 * offset: 0x0030
 * reset value: 0x0000 0000
 */
#define RCC_CFGR3_USART3SW (0x000c0000)
#define RCC_CFGR3_USART2SW (0x00030000)
#define RCC_CFGR3_ADCSW    (0x00000100)
#define RCC_CFGR3_USBSW    (0x00000080)
#define RCC_CFGR3_CECSW    (0x00000040)
#define RCC_CFGR3_I2C1SW   (0x00000010)
#define RCC_CFGR3_USART1SW (0x00000003)


/** Clock control register 2(RCC_RC2)
 * offset: 0x0034
 * reset value: 0xxx00 xx80
 */
#define RCC_CR2_HSI48CAL  (0xff000000)
#define RCC_CR2_HSI48RDY  (0x00020000)
#define RCC_CR2_HSI48ON   (0x00010000)
#define RCC_CR2_HSI14CAL  (0x0000ff00)
#define RCC_CR2_HSI14TRIM (0x000000f8)
#define RCC_CR2_HSI14DIS  (0x00000004)
#define RCC_CR2_HSI14RDY  (0x00000002)
#define RCC_CR2_HSI14ON   (0x00000001)

#endif 
