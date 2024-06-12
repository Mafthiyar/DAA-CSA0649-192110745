#include <stdio.h>
#include <limits.h>


#define V 9


int minDistance(int dist[], int sptSet[]) {

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void dijkstra(int graph[V][V], int src) {
    int dist[V];    
    
    int sptSet[V];  
    
    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    
    
    dist[src] = 0;
    
  
    for (int count = 0; count < V - 1; count++) {
       
        int u = minDistance(dist, sptSet);
        
       
        sptSet[u] = 1;
        
       
        for (int v = 0; v < V; v++) {
            
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
 
    printf("Vertex   Optimal Cost from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


int main() {
    int graph[V][V];  
    int edges;        
    int u, v, w;      
    
   
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
   
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    
   
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  
    }
    
    
    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
  
    dijkstra(graph, src);
    
    return 0;
}

