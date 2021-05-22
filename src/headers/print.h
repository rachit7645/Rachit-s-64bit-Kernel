#pragma once

#include <stdint.h>
#include <stddef.h>

// All the colors supported in text mode
enum display_colors {
    PRINT_COLOR_BLACK = 0,
	PRINT_COLOR_BLUE = 1,
	PRINT_COLOR_GREEN = 2,
	PRINT_COLOR_CYAN = 3,
	PRINT_COLOR_RED = 4,
	PRINT_COLOR_MAGENTA = 5,
	PRINT_COLOR_BROWN = 6,
	PRINT_COLOR_LIGHT_GRAY = 7,
	PRINT_COLOR_DARK_GRAY = 8,
	PRINT_COLOR_LIGHT_BLUE = 9,
	PRINT_COLOR_LIGHT_GREEN = 10,
	PRINT_COLOR_LIGHT_CYAN = 11,
	PRINT_COLOR_LIGHT_RED = 12,
	PRINT_COLOR_PINK = 13,
	PRINT_COLOR_YELLOW = 14,
	PRINT_COLOR_WHITE = 15,
};

static const size_t NUM_COLS = 80;      // In GRUB text mode there are 80 cols and
static const size_t NUM_ROWS = 25;      // 25 rows

struct Char {
    uint8_t character;
    uint8_t color;
};
typedef struct Char Char;		// Character type 

// Prototypes

void print_clear();
void print_char(char character);
void print_str(char* string);
void print_long(long number);
void print_set_color(uint8_t foreground, uint8_t background);
void print_newline();
void print_terminal();
void clear_char();