#pragma once

#include <stdint.h>

#define KEYBOARD_DATA_PORT  0x60

void handle_keyboard(uint8_t scancode);