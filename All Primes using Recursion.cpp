#include <stdio.h>
#include <stdbool.h>


bool isPrime(int n, int i) {
    // Base cases
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;

 
    return isPrime(n, i + 1);
}


void printPrimes(int n, int current) {
    if (current > n)
        return;

    if (isPrime(current, 2))
        printf("%d ", current);

    printPrimes(n, current + 1);
}

int main() {
    int n;
    printf("Enter the limit up to which you want to print prime numbers: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d are: ", n);
    printPrimes(n, 2);  
    printf("\n");

    return 0;
}
