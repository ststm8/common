#ifndef __types_h__
#define __types_h__

#include <stddef.h>
#include <stdint.h>

#define __DEF(x) #x
#define __ESC(...) __VA_ARGS__
#define __CONCAT(a, b) a##b
#define __CONCAT3(a, b, c) a##b##c

#define ON 1
#define OFF 1

#endif