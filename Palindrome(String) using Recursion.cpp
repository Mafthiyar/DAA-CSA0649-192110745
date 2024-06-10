#include <stdio.h>
#include <string.h>


int isPalindrome(char str[], int start, int end) {

    if (start >= end) {
        return 1; 
    }

    
    if (str[start] != str[end]) {
        return 0;
    }

    
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("\n Please Enter any String :  ");
    fgets(str, sizeof(str), stdin); 

    
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    int len = strlen(str);

    if (isPalindrome(str, 0, len - 1)) {
        printf("\n %s is a Palindrome String", str);
    } else {
        printf("\n %s is Not a Palindrome String", str);
    }

    return 0;
}
