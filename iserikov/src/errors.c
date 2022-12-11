#include "pathfinder.h"

static char *remove_first_line(char *string) {

    int toBeRemoved = 0;

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    return string;
}

void print_usage() {

    mx_printerr("usage: ./pathfinder [filename]\n");
    exit(1);
}

bool is_file_exist(char *filename) {
    
    int file = open(filename, O_RDONLY);
    
    if (file == -1) {

        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        return false;
        
    } else return true;
    
    close(file);
}

bool is_file_empty(char *filename) {

    char *temp = mx_file_to_str(filename);
    
    if (mx_strlen(temp) == 0) {

        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        free(temp);
        return false;

    } else {
        free(temp);
        return true;
    }
}

bool check_first_line(char *filename) {

    char *temp = mx_file_to_str(filename);
    
    int i = 0;
    
    while (temp[i] != '\n') {

        if (!mx_isdigit(temp[i])) {

        mx_printerr("error: line 1 is not valid\n");
        free(temp);
        return false;  

    } else if (temp[i] < 0) {

        mx_printerr("error: line 1 is not valid\n");
        free(temp);
        return false;

    } 

    i++;
    }
    
    free(temp);
    
    return true;
}

bool check_lines(char *filename) {
    
    char *temp = mx_file_to_str(filename);

    int count = mx_count_words(temp, '\n');
    
    int temp1 = 0;
    int temp2 = 0;
    
    char **array = mx_strsplit(temp, '\n');
    
    for (int i = 1; i < count; i++) {

           if (!mx_isalpha(array[i][0]) || !mx_isdigit(array[i][mx_strlen(array[i]) - 1])) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                free(temp);
                return false;
           }    
    }
    for (int i = 1; i < count; i++) {

        temp1 = 0;
        temp2 = 0;

        for (int j = 0; j < mx_strlen(array[i]); j++) {
            if (array[i][j] == '-')
                temp1++;

            if (array[i][j] == ',')
                temp2++;    
        }

            if (temp1 != 1 || temp2 != 1) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                free(temp);
                return false;
        }
    }
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }

    free(array);

    free(temp);
    
    return true;
}

bool check_islands(bridge *bridges, char *filename) {

    char *string = mx_file_to_str(filename);

    string = remove_first_line(string);
    
    int count = mx_count_words(string, '\n');

    for (int i = 0; i < count; i++) {
        
        if (mx_strcmp(bridges[i].island1, bridges[i].island2) == 0) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 2));
                mx_printerr(" is not valid\n");
                free(string);
                return false;
            }
        
        for (int j = 0; j < mx_strlen(bridges[i].island1); j++) {

            if (!mx_isalpha(bridges[i].island1[j])) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                free(string);
                return false;
            }
        }

        for (int j = 0; j < mx_strlen(bridges[i].island2); j++) {

            if (!mx_isalpha(bridges[i].island2[j])) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                free(string);
                return false;
            }
        }

    }
    free(string);
    return true;
    
}

bool check_duplicates(bridge *bridges, char *filename) {

    char *string = mx_file_to_str(filename);

    int size = mx_atoi(&string[0]);

    for (int i = 0; i < size - 1; i++) {

        for (int j = size - 1; j > 0; j--) {

           if((mx_strcmp(bridges[i].island1, bridges[j].island1) == 0) 
           && (mx_strcmp(bridges[i].island2, bridges[j].island2) == 0) 
           && (i != j)) {

            mx_printerr("error: duplicate bridges\n");
            free(string);
            return false;

           }

        }

    }
    free(string);

    return true;
}

bool check_max_int(bridge *bridges, char *filename) {

    char *string = mx_file_to_str(filename);

    string = remove_first_line(string);
    
    int count = mx_count_words(string, '\n');

    unsigned long int sum = 0;

    for (int i = 0; i < count; i++) {
        sum = sum + bridges[i].len;
    }
    
    if (sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        free(string);
        return false;
    }
    free(string);
    return true;
}

