#ifndef _SYSTICK_H
#define _SYSTICK_H

#include <stdint.h>
#include "io.h"


#define SYSTICK_ADDRESS (0xe000e010)
#define SYSTICK ((volatile systick_t *)SYSTICK_ADDRESS)

typedef struct _systick_t systick_t;

struct _systick_t {
  __IO uint32_t CSR;   // 0x0000
  __IO uint32_t RVR;   // 0x0004
  __IO uint32_t CVR;   // 0x0008
  __RO uint32_t CALIB; // 0x000c
};


/** SysTick control and status register(STK_CSR)
 * offset: 0x0000
 * reset value: 0x0000 0004
 */
#define STK_CSR_COUNTFLAG (0x00010000)
#define STK_CSR_CLKSOURCE (0x00000004)
#define STK_CSR_TICKINT   (0x00000002)
#define STK_CSR_ENABLE    (0x00000001)


/** SysTick reload value register(STK_RVR)
 * offset: 0x0004
 * reset value: unknown
 */
#define STK_RVR_RELOAD (0x00ffffff)


/** SysTick current value register(STK_CVR)
 * offset: 0x0008
 * reset value: unknown
 */
#define STK_CVR_CURRENT (0x00ffffff)


/** SysTick calibration value register(STK_CALIB)
 * offset: 0x000c
 * reset value: 0x0000 0000
 */
#define STK_CALIB_NOREF (0x80000000)
#define STK_CALIB_SKEW  (0x40000000)
#define STK_CALIB_TENMS (0x00ffffff)


#endif
