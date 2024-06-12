#include <stdio.h>
#include <stdlib.h>

static int total_nodes;

void printValues(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%*d", 5, A[i]);
    }
    printf("\n");
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
    total_nodes++;
    if (target_sum == sum) {
        printValues(t, t_size);
        subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    } else {
        for (int i = ite; i < s_size; i++) {
            t[t_size] = s[i];
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int* tuplet_vector = (int*)malloc(size * sizeof(int));
    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    free(tuplet_vector);
}

int main() {
    int size, target_sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &size);

    int* set = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the set: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    printf("The set is ");
    printValues(set, size);

    printf("Subsets with the target sum %d are:\n", target_sum);
    generateSubsets(set, size, target_sum);
    
    printf("Total Nodes generated: %d\n", total_nodes);

    free(set);
    return 0;
}
