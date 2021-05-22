#include "convert_to_char.h"
#include <stddef.h>

char* long_to_char(long number) {
    char* str; 
    size_t i = 0;

    while(number != 0) {
        long temp = number % 10;
        switch(temp) {
            case 0:
                str[i] = '0';
                break;
            case 1:
                str[i] = '1';
                break;
            case 2:
                str[i] = '2';
                break;
            case 3:
                str[i] = '3';
                break;
            case 4:
                str[i] = '4';
                break;
            case 5:
                str[i] = '5';
                break;
            case 6:
                str[i] = '6';
                break;
            case 7:
                str[i] = '7';
                break;
            case 8:
                str[i] = '8';
                break;
            case 9:
                str[i] = '9';
                break;
        }
        i++;
        number /= 10; 
    }

    return str;
}