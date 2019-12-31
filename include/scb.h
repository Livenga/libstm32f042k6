#ifndef _SCB_H
#define _SCB_H

#include <stdint.h>
#include "io.h"


#define SCB_ADDRESS (0xe000ed00)
#define SCB ((volatile scb_t *)SCB_ADDRESS)


typedef struct _scb_t scb_t;
struct _scb_t {
  __RO uint32_t CPUID;       // 0xed00
  __IO uint32_t ICSR;        // 0xed04

  __RO uint32_t _reserved_0; //0xed08

  __IO uint32_t AIRCR;       // 0xed0c
  __IO uint32_t SCR;         // 0xed10
  __IO uint32_t CCR;         // 0xed14

  __RO uint32_t _reserved_1; // 0xed18
  __IO uint32_t SHPR2;       // 0xed1c
  __IO uint32_t SHPR3;       // 0xed20
};


#endif
