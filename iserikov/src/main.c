#include "pathfinder.h"

static char *remove_first_line(char *string) {

    int toBeRemoved = 0;

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    mx_memmove(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string)-toBeRemoved);

    return string;
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) print_usage();
    
    char *string = mx_file_to_str(argv[1]);
    
    int number_of_islands = mx_atoi(&string[0]);

    string = remove_first_line(string);

    int number_of_bridges = mx_count_words(string, '\n');
    
    if (!is_file_exist(argv[1])) exit(1);
    if (!is_file_empty(argv[1])) exit(1);
    if (!check_first_line(argv[1])) exit(1);
    if (!check_lines(argv[1])) exit(1);
    
    struct bridge *bridges = init_bridge(argv[1]);
    
    if (!check_count_islands(bridges, argv[1])) exit(1);
    if (!check_duplicates(bridges, argv[1])) exit(1);
    if (!check_islands(bridges, argv[1])) exit(1);
    if (!check_max_int(bridges, argv[1])) exit(1);
    
    char **islands = init_islands(bridges, argv[1]);

    bridges = fill_indexes(bridges, islands, number_of_islands, number_of_bridges);
    
    int **Graph = makegraph(bridges, argv[1]);
    
    for(int i = 0; i < number_of_islands - 1; i++) {
    
        dijkstra(Graph, i, argv[1], bridges);
    }

    for (int i = 0; i < number_of_bridges; i++) {
    
        free(bridges[i].island1);
        free(bridges[i].island2);
    
    }

    for (int i = 0; i < number_of_islands; i++) {
    
        free(islands[i]);
        free(Graph[i]);
    
    }
    
    free(Graph);
    free(string);
    free(islands);
    free(bridges);
    
    return 0;
}
