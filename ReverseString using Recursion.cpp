#include <stdio.h>
#include <string.h>

void stringReverse(char *Str)
{	
	if(*Str)
	{
		stringReverse(Str + 1);
		printf("%c", *Str);
	}
}
 
int main()
{
  	char Str[100];
 
  	printf("Please Enter any String to Reverse =  ");
  	fgets(Str, sizeof Str, stdin);
 
  	printf("\nString after Reversing = ");
	stringReverse(Str);
	printf("\n");
}
