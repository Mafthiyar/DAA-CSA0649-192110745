#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_JOBS 100


typedef struct node {
    int job_number;
    int worker_number;
    struct node* parent;
    int cost;
} Node;


typedef struct priority_queue {
    Node* array[MAX_JOBS * MAX_JOBS]; 
    int size;
} PriorityQueue;


PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}


void swap(Node** x, Node** y) {
    Node* temp = *x;
    *x = *y;
    *y = temp;
}


void minHeapify(PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->array[left]->cost < pq->array[smallest]->cost)
        smallest = left;

    if (right < pq->size && pq->array[right]->cost < pq->array[smallest]->cost)
        smallest = right;

    if (smallest != i) {
        swap(&pq->array[i], &pq->array[smallest]);
        minHeapify(pq, smallest);
    }
}


Node* extractMin(PriorityQueue* pq) {
    if (pq->size == 0)
        return NULL;

    Node* root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return root;
}


void addToPriorityQueue(PriorityQueue* pq, Node* node) {
    pq->array[pq->size] = node;
    pq->size++;
    int i = pq->size - 1;
    while (i > 0 && pq->array[(i - 1) / 2]->cost > pq->array[i]->cost) {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void printSolution(Node* solution) {
    printf("Optimal Cost: %d\n", solution->cost);
    printf("Job Assignments:\n");
    while (solution != NULL) {
        printf("Job %d -> Worker %d\n", solution->job_number, solution->worker_number);
        solution = solution->parent;
    }
}


void findMinCost(int costMatrix[MAX_JOBS][MAX_JOBS], int n) {
    PriorityQueue* pq = createPriorityQueue();

   
    Node* root = (Node*)malloc(sizeof(Node));
    root->job_number = -1;
    root->worker_number = -1;
    root->parent = NULL;
    root->cost = 0;

    addToPriorityQueue(pq, root);

    while (1) {
       
        Node* E = extractMin(pq);

 
        if (E->job_number == n - 1) {
            printSolution(E);
            return;
        }

    
        for (int i = 0; i < n; i++) {
           
            if (costMatrix[E->job_number + 1][i] == -1)
                continue;

            Node* child = (Node*)malloc(sizeof(Node));
            child->job_number = E->job_number + 1;
            child->worker_number = i;
            child->parent = E;
            child->cost = E->cost + costMatrix[E->job_number + 1][i];

            addToPriorityQueue(pq, child);
        }
    }
}


int main() {
    int n;


    printf("Enter number of jobs (n): ");
    scanf("%d", &n);

    int costMatrix[MAX_JOBS][MAX_JOBS];

    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }


    findMinCost(costMatrix, n);

    return 0;
}
