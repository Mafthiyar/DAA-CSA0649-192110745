#include <stdio.h>
 
void recur(char [], char [], int);
 
int main()
{
    char str[30], str1[30];
 
    printf("Enter The String: ");
    scanf("%[^\n]s", str);
    recur(str, str1, 0);
    printf("Executed Successfully\n");
    printf("The input String: %s\n", str);
    printf("The Copied String: %s\n", str1);
    return 0;
}
 
void recur(char str[], char str1[], int index)
{
    str1[index] = str[index];
    if (str[index] == '\0')
        return;
    recur(str, str1, index + 1);
}
