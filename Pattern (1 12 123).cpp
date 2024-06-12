#include <stdio.h>

void printLine(int n) {
    
    if (n == 0) {
        return;
    }
    

    printLine(n - 1);
    printf("%d", n);
}

void printPattern(int n) {
    
    if (n == 0) {
        return;
    }
    
    
    printPattern(n - 1);
    
    
    printLine(n);
    printf("\n");
}

int main() {
    int lines;
    
    printf("Enter the number of lines: ");
    scanf("%d", &lines);
    
    
    printPattern(lines);
    
    return 0;
}
