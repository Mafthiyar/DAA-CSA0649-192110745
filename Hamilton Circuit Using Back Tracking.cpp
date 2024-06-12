#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int numVertices;


bool isSafe(int v, int pos, int path[]) {
  
    if (graph[path[pos - 1]][v] == 0)
        return false;

   
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}


bool hamiltonianCycleUtil(int path[], int pos) {
    
    if (pos == numVertices) {
     
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

  
    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;

    
            if (hamiltonianCycleUtil(path, pos + 1))
                return true;

       
            path[pos] = -1;
        }
    }

    return false;
}


void hamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    
    for (int i = 0; i < numVertices; i++)
        path[i] = -1;

   
    path[0] = 0;

    if (!hamiltonianCycleUtil(path, 1)) {
        printf("No Hamiltonian Circuit found\n");
        return;
    }


    printf("Hamiltonian Circuit found:\n");
    for (int i = 0; i < numVertices; i++)
        printf("%d -> ", path[i] + 1);
    printf("%d\n", path[0] + 1); 
}

int main() {
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

   
    printf("Enter the adjacency matrix for the graph (0 or 1):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    
    hamiltonianCycle(graph, numVertices);

    return 0;
}
