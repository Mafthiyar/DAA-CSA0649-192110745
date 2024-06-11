#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


struct Edge {
    int source, destination, weight;
};


struct Graph {
    int V, E;           
    struct Edge* edges; 
};


struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}


void addEdge(struct Graph* graph, int index, int source, int destination, int weight) {
    graph->edges[index].source = source;
    graph->edges[index].destination = destination;
    graph->edges[index].weight = weight;
}


void printMST(int parent[], struct Graph* graph) {
    printf("Edge   Weight\n");
    for (int i = 1; i < graph->V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph->edges[parent[i]].weight);
}


int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


void primMST(struct Graph* graph) {
    int V = graph->V;
    int parent[V];    
    int key[V];        
    bool mstSet[V];    

   
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;       
    parent[0] = -1;   

   
    for (int count = 0; count < V - 1; count++) {
       
        int u = minKey(key, mstSet, V);

     
        mstSet[u] = true;

        
        for (int v = 0; v < V; v++)
       
            if (graph->edges[u * V + v].weight && mstSet[v] == false && graph->edges[u * V + v].weight < key[v])
                parent[v] = u, key[v] = graph->edges[u * V + v].weight;
    }

   
    printMST(parent, graph);
}


int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges with weights (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        addEdge(graph, i, source, destination, weight);
    }

  
    printf("Minimum Spanning Tree using Prim's algorithm:\n");
    primMST(graph);

    return 0;
}
