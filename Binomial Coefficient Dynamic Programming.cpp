#include <stdio.h>


unsigned int recursiveBinomialCoefficientMethod(int n, int k) {
    if (k == n || k == 0)
        return 1;
    return (recursiveBinomialCoefficientMethod(n - 1, k - 1) + recursiveBinomialCoefficientMethod(n - 1, k));
}

int main() {
    unsigned int valueOfN, valueOfK;
    printf("\nEnter the value of n: ");
    scanf("%u", &valueOfN);
    printf("\nEnter the value of k: ");
    scanf("%u", &valueOfK);
    printf("Value of C(%u, %u): %u\n", valueOfN, valueOfK, recursiveBinomialCoefficientMethod(valueOfN, valueOfK));
    return 0;
}
