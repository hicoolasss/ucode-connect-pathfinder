#include "pathfinder.h"

bridge *fill_indexes(struct bridge *bridges, char **temp, int V, int E) {
    
    struct bridge *temp_bridges = bridges;
    
    for (int i = 0; i < E; i++) {
        
        for (int j = 0; j < V; j++) {
            
            if (mx_strcmp(temp_bridges[i].island1, temp[j]) == 0) {
             
                temp_bridges[i].src = j;
            
            } else if (mx_strcmp(temp_bridges[i].island2, temp[j]) == 0) {

                temp_bridges[i].dest = j;
            
            }
        }
    }
    return temp_bridges;
}

