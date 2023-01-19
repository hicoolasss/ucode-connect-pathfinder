#include "../inc/libmx.h"

void mx_printchar(char c);

void mx_printint(int n) {
    int count = 0;
    if (n == 0)
        mx_printchar(48);
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    int temp = n;
    while (n != 0) {
        n = n / 10;
        count++;
    }
    char array[count];
    for (int i = 0; i < count; i++) {
        array[i] = temp % 10 + 48;
        temp /= 10;
    }
    for (int i = count - 1; i >= 0; i--)
        mx_printchar(array[i]);
}
