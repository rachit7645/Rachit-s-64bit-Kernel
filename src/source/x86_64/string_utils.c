#include "string_utils.h"
#include "utils.h"
#include "print.h"

char* strrev(char* string) {
    size_t i;
    size_t count = strlen(string);
    size_t j = count - 2;
    
    char* reverse = 0;

    for (i = 0; i < count; i++) {
        reverse[i] = string[j];
        j--;
    }

    return reverse;

}

size_t strlen(char* string) {
    size_t i = 0;

    while(string[i] != '\0')
        i++;

    return i + 1;
}