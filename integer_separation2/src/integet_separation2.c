/* 
 * integet_separation2
 *	
 * Separates the integers from a five digit number using a for loop
 *
 * Joacim Eriksson
 * 2016-04-07
*/
#include <stdio.h>

int main(void) 
{
	/* Declare variables and initialize LastValue to 0 */
	int Number, Counter, SeparatedInteger, LastValue = 0;
	
	/* Instruct the user to input a five digit number */
	printf("Enter a five digit number.\n");
	scanf("%d", &Number);

	/* 
	 * Loop to separate each Integer and print them out, limited to the count to the ammount of 
	 * numbers it can separate 
	 */
	for (Counter = 10000; Counter >= 0; Counter/=10) {
		/* Calculate the current separated integer */
		SeparatedInteger = (Number - LastValue) / Counter;
		/* 
		 * Add the current separated integer, times the counter, to an integer containing the last 
		 * calculated numbers 
		 */
		LastValue += SeparatedInteger * Counter;
	
		/* Print the results */
		printf("%d\n", SeparatedInteger);
	}	

	/* The program ran successfully */
	return 0;
}
