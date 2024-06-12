#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 9999

int n;
int **distan;
int **DP;

int TSP(int mark, int position);

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    
    distan = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        distan[i] = (int *)malloc(n * sizeof(int));
    }

    
    printf("Enter the distance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &distan[i][j]);
        }
    }

    
    DP = (int **)malloc((1 << n) * sizeof(int *));
    for (int i = 0; i < (1 << n); i++) {
        DP[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            DP[i][j] = -1;
        }
    }


    int shortestDistance = TSP(1, 0);

    
    printf("Minimum Distance Travelled -> %d\n", shortestDistance);


    for (int i = 0; i < n; i++) {
        free(distan[i]);
    }
    free(distan);

    for (int i = 0; i < (1 << n); i++) {
        free(DP[i]);
    }
    free(DP);

    return 0;
}

int TSP(int mark, int position) {
    int completed_visit = (1 << n) - 1;
    if (mark == completed_visit) {
        return distan[position][0];
    }
    if (DP[mark][position] != -1) {
        return DP[mark][position];
    }
    int answer = MAX;
    for (int city = 0; city < n; city++) {
        if ((mark & (1 << city)) == 0) {
            int newAnswer = distan[position][city] + TSP(mark | (1 << city), city);
            answer = (answer < newAnswer) ? answer : newAnswer;
        }
    }
    return DP[mark][position] = answer;
}
