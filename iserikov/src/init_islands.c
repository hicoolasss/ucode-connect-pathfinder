#include "pathfinder.h"

static char *remove_first_line(char *string) {

    int toBeRemoved = 0;

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string) - toBeRemoved);

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string) - toBeRemoved);

    return string;
}

char **init_islands(bridge *bridges, char *filename) {

    char *string = mx_file_to_str(filename);

    int size = mx_atoi(&string[0]);

    int write_to = 0;

    string = remove_first_line(string);

    int count = mx_count_words(string, '\n');

    char **temp = malloc((size) * sizeof(char *));

    for (int i = 0; i < (size); i++) {
        
        temp[i] = malloc(128 * sizeof(char));
    }

    for (int i = 0; i < count; i++) {

        bool find = false;

        for (int a = 0; a < write_to; a++) {

            if (mx_strcmp(temp[a], bridges[i].island1) == 0) {

                find = true;
                break;
            }
        }

        if (!find) {

            mx_strcpy(temp[write_to], bridges[i].island1);
            write_to++;
        }

        if (write_to > size) {
            mx_printerr("error: invalid number of islands\n");
        }
        
        find = false;

        for (int a = 0; a < write_to; a++) {

            if (mx_strcmp(temp[a], bridges[i].island2) == 0) {

                find = true;
                break;
            }
        }

        if (!find) {

            mx_strcpy(temp[write_to], bridges[i].island2);
            write_to++;
        }
        
        if (write_to > size) {
            
            mx_printerr("error: invalid number of islands\n");
        }
    }

    if (write_to == size - 1) {

        mx_printerr("error: invalid number of islands\n");
    }

    free(string);
    
    return temp;
}
