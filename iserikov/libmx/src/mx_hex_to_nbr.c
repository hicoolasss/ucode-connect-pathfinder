#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;
    int size = 0;
    unsigned long long int res = 0;
    while (hex[size] != '\0')
        size++;
    size--;
    unsigned long int hex_count = 1;
    for (int i = size; i >= 0; i--) {
        if (mx_isalpha(hex[i]) == 1) {
            if (mx_islower(hex[i]) == 1)
                res += (hex[i] - 87) * hex_count;
            if (mx_isupper(hex[i]) == 1)
                res += (hex[i] - 55) * hex_count;
        }
        if (mx_isdigit(hex[i]) == 1)
            res += (hex[i] - 48) * hex_count;
        hex_count *= 16;
    }
    return res;
}
