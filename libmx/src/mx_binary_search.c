#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
        int l = 0;
        int r = size - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            *count += 1;
            if (mx_strcmp(arr[m], s) == 0) {
                return m;
            }
            if (mx_strcmp(arr[m], s) > 0)
                r = m - 1;
            else 
                l = m + 1;
        }
        *count = 0;
        return -1;
}
