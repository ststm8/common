#ifndef __rgb_h__
#define __rgb_h__

#include <types.h>

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB_t;

#define RGB(R, G, B)           \
    {                          \
        .r = R, .g = G, .b = B \
    }

#endif