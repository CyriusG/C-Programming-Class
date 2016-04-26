/* 
 * findlargest
 *	
 * Find out the largest number out of ten numbers
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>

int main(void) 
{
	/*
	 * Declare and initilize variable counter to 0, number (does not need initilization) and 
	 * largestnumber to 0
	 */
	int Counter = 0; 
	unsigned int LargestNumber = 0, Number;

	/*
	 * While counter is less than ten, ask for more numbers
	 *		Ask the user for a number and assign it to the variable number
	 *		Check if the current number is larger than the one stored in the Largest variable
	 *			If true, assign Largest to the current number
	 *		else
	 *			Do nothing
	 *
	 *		Increment counter with one	
	 */

	while(Counter < 10)
	{
		printf("Enter a positive number: ");
		scanf("%u", &Number);

		if (Number > LargestNumber) 
		{
			LargestNumber = Number;
		}

		Counter++;
	}

	/* Print out the largest number */	
	printf("Largest number: %u\n", LargestNumber);
	
	/* Program ran without problems */
	return 0;
}
