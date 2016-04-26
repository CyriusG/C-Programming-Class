/* 
	If Statements
	
	Enter two integers and print different text depending
	on the sum of the two integers.

	Joacim Eriksson
	2016-04-01
*/
#include <stdio.h>

int main() 
{
	int Integer1, Integer2;
	
	/* Read two integers and store them in variables. */
	printf("Enter two integers separated by a space.\n");
	scanf("%d %d", &Integer1, &Integer2);
	
	/* If Integer1 and Integer 2 are equal. */
	if(Integer1 == Integer2)
	{
		printf("%d and %d are equal.\n", Integer1, Integer2);
	}
	
	/* If Integer1 and Integer2 are not equal. */
	if(Integer1 != Integer2)
	{
		printf("%d and %d are not equal.\n", Integer1, Integer2);
	}
	
	/* If Integer1 is larger than Integer2. */
	if(Integer1 > Integer2) 
	{
		printf("%d is larger than %d.\n", Integer1, Integer2);
	}

	/* If Integer1 is smaller than Integer2. */
	if(Integer1 < Integer2) 
	{
			printf("%d is smaller than %d.\n", Integer1, Integer2);
	}

	return 0;
}
