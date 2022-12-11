#include "pathfinder.h"

void clear_list_w_data(t_list **list) {
    
    t_list *current = *list;
    t_list *next = NULL;

    while (current != NULL) {
        
        next = current->next;
        
        free(current->data);
        free(current);
        
        current = next;
    
    }
    
    *list = NULL;

}

bool cmp(void *a, void *b) {
    
    int *islands1 = (int *)a;
    int *islands2 = (int *)b;
    int i = 0;
    
    while (islands1[i] != -1 && islands2[i] != -1) {
        
        if (islands1[i] != islands2[i]) {
        
            return islands1[i] > islands2[i];
        
        }
        
        i++;
    
    }
    
    return islands1[i] > islands2[i];

}

void get_index(t_list **paths, t_list **parent, char **islands, int *buf, int index, const int cur, int src) {
    
    if (cur == src) {
        
        int i = 0;
        int j = 0;
        int *arr = malloc(index * sizeof(int));
        
        buf[index++] = src;
        
        for (i = index - 2; i >= 0; i--) {
            
            arr[j++] = buf[i];
        
        }
        
        mx_push_back(&paths[buf[1]], arr);
    
    } else {
        
        for (t_list *temp = parent[cur]; temp; temp = temp->next) {
           
            buf[index++] = *(int *)temp->data;
            
            get_index(paths, parent, islands, buf, index, *(int *)temp->data, src);
            
            index--;
        
        }
    
    }

}

void *find_island(char **islands, int i, int size) {
    
    for (int j = 0; j < size; j++) {
        
        if (i == j) {
           
            return islands[j];

        }
    
    }
    
    return NULL;

}

void print_distance(int **graph, int *index, int dist) {
    
    int count = 0;
    int i = 0;
    int j = 1;
    
    mx_printint(graph[index[i++]][index[j++]]);
    
    while (index[j] != -1) {
        
        mx_printstr(" + ");
        mx_printint(graph[index[i]][index[j]]);
        
        i++, j++, count++;
    
    }
    
    if (count != 0) {
        
        mx_printstr(" = ");
        mx_printint(dist);
    
    }
    
    mx_printstr("\n");

}

void print_route(char **islands, int *path, int size) {
    
    int j = 0;
    while (path[j + 1] != -1) {
        
        mx_printstr(find_island(islands, path[j], size));
        mx_printstr(" -> ");
        
        j++;
    
    }
    
    mx_printstr(find_island(islands, path[j], size));
}

void print_path(char **islands, int *path, int dest, int size) {
    
    mx_printstr(find_island(islands, path[0], size));
    mx_printstr(" -> ");
    mx_printstr(find_island(islands, path[dest], size));

}

void print_all(int *distance, int src, int size, int **graph, char **islands, t_list **parent) {
    
    int j = 0;

    int *numbers = malloc(size * size * sizeof(int));

    t_list **paths = malloc((size + 1) * sizeof(t_list *));
    
    for (int i = 0; i < size; i++) {
        
        paths[i] = mx_create_node(malloc(sizeof(int)));
    
    }
    
    paths[size] = NULL;
    
    for (int i = 0; i < size; i++) {
        
        if (i != src) {
            
            numbers[0] = -1;
            numbers[1] = i;
            
            get_index(paths, parent, islands, numbers, 2, i, src);
            
            free(paths[i]->data);
            
            mx_pop_front(&paths[i]);
        
        }
    
    }

    for (int i = 1; paths[i]; i++) {
        
        if (i != src) {
            
            mx_sort_list(paths[i], cmp);
            
            for (t_list *path = paths[i]; path; path = path->next) {
                
                int *routes = path->data;
                
                for (j = 0; routes[j + 1] != -1; j++);
                
                if (routes[j] > src) {
                    
                    mx_printstr("========================================");
                    
                    mx_printstr("\n");
                    mx_printstr("Path: ");
                    
                    print_path(islands, routes, j, size);
                    
                    mx_printstr("\n");
                    mx_printstr("Routes: ");
                    
                    print_route(islands, routes, size);
                    
                    mx_printstr("\n");
                    mx_printstr("Distance: ");
                    
                    print_distance(graph, routes, distance[i]);
                    
                    mx_printstr("========================================");
                    mx_printstr("\n");
                
                }
            
            }
        
        }
    
    }
    
    free(numbers);
    
    for (int i = 0; i < size; i++) {
       
       clear_list_w_data(&paths[i]);
    
    }
    
    free(paths);
    
}
