#include "pathfinder.h"

static char *remove_first_line(char *string) {

    int toBeRemoved = 0;

    mx_strncpy(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    mx_strncpy(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    return string;
}

bridge *init_bridge(char *filename) {

    char *string = mx_file_to_str(filename);

    string = remove_first_line(string);

    int count = mx_count_words(string, '\n');

    struct bridge *bridges = malloc((count) * sizeof(bridge));

    char **str = mx_strsplit(string, '\n');

    for (int i = 0; i < count; i++) {
        
        char **len = mx_strsplit(str[i], ',');
        char **island = mx_strsplit(len[0], '-');
        struct bridge temp = {island[0], 0, island[1], 0, mx_atoi(len[1])};
        
        bridges[i] = temp;
        for (int j = 0; j < 2; j++) {
            free(len[j]);
        }
        free(len);
    
        free(island);
    }

    free(string);

    for (int i = 0; i < count + 1; i++) {
        free(str[i]);
    }
    
    free(str);

    return bridges;
    
}








