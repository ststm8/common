#ifndef __stm8mcu_h__
#define __stm8mcu_h__

#ifdef STM8S105K4
#include <STM8S105K4.h>
#elif STM8L101K3
#include <STM8L101K3.h>
#elif STM8S103K3
#include <STM8S103K3.h>
#else
#error unknown STM8 MCU
#endif

#include "types.h"

// STM8_FREQ defined trhough Makefile
#define STM8_FREQ_MHZ ((uint8_t)(STM8_FREQ / 1000000L))

#endif