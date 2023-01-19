#include "pathfinder.h"

static char *remove_first_line(char *string) {

    int toBeRemoved = 0;

    mx_strncpy(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string) - toBeRemoved);

    mx_strncpy(&string[toBeRemoved], &string[toBeRemoved + 1], mx_strlen(string) - toBeRemoved);

    return string;
}

static int minimumDistance(int *distance, bool *visited, int size) {

    int min = INT_MAX;
    int min_index = INT_MAX;
    
    for (int i = 0; i < size; i++) {
        
        if (!visited[i] && distance[i] < min) {
            
            min = distance[i];
            
            min_index = i;
        
        }
    
    }
    
    return min_index;
}

void create_adj_matrix(int **Adj, int **arr, int N, int M, struct bridge *bridges)
{
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            
            Adj[i][j] = 0;
        
        }
    
    }
    
    for (int i = 0; i < M; i++) {
        
        int x = arr[i][0];
        int y = arr[i][1];

        Adj[x][y] = bridges[i].len;
        Adj[y][x] = bridges[i].len;
    
    }

}

int **makegraph(bridge *bridges, char *filename)
{
    char *string = mx_file_to_str(filename);

    int size = mx_atoi(&string[0]);

    string = remove_first_line(string);

    int count = mx_count_words(string, '\n');

    int k = 0;

    int **temp = malloc(count * sizeof(int *));

    for (int i = 0; i < count; i++) {
        
        temp[i] = malloc(2 * sizeof(int));
    
    }

    int **graph = malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        
        graph[i] = malloc(size * sizeof(int));
    
    }

    int *index = malloc((count * 2) * sizeof(int));

    for (int i = 0; i < count * 2; i++) {
        
        for (int j = 0; j < count; j++) {

            
            index[i] = bridges[j].src;
            
            i++;
            
            index[i] = bridges[j].dest;
            
            i++;
        
        }
    
    }

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < 2; j++) {
            
            temp[i][j] = index[k];
            
            k++;
        
        }
    
    }

    create_adj_matrix(graph, temp, size, count, bridges);

    for (int i = 0; i < count; i++) {
    
        free(temp[i]);
    
    }
    
    free(temp);
    free(index);
    free(string);

    return graph;

}

void clear_list(t_list **list)
{
    t_list *current = *list;
    t_list *next = NULL;

    while (current != NULL) {
        
        next = current->next;
        
        free(current);
        
        current = next;
    
    }
    
    *list = NULL;

}


void dijkstra(int **graph, int src, char *filename, struct bridge *bridges)
{
    
    char *string = mx_file_to_str(filename);

    int size = mx_atoi(&string[0]);
    int count = 0;

    int *distance = malloc(size * size * sizeof(int));
    int *dup_parent = malloc(size * size * sizeof(int));

    string = remove_first_line(string);

    char **islands = init_islands(bridges, filename);

    bool *visited = malloc(size * sizeof(bool));
    
    t_list **parent = malloc(size * sizeof(t_list *));
    
    for (int i = 0; i < size; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = mx_create_node((void *)&src);
        visited[i] = false;
    }

    distance[src] = 0;

    for (int i = 0; i < size - 1; i++)
    {
        
        int U = minimumDistance(distance, visited, size);
        
        visited[U] = true;
        
        for (int j = 0; j < size; j++)
        {
        
            if (!visited[j] && graph[U][j] && distance[U] + graph[U][j] < distance[j]) {
                
                dup_parent[count] = U;
                
                distance[j] = distance[U] + graph[U][j];
                
                clear_list(&parent[j]);
                
                mx_push_back(&parent[j], (void *)&dup_parent[count++]);
            
            }
    
            else if (!visited[j] && graph[U][j] && distance[U] + graph[U][j] == distance[j]) {
                
                dup_parent[count] = U;
                
                mx_push_back(&parent[j], (void *)&dup_parent[count++]);
            
            }
        
        }
    
    }
    
    print_all(distance, src, size, graph, islands, parent);
    
    for (int i = 0; i < size; i++) {
        
        clear_list(&parent[i]);
        
        free(islands[i]);
    
    }
    
    free(distance);
    free(parent);
    free(dup_parent);
    free(visited);
    free(islands);
    free(string);
}
