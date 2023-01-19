#pragma once
#include "libmx.h"
#define INT_MAX 2147483647
#include <stdbool.h>

typedef struct bridge {
    char *island1;
    int src;
    char *island2;
    int dest;
    int len;
} bridge;

void print_usage();
void clear_list_w_data(t_list **list);
void clear_list(t_list **list);
void *find_island(char **islands, int i, int size);
void dijkstra(int **graph, int src, char *filename, struct bridge *bridges);
void create_adj_matrix(int **Adj, int **arr, int N, int M, struct bridge *bridges);
void get_index(t_list **paths, t_list **parent, char **islands, int *buf, int index, const int cur, int src);
void print_distance(int **graph, int *index, int dist);
void print_route(char **islands, int *path, int size);
void print_path(char **islands, int *path, int dest, int size);
void print_all(int *distance, int startnode, int n, int **matrix, char **islands, t_list **pred_lists);
int **makegraph(bridge *bridges, char *filename);
char **init_islands(bridge *bridges, char *filename);
bool check_count_islands(bridge *bridges, char *filename);
bool is_file_empty(char *filename);
bool check_first_line(char *filename);
bool check_lines(char *filename);
bool check_duplicates(bridge *bridges, char *filename);
bool check_islands(bridge *bridges, char *filename);
bool check_max_int(bridge *bridges, char *filename);
bool cmp(void *a, void *b);

bridge *init_bridge(char *filename);
bridge *find_routes(bridge *bridges, char *filename);
bridge *fill_indexes(struct bridge *bridges, char **temp, int V, int E);
