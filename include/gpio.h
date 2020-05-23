#ifndef _GPIO_H
#define _GPIO_H


#include <stdint.h>
#include "io.h"


#define GPIO_A_ADDRESS (0x48000000)
#define GPIO_B_ADDRESS (0x48000400)
#define GPIO_C_ADDRESS (0x48000800)
#define GPIO_D_ADDRESS (0x48000c00)
#define GPIO_E_ADDRESS (0x48001000)
#define GPIO_F_ADDRESS (0x48001400)


#define GPIO_A ((gpio_t *)GPIO_A_ADDRESS)
#define GPIO_B ((gpio_t *)GPIO_B_ADDRESS)
#define GPIO_C ((gpio_t *)GPIO_C_ADDRESS)
#define GPIO_D ((gpio_t *)GPIO_D_ADDRESS)
#define GPIO_E ((gpio_t *)GPIO_E_ADDRESS)
#define GPIO_F ((gpio_t *)GPIO_F_ADDRESS)


typedef struct _gpio_t gpio_t;
struct _gpio_t {
  __IO uint32_t MODER;   // 0x0000
  __IO uint32_t OTYPER;  // 0x0004
  __IO uint32_t OSPEEDR; // 0x0008
  __IO uint32_t PUPDR;   // 0x000c
  __RO uint32_t IDR;     // 0x0010
  __IO uint32_t ODR;     // 0x0014
  __IO uint32_t BSRR;    // 0x0018
  __IO uint32_t LCKR;    // 0x001c
  __IO uint32_t AFRL;    // 0x0020
  __IO uint32_t AFRH;    // 0x0024
  __IO uint32_t BRR;     // 0x0028
};


#define GPIO_SET_MODE(GPIO, PIN, MODE) \
  GPIO->MODER = (GPIO->MODER & ~(0b11 << (PIN * 2))) | (MODE << (PIN * 2))

#define GPIO_SET_OTYPE (GPIO, PIN, SPEED) \
  GPIO->OTYPER = (GPIO->OTYPER & ~(0b11 << (PIN * 2))) | (SPEED << (PIN * 2))

#define GPIO_SET_PUPD(GPIO, PIN, PUPD) \
  GPIO->PUPDR = (GPIO->PUPDR & ~(0b11 << (PIN * 2))) | (PUPD << (PIN * 2))

#define GPIO_ON(GPIO, PIN) \
  GPIO->BSRR = (1 << PIN)

#define GPIO_OFF(GPIO, PIN) \
  GPIO->BRR = (1 << PIN)

/** GPIO port mode register(GPIOx_MODER)
 * offset: 0x0000
 * reset value: 0x2800 0000 (for port A)
 * reset value: 0x0000 0000
 */
#define GPIO_MODER_MODER15 (0xc0000000)
#define GPIO_MODER_MODER14 (0x30000000)
#define GPIO_MODER_MODER13 (0x0c000000)
#define GPIO_MODER_MODER12 (0x03000000)
#define GPIO_MODER_MODER11 (0x00c00000)
#define GPIO_MODER_MODER10 (0x00300000)
#define GPIO_MODER_MODER9  (0x000c0000)
#define GPIO_MODER_MODER8  (0x00030000)
#define GPIO_MODER_MODER7  (0x0000c000)
#define GPIO_MODER_MODER6  (0x00003000)
#define GPIO_MODER_MODER5  (0x00000c00)
#define GPIO_MODER_MODER4  (0x00000300)
#define GPIO_MODER_MODER3  (0x000000c0)
#define GPIO_MODER_MODER2  (0x00000030)
#define GPIO_MODER_MODER1  (0x0000000c)
#define GPIO_MODER_MODER0  (0x00000003)

#define GPIO_MODER_INPUT              (0b00)
#define GPIO_MODER_OUTPUT             (0b01)
#define GPIO_MODER_ALTERNATE_FUNCTION (0b10)
#define GPIO_MODER_ANALOG             (0b11)



/** GPIO port output type register(GPIOx_OTYPER)
 * offset: 0x0004
 * reset value: 0x0000 0000
 */
#define GPIO_OTYPER_OT15 (0x00008000)
#define GPIO_OTYPER_OT14 (0x00004000)
#define GPIO_OTYPER_OT13 (0x00002000)
#define GPIO_OTYPER_OT12 (0x00001000)
#define GPIO_OTYPER_OT11 (0x00000800)
#define GPIO_OTYPER_OT10 (0x00000400)
#define GPIO_OTYPER_OT9  (0x00000200)
#define GPIO_OTYPER_OT8  (0x00000100)
#define GPIO_OTYPER_OT7  (0x00000080)
#define GPIO_OTYPER_OT6  (0x00000040)
#define GPIO_OTYPER_OT5  (0x00000020)
#define GPIO_OTYPER_OT4  (0x00000010)
#define GPIO_OTYPER_OT3  (0x00000008)
#define GPIO_OTYPER_OT2  (0x00000004)
#define GPIO_OTYPER_OT1  (0x00000002)
#define GPIO_OTYPER_OT0  (0x00000001)

#define GPIO_OTYPER_LOW_SPEED    (0b00)
#define GPIO_OTYPER_MEDIUM_SPEED (0b01)
#define GPIO_OTYPER_HIGH_SPEED   (0b11)



/** GPIO port output speed register(GPIOx_OSPEEDR)
 * offset: 0x0008
 * reset value: 0x0c00 0000(for port A)
 * reset value: 0x0000 0000
 */
#define GPIO_OSPEEDR_OSPEEDR15 (0xc0000000)
#define GPIO_OSPEEDR_OSPEEDR14 (0x30000000)
#define GPIO_OSPEEDR_OSPEEDR13 (0x0c000000)
#define GPIO_OSPEEDR_OSPEEDR12 (0x03000000)
#define GPIO_OSPEEDR_OSPEEDR11 (0x00c00000)
#define GPIO_OSPEEDR_OSPEEDR10 (0x00300000)
#define GPIO_OSPEEDR_OSPEEDR9  (0x000c0000)
#define GPIO_OSPEEDR_OSPEEDR8  (0x00030000)
#define GPIO_OSPEEDR_OSPEEDR7  (0x0000c000)
#define GPIO_OSPEEDR_OSPEEDR6  (0x00003000)
#define GPIO_OSPEEDR_OSPEEDR5  (0x00000c00)
#define GPIO_OSPEEDR_OSPEEDR4  (0x00000300)
#define GPIO_OSPEEDR_OSPEEDR3  (0x000000c0)
#define GPIO_OSPEEDR_OSPEEDR2  (0x00000030)
#define GPIO_OSPEEDR_OSPEEDR1  (0x0000000c)
#define GPIO_OSPEEDR_OSPEEDR0  (0x00000003)


/** GPIO port pull-up/pull-down register(GPIOx_PUPDR)
 * offset: 0x000c
 * reset value: 0x2400 0000(for port A)
 * reset value: 0x0000 0000
 */
#define GPIO_PUPDR_PUPDR15 (0xc0000000)
#define GPIO_PUPDR_PUPDR14 (0x30000000)
#define GPIO_PUPDR_PUPDR13 (0x0c000000)
#define GPIO_PUPDR_PUPDR12 (0x03000000)
#define GPIO_PUPDR_PUPDR11 (0x00c00000)
#define GPIO_PUPDR_PUPDR10 (0x00300000)
#define GPIO_PUPDR_PUPDR9  (0x000c0000)
#define GPIO_PUPDR_PUPDR8  (0x00030000)
#define GPIO_PUPDR_PUPDR7  (0x0000c000)
#define GPIO_PUPDR_PUPDR6  (0x00003000)
#define GPIO_PUPDR_PUPDR5  (0x00000c00)
#define GPIO_PUPDR_PUPDR4  (0x00000300)
#define GPIO_PUPDR_PUPDR3  (0x000000c0)
#define GPIO_PUPDR_PUPDR2  (0x00000030)
#define GPIO_PUPDR_PUPDR1  (0x0000000c)
#define GPIO_PUPDR_PUPDR0  (0x00000003)


#define GPIO_PUPDR_NO        (0b00)
#define GPIO_PUPDR_PULL_UP   (0b01)
#define GPIO_PUPDR_PULL_DOWN (0b10)


/** GPIO port input data register(GPIOx_IDR)
 * offset: 0x0010
 * reset value: 0x0000 xxxx
 */
#define GPIO_IDR_IDR15 (0x00008000)
#define GPIO_IDR_IDR14 (0x00004000)
#define GPIO_IDR_IDR13 (0x00002000)
#define GPIO_IDR_IDR12 (0x00001000)
#define GPIO_IDR_IDR11 (0x00000800)
#define GPIO_IDR_IDR10 (0x00000400)
#define GPIO_IDR_IDR9  (0x00000200)
#define GPIO_IDR_IDR8  (0x00000100)
#define GPIO_IDR_IDR7  (0x00000080)
#define GPIO_IDR_IDR6  (0x00000040)
#define GPIO_IDR_IDR5  (0x00000020)
#define GPIO_IDR_IDR4  (0x00000010)
#define GPIO_IDR_IDR3  (0x00000008)
#define GPIO_IDR_IDR2  (0x00000004)
#define GPIO_IDR_IDR1  (0x00000002)
#define GPIO_IDR_IDR0  (0x00000001)


/** GPIO port output data register(GPIOx_ODR)
 * offset: 0x0014
 * reset value: 0x0000 0000
 */
#define GPIO_ODR_ODR15 (0x00008000)
#define GPIO_ODR_ODR14 (0x00004000)
#define GPIO_ODR_ODR13 (0x00002000)
#define GPIO_ODR_ODR12 (0x00001000)
#define GPIO_ODR_ODR11 (0x00000800)
#define GPIO_ODR_ODR10 (0x00000400)
#define GPIO_ODR_ODR9  (0x00000200)
#define GPIO_ODR_ODR8  (0x00000100)
#define GPIO_ODR_ODR7  (0x00000080)
#define GPIO_ODR_ODR6  (0x00000040)
#define GPIO_ODR_ODR5  (0x00000020)
#define GPIO_ODR_ODR4  (0x00000010)
#define GPIO_ODR_ODR3  (0x00000008)
#define GPIO_ODR_ODR2  (0x00000004)
#define GPIO_ODR_ODR1  (0x00000002)
#define GPIO_ODR_ODR0  (0x00000001)


/** GPIO port bit set/reset register(GPIOx_BSRR)
 * offset: 0x0018
 * reset value: 0x0000 0000
 */
#define GPIO_BSRR_BR15 (0x80000000)
#define GPIO_BSRR_BR14 (0x40000000)
#define GPIO_BSRR_BR13 (0x20000000)
#define GPIO_BSRR_BR12 (0x10000000)
#define GPIO_BSRR_BR11 (0x08000000)
#define GPIO_BSRR_BR10 (0x04000000)
#define GPIO_BSRR_BR9  (0x02000000)
#define GPIO_BSRR_BR8  (0x01000000)
#define GPIO_BSRR_BR7  (0x00800000)
#define GPIO_BSRR_BR6  (0x00400000)
#define GPIO_BSRR_BR5  (0x00200000)
#define GPIO_BSRR_BR4  (0x00100000)
#define GPIO_BSRR_BR3  (0x00080000)
#define GPIO_BSRR_BR2  (0x00040000)
#define GPIO_BSRR_BR1  (0x00020000)
#define GPIO_BSRR_BR0  (0x00010000)
#define GPIO_BSRR_BS15 (0x00008000)
#define GPIO_BSRR_BS14 (0x00004000)
#define GPIO_BSRR_BS13 (0x00002000)
#define GPIO_BSRR_BS12 (0x00001000)
#define GPIO_BSRR_BS11 (0x00000800)
#define GPIO_BSRR_BS10 (0x00000400)
#define GPIO_BSRR_BS9  (0x00000200)
#define GPIO_BSRR_BS8  (0x00000100)
#define GPIO_BSRR_BS7  (0x00000080)
#define GPIO_BSRR_BS6  (0x00000040)
#define GPIO_BSRR_BS5  (0x00000020)
#define GPIO_BSRR_BS4  (0x00000010)
#define GPIO_BSRR_BS3  (0x00000008)
#define GPIO_BSRR_BS2  (0x00000004)
#define GPIO_BSRR_BS1  (0x00000002)
#define GPIO_BSRR_BS0  (0x00000001)


/** GPIO port configuration lock register(GPIOx_LCKR)
 * offset: 0x001c
 * reset value: 0x0000 0000
 */
#define GPIO_LCKR_LCKK  (0x00010000)
#define GPIO_LCKR_LCK15 (0x00008000)
#define GPIO_LCKR_LCK14 (0x00004000)
#define GPIO_LCKR_LCK13 (0x00002000)
#define GPIO_LCKR_LCK12 (0x00001000)
#define GPIO_LCKR_LCK11 (0x00000800)
#define GPIO_LCKR_LCK10 (0x00000400)
#define GPIO_LCKR_LCK9  (0x00000200)
#define GPIO_LCKR_LCK8  (0x00000100)
#define GPIO_LCKR_LCK7  (0x00000080)
#define GPIO_LCKR_LCK6  (0x00000040)
#define GPIO_LCKR_LCK5  (0x00000020)
#define GPIO_LCKR_LCK4  (0x00000010)
#define GPIO_LCKR_LCK3  (0x00000008)
#define GPIO_LCKR_LCK2  (0x00000004)
#define GPIO_LCKR_LCK1  (0x00000002)
#define GPIO_LCKR_LCK0  (0x00000001)


/** GPIO alternate function low register(GPIOx_AFRL)
 * offset: 0x0020
 * reset value: 0x0000 0000
 */
#define GPIO_AFRL_AFSEL7 (0xf0000000)
#define GPIO_AFRL_AFSEL6 (0x0f000000)
#define GPIO_AFRL_AFSEL5 (0x00f00000)
#define GPIO_AFRL_AFSEL4 (0x000f0000)
#define GPIO_AFRL_AFSEL3 (0x0000f000)
#define GPIO_AFRL_AFSEL2 (0x00000f00)
#define GPIO_AFRL_AFSEL1 (0x000000f0)
#define GPIO_AFRL_AFSEL0 (0x0000000f)

#define GPIO_AFRL_AFSEL_AF0 (0b0000)
#define GPIO_AFRL_AFSEL_AF1 (0b0001)
#define GPIO_AFRL_AFSEL_AF2 (0b0010)
#define GPIO_AFRL_AFSEL_AF3 (0b0011)
#define GPIO_AFRL_AFSEL_AF4 (0b0100)
#define GPIO_AFRL_AFSEL_AF5 (0b0101)
#define GPIO_AFRL_AFSEL_AF6 (0b0110)
#define GPIO_AFRL_AFSEL_AF7 (0b0111)


/** GPIO alternate function high register(GPIOx_AFRH)
 * offset: 0x0020
 * reset value: 0x0000 0000
 */
#define GPIO_AFRH_AFSEL15 (0xf0000000)
#define GPIO_AFRH_AFSEL14 (0x0f000000)
#define GPIO_AFRH_AFSEL13 (0x00f00000)
#define GPIO_AFRH_AFSEL12 (0x000f0000)
#define GPIO_AFRH_AFSEL11 (0x0000f000)
#define GPIO_AFRH_AFSEL10 (0x00000f00)
#define GPIO_AFRH_AFSEL9  (0x000000f0)
#define GPIO_AFRH_AFSEL8  (0x0000000f)

#define GPIO_AFRH_AFSEL_AF0 (0b0000)
#define GPIO_AFRH_AFSEL_AF1 (0b0001)
#define GPIO_AFRH_AFSEL_AF2 (0b0010)
#define GPIO_AFRH_AFSEL_AF3 (0b0011)
#define GPIO_AFRH_AFSEL_AF4 (0b0100)
#define GPIO_AFRH_AFSEL_AF5 (0b0101)
#define GPIO_AFRH_AFSEL_AF6 (0b0110)
#define GPIO_AFRH_AFSEL_AF7 (0b0111)


/** GPIO port bit reset register(GPIOx_BRR)
 * offset: 0x0028
 * reset value: 0x0000 0000
 */
#define GPIO_BRR_BR15 (0x00008000)
#define GPIO_BRR_BR14 (0x00004000)
#define GPIO_BRR_BR13 (0x00002000)
#define GPIO_BRR_BR12 (0x00001000)
#define GPIO_BRR_BR11 (0x00000800)
#define GPIO_BRR_BR10 (0x00000400)
#define GPIO_BRR_BR9  (0x00000200)
#define GPIO_BRR_BR8  (0x00000100)
#define GPIO_BRR_BR7  (0x00000080)
#define GPIO_BRR_BR6  (0x00000040)
#define GPIO_BRR_BR5  (0x00000020)
#define GPIO_BRR_BR4  (0x00000010)
#define GPIO_BRR_BR3  (0x00000008)
#define GPIO_BRR_BR2  (0x00000004)
#define GPIO_BRR_BR1  (0x00000002)
#define GPIO_BRR_BR0  (0x00000001)
#endif
