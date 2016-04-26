/* 
 * onetofour
 *	
 * Prints one to four on one line without any conversion specifiers with one 
 * printf, with four conversion specifiers with one printf and with four printf
 * statements
 *
 * Joacim Eriksson
 * 2016-04-03
*/
#include <stdio.h>

int main() 
{
	int One, Two, Three, Four;

	/* Without any conversion specifiers and one printf */
	printf("Without any conversion specifiers and one printf.\n");
	printf("1, 2, 3 and 4.\n");
	
	/* With four conversion specifiers and one printf */
	printf("With four conversion specifiers and one printf.\n");
	One = 1;
	Two = 2;
	Three = 3;
	Four = 4;

	printf("%d, %d, %d and %d.\n", One, Two, Three, Four);

	/* With four printf statements */
	printf("With four printf statements.\n");
	printf("%d, ", One);
	printf("%d, ", Two);
	printf("%d and ", Three);
	printf("%d.\n", Four);

	return 0;
}
