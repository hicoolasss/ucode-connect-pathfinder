#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL && sub == NULL) return -1;
    if (sub == NULL) return 0;
    if (str == NULL || sub == NULL) return -1;

    int count = 0;

    int len1 = mx_strlen(str);
    int len2 = mx_strlen(sub);

    const char *tmp1 = str;
    const char *tmp2 = sub;
    
    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (mx_strstr(tmp1 + i, tmp2) == tmp1 + i) {
            count++;
            i = i + len2 - 1;
        }
    }
    return count;
}
