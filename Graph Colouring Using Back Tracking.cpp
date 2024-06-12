#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define numOfVertices 4


typedef struct {
    char name;
    bool colored;
    int color;
} Vertex;


int graph[numOfVertices][numOfVertices];


char colors[][30] = {"Green", "Blue"};
int color_used = 2;


Vertex *vertexArray[numOfVertices];


int hasUncoloredNeighbours(int idx) {
    for (int i = 0; i < numOfVertices; i++) {
        if (graph[idx][i] == 1 && vertexArray[i]->colored == false)
            return i;
    }
    return -1;
}


bool canColorWith(int colorIndex, int vertex) {
    Vertex *neighborVertex;
    for (int i = 0; i < numOfVertices; i++) {
        if (graph[vertex][i] == 0) continue; 
        neighborVertex = vertexArray[i];
        if (neighborVertex->colored && neighborVertex->color == colorIndex)
            return false;
    }
    return true;
}


bool setColors(int idx) {
    int colorIndex, unColoredIdx;

    
    for (colorIndex = 0; colorIndex < color_used; colorIndex++) {
        
        if (!canColorWith(colorIndex, idx)) continue;

    
        vertexArray[idx]->color = colorIndex;
        vertexArray[idx]->colored = true;

        
        int colorCount = 0;
        for (int i = 0; i < numOfVertices; i++) {
            if (vertexArray[i]->colored) colorCount++;
        }

       
        if (colorCount == numOfVertices)
            return true;

       
        while ((unColoredIdx = hasUncoloredNeighbours(idx)) != -1) {
            if (setColors(unColoredIdx))
                return true;
        }
    }

   
    vertexArray[idx]->color = -1;
    vertexArray[idx]->colored = false;
    return false;
}

int main() {
   
    printf("Enter the adjacency matrix for the graph (0 or 1):\n");
    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

  
    Vertex vertexA, vertexB, vertexC, vertexD;
    vertexA.name = 'A';
    vertexB.name = 'B';
    vertexC.name = 'C';
    vertexD.name = 'D';

    vertexArray[0] = &vertexA;
    vertexArray[1] = &vertexB;
    vertexArray[2] = &vertexC;
    vertexArray[3] = &vertexD;

   
    for (int i = 0; i < numOfVertices; i++) {
        vertexArray[i]->colored = false;
        vertexArray[i]->color = -1;
    }

    
    bool hasSolution = setColors(0);

  
    if (!hasSolution) {
        printf("No Solution\n");
    } else {
        printf("Vertex Coloring Solution:\n");
        for (int i = 0; i < numOfVertices; i++) {
            printf("%c: %s\n", vertexArray[i]->name, colors[vertexArray[i]->color]);
        }
    }

    return 0;
}
