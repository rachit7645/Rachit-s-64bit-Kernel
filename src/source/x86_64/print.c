#include "print.h"
#include "convert_to_char.h"

Char* buffer = (Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
	Char empty = (Char) {
		character: ' ',
		color: color,
	};
	for (size_t col = 0; col < NUM_COLS; col++) {
		buffer[col + NUM_COLS * row] = empty;
	}
}

void clear_row_panic(size_t row, uint8_t color) {
	Char empty = (Char) {
		character: ' ',
		color: color,
	};
	for (size_t col = 0; col < NUM_COLS; col++) {
		buffer[col + NUM_COLS * row] = empty;
	}
}

void print_clear() {
	for (size_t i = 0; i < NUM_ROWS; i++) {
		clear_row(i);
	}
	col = 0;
	row = 0;
}

void print_clear_panic(uint8_t color) {
	for (size_t i = 0; i < NUM_ROWS; i++) {
		clear_row_panic(i, color);
	}
	col = 0;
	row = 0;
}

void print_newline() {
	col = 0;
	if (row < NUM_ROWS - 1) {
		row++;
		return;
	}
	for (size_t row = 1; row < NUM_ROWS; row++) {
		for (size_t col = 0; col < NUM_COLS; col++) {
			Char character = buffer[col + NUM_COLS * row];
			buffer[col + NUM_COLS * (row - 1)] = character;
		}
	}
	clear_row(NUM_ROWS - 1);
}

void print_char(char character) {
	if (character == '\n') {
		print_newline();
		return;
	}
	if (col > NUM_COLS) {
		print_newline();
	}
	buffer[col + NUM_COLS * row] = (Char) {
		character: (uint8_t) character,
		color: color,
	};
	col++;
}

void set_row(size_t set_row) {
	row = set_row;
}

void set_col(size_t set_col) {
	col = set_col;
}

void print_str(char* str) {
	for (size_t i = 0; 1; i++) {
		char character = (uint8_t) str[i];
		if (character == '\0') {
			return;
		}
		print_char(character);
	}
}

void print_short(uint16_t number) {
	print_str(short_to_char(number));
}

void print_int(uint32_t number) {
	print_str((int_to_char(number)));
}

void print_long(uint64_t number) {
	print_str(long_to_char(number));
}

void print_set_color(uint8_t foreground, uint8_t background) {
	color = foreground + (background << 4);
}

void print_terminal() {
	print_str("OSBETA>");
}

void clear_char() {
	if(!(col <= 7)) {
		buffer[(col - 1) + NUM_COLS * row] = (Char) {
			character: ' ',
			color: color
		};
		col--;
	}
}