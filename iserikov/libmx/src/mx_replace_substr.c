#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    size_t const rep_len = mx_strlen(replace);
    size_t const sub_len = mx_strlen(sub);
    size_t const str_len = mx_strlen(str);

    size_t patcnt = 0;
    const char *oriptr;
    const char *patloc;

    for (oriptr = str; (patloc = mx_strstr(oriptr, sub)); oriptr = patloc + sub_len) {
        patcnt++;
    }
        size_t const retlen = str_len + patcnt * (rep_len - sub_len);
        char *const returned = (char *)malloc(sizeof(char) * (retlen + 1));

        if (returned != NULL) {
            char *retptr = returned;
            for (oriptr = str; (patloc = mx_strstr(oriptr, sub)); oriptr = patloc + sub_len) {
                size_t const skplen = patloc - oriptr;
               
                mx_strncpy(retptr, oriptr, skplen);
                retptr += skplen;

                mx_strncpy(retptr, replace, rep_len);
                retptr += rep_len;
            }
            mx_strcpy(retptr, oriptr);
        }
        return returned;

}
