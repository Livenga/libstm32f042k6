#ifndef _NVIC_H
#define _NVIC_H

#include <stdint.h>
#include "io.h"


#define NVIC_ADDRESS (0xe000e100)
#define NVIC ((volatile nvic_t *)NVIC_ADDRESS)


#define Enable_NVIC(nvic_id) \
  NVIC->ISER |= (1 << nvic_id)

#define Disable_NVIC(nvic_id) \
  NVIC->ICER = (1 << nvic_id)


typedef struct _nvic_t nvic_t;

struct _nvic_t {
  __IO uint32_t ISER; // 0x0000

  __RO uint32_t _reserved_0[31];

  __IO uint32_t ICER; // 0x0080

  __RO uint32_t _reserved_1[31];

  __IO uint32_t ISPR; // 0x0200

  __RO uint32_t _reserved_2[31];

  __IO uint32_t ICPR; // 0x0280

  __RO uint32_t _reserved_3[95];

  __IO uint32_t IPR[8]; // 0xe400
};


typedef enum {
  WWDG_IRQn = 0,
  PVD_VDDIO2_IRQn_IRQn,
  TTC_IRQn,
  FLASH_IRQn,
  RCC_CRS_IRQn,
  EXTI0_1_IRQn,
  EXTI2_3_IRQn,
  EXTI14_15_IRQn,
  TSC_IRQn,
  DMA_CH1_IRQn,
  DMA_CH2_3_IRQn, // 10
  DMA_CH4_5_6_7_IRQn,
  ADC_COMP_IRQn,
  TIM1_BRK_UP_TRG_COM_IRQn,
  TIM1_CC_IRQn,
  TIM2_IRQn,
  TIM3_IRQn,
  TIM6_DAC_IRQn,
  TIM7_IRQn,
  TIM14_IRQn,
  TIM15_IRQn, // 20
  TIM16_IRQn,
  TIM17_IRQn,
  I2C1_IRQn,
  I2C2_IRQn,
  SPI1_IRQn,
  SPI2_IRQn,
  USART1_IRQn,
  USART2_IRQn,
  USART3_4_5_6_7_8_IRQn,
  CEC_CAN_IRQn, // 30
  USB_IRQn
} nvic_id_t;

#endif
