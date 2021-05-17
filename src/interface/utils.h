#pragma once

#include <stdint.h>
#include <stddef.h>

// Input and output functions

void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);

// Memory allocation functions

void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);
void memset(uint8_t *dest, uint8_t val, uint32_t len);

// String functions

int strcmp(char *str1, char *str2);
char* strcpy(char *dest, const char *src);
char* strcat(char *dest, const char *src);