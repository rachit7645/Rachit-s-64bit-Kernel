#include "utils.h"
#include "print.h"

// Write a byte out to the specified port.
inline void outb(uint16_t port, uint8_t value) {
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

inline uint16_t inw(uint16_t port) {
    uint16_t ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

// Copy len bytes from src to dest.
void memcpy(uint8_t* dest, const uint8_t* src, uint32_t len) {
    const uint8_t *sp = (const uint8_t*)src;
    uint8_t *dp = (uint8_t*)dest;
    for(; len != 0; len--) *dp++ = *sp++;
}

// Write len copies of val into dest.
void memset(uint8_t *dest, uint8_t val, uint32_t len) {
    uint8_t* temp = (uint8_t*)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

// Compare two strings, return true if they are same or false if they are not same
bool strcmp(char* first_string, char* second_string) {
    size_t i = 0;
    bool result = false;

    while(first_string[i] != '\0' && second_string[i] != '\0') {
        if(first_string[i] != second_string[i]) 
            return result = false;
        i++;
    }

    if(!result) 
        result = true;    
    
    return result;
}

// Copy the NULL-terminated string src into dest, and
// return dest.
char* strcpy(char* dest, const char* src) {
    do
    {
      *dest++ = *src++;
    }
    while(*src != 0);
    return dest;
}

// Concatenate the NULL-terminated string src onto
// the end of dest, and return dest.
char* strcat(char* dest, const char* src) {
    while (*dest != 0)
    {
        *dest = *dest++;
    }

    do
    {
        *dest++ = *src++;
    }
    while (*src != 0);
    return dest;
}
