/* 
 * tabularoutput
 *	
 * Prints a series of tabular formated numbers
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>

int main(void) 
{
	unsigned int Counter = 1, A = 3;
	
	/* Print the initial header */
	printf("A \t A+2 \t A+4 \t A+6\n\n");

	/* Iterate through all five rows */	
	while(Counter <= 5)
	{
		/* Calculate and print the four columns for each row */
		printf("%u \t %u \t %u \t %u \n",A * Counter,  A * Counter + 2, A * Counter + 4, 
										A * Counter + 6);
		
		/* Increment the counter */
		Counter++;
	}

	/* The program ran without problems */
	return 0;
}
