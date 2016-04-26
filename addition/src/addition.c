/* 
	Addition
	
	Simple addition program

	Joacim Eriksson
	2016-04-01
*/
#include <stdio.h>

int main(void) 
{
	/* Declare three integer variables */
	int Integer1, Integer2, Sum;

	/* Instruct the user to enter the first integer. */
	printf("Enter first integer\n");
	/* Scan only digits and assign it to the first integer variable */
	scanf("%d", &Integer1);
	/* Instruct the user to enter the second integer */
	printf("Enter second integer\n");
	/* Scan only digits and assign it to the second integer variable */
	scanf("%d", &Integer2);
	/* Calculate the sum of the two integers */
	Sum = Integer1 + Integer2;
	/* Print the sum */
	printf("Sum is %d\n", Sum);
	/* The program ran without any problems */
	return 0;
}

