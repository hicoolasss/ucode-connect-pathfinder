#include "pathfinder.h"

static char *remove_first_line(char *string) {

    int toBeRemoved = 0;

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    return string;
}

bool check_count_islands(bridge *bridges, char *filename) {

    char *string = mx_file_to_str(filename);
    
    int size = mx_atoi(&string[0]);

    string = remove_first_line(string);

    int count = mx_count_words(string, '\n');

    int full_size = count * 2;

    char **island1 = malloc((count) * sizeof(char *));

    for(int i = 0; i < (count); i++) {
        island1[i] = malloc(128 * sizeof(char));
    }

    char **island2 = malloc((count) * sizeof(char *));

    for(int i = 0; i < (count); i++) {
        island2[i] = malloc(128 * sizeof(char));
    }

    char **islands = malloc((full_size) * sizeof(char *));

    for(int i = 0; i < (full_size); i++) {
        islands[i] = malloc(128 * sizeof(char));
    }

    for (int i = 0; i < count; i++) {
            mx_strcpy(island1[i], bridges[i].island1);
            mx_strcpy(island2[i], bridges[i].island2);
    }

    for (int i = 0; i < count; i++) {
        mx_strcpy(islands[i], island1[i]);
    }

    for (int j = 0; j < count; j++) {
        mx_strcpy(islands[count + j], island2[j]);
    }

    int j = 0;

    for (int i = 0; i < full_size; i ++) {
        
        j = i + 1;
        
        while (j < full_size) {
        
            if (strcmp(islands[i], islands[j]) == 0) {
        
                mx_strncpy(*(islands + j), *(islands + ((full_size) - 1)), sizeof(islands[0]));
        
                (full_size)--;
            } else {
                j++;
            }
        }
    }

    free(string);

    for (int i = 0; i < count; i++) {
        free(island1[i]);
    }
    
    free(island1);

    for (int i = 0; i < count; i++) {
        free(island2[i]);
    }
    
    free(island2);

    for (int i = 0; i < count * 2; i++) {
        free(islands[i]);
    }
    
    free(islands);
    
    if (size != full_size) {
        mx_printerr("error: invalid number of islands\n");
        return false;
    } else {
        return true;
    }

}
