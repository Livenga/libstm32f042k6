/** RM0091
 * 3.5.9 Flash register map p.73
 */

#ifndef _FLASH_H
#define _FLASH_H

#include <stdint.h>
#include "io.h"

#define FLASH_ADDRESS (0x40022000)
#define FLASH ((struct flash_t *)FLASH_ADDRESS)

struct flash_t {
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;

  __RO uint32_t _reserved_0;

  __RO uint32_t OBR;
  __IO uint32_t WRPR;
};

/** Flash access control register(FLASH_ACR)
 */
#define FLASH_ACR_PRFTBS  (0x00000020)
#define FLASH_ACR_PRFTBE  (0x00000010)
#define FLASH_ACR_LATENCY (0x00000007)

// Latency
// Zero wait state, if SYSCLK <= 24MHz
#define FLASH_ACR_LATENCY_ZERO_WAIT (0x00000000)
// One wait state, if 24MHz <= SYSCLK <= 48MHz
#define FLASH_ACR_LATENCY_ONE_WAIT  (0x00000001)


/** Flash key register(FLASH_KEYR)
 */
#define FLASH_KEYR_FKEY (0xffffffff)


/** Flash option key register(FLASH_OPTKEYR)
 */
#define FLASH_OPTKEYR_OPTKEY (0xffffffff)


/** Flash status register(FLASH_SR)
 */
#define FLASH_SR_EOP      (0x00000020)
#define FLASH_SR_WRPRTERR (0x00000010)
#define FLASH_SR_PGERR    (0x00000004)
#define FLASH_SR_BSY      (0x00000001)


/** Flash control register(FLASH_CR)
 */
#define FLASH_CR_OBL_LAUNCH (0x00002000)
#define FLASH_CR_EOFIE      (0x00001000)
#define FLASH_CR_ERRIE      (0x00000400)
#define FLASH_CR_OPTWRE     (0x00000200)
#define FLASH_CR_LOCK       (0x00000080)
#define FLASH_CR_STRT       (0x00000040)
#define FLASH_CR_OPTER      (0x00000020)
#define FLASH_CR_OPTPG      (0x00000010)
#define FLASH_CR_MER        (0x00000004)
#define FLASH_CR_PER        (0x00000002)
#define FLASH_CR_PG         (0x00000001)


/** Flash address register(FLASH_AR)
 */
#define FLASH_AR_FAR (0xffffffff)


/** Flash Option byte register(FLASH_OBR)
 */
#define FLASH_OBR_DATA1            (0xff000000)
#define FLASH_OBR_DATA0            (0x00ff0000)
#define FLASH_OBR_BOOT_SEL         (0x00008000)
#define FLASH_OBR_RAM_PARITY_CHECK (0x00004000)
#define FLASH_OBR_VDDA_MONITOR     (0x00002000)
#define FLASH_OBR_NBOOT1           (0x00001000)
#define FLASH_OBR_NBOOT0           (0x00000800)
#define FLASH_OBR_NRST_STDBY       (0x00000400)
#define FLASH_OBR_NRST_STOP        (0x00000200)
#define FLASH_OBR_WDG_SW           (0x00000100)
#define FLASH_OBR_RDPRT            (0x00000006)
#define FLASH_OBR_OPTERR           (0x00000001)


/** Flash write protection register
 */
#define FLASH_WRPR_WRP (0xffffffff)
#endif
