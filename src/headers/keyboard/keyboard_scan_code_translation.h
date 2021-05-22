#pragma once

#include <stdint.h>
#include <stdbool.h>

#define LEFT_SHIFT  0x2A
#define RIGHT_SHIFT 0x36
#define ENTER       0x1C
#define BACK_SPACE  0x0E
#define SPACEBAR    0x39

extern const char ASCIITable[];
char translate(uint8_t scancode, bool uppercase);