/* 
 * integercomparison
 *	
 * Asks the user for two integers and prints out which of the two is larger
 * than the other, if they are equal print that they are equal.
 *
 * Joacim Eriksson
 * 2016-04-03
*/
#include <stdio.h>

int main() 
{
	/* Declare two integers */
	int Integer1, Integer2;

	/* Ask the user for two integers and put them into variables */
	printf("Enter two integers.\n");	
	scanf("%d%d", &Integer1, &Integer2);
	
	/* If Integer1 is larger than Integer2 */
	if (Integer1 > Integer2) 
	{
		printf("%d is larger than %d.\n", Integer1, Integer2);
	}	
	/* If Integer2 is larger than Integer1 */
	if (Integer2 > Integer1) 
	{
		printf("%d is larger than %d.\n", Integer2, Integer1);
	}
	/* If the two integers are equal */
	if (Integer1 == Integer2) 
	{
		printf("%d is equal to %d.\n", Integer1, Integer2);
	}	
	
	/* The program ran without problems */
	return 0;
}
