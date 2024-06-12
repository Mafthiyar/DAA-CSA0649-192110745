#include <stdio.h>
#include <limits.h>


int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}


int optimalBST(int keys[], int freq[], int n) {
   
    int cost[n][n];

   
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }


    for (int length = 2; length <= n; length++) { 
        
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            
          
            int totalFreq = sum(freq, i, j);

          
            for (int r = i; r <= j; r++) {
                int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + totalFreq;
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    printf("Enter the keys: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int optimal_cost = optimalBST(keys, freq, n);
    printf("Optimal cost: %d\n", optimal_cost);

    return 0;
}
