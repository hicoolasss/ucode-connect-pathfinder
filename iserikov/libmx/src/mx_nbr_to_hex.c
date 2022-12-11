#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr < 0 ) return 0;
    unsigned long int quotient = 0;
    int i = 0;
    int temp = 0;
    int count = 0;
    char temp_char;
    
    char *hexadecimalNumber = mx_strnew(100);
    quotient = nbr;
    while (quotient != 0) {
        temp = quotient % 16;
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 87;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    for (int i = 0; *(hexadecimalNumber + i) != '\0'; i++)
        count++;
    count--;
    for (i = 0; i < count; i++) {
        temp_char = hexadecimalNumber[i];
        hexadecimalNumber[i] = hexadecimalNumber[count];
        hexadecimalNumber[count] = temp_char;
        count--;
    }
    return hexadecimalNumber;
}
