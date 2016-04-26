/* 
 * fivetable
 *	
 * Prints table of multiplication of five
 *
 * Joacim Eriksson
 * 2016-04-02
*/
#include <stdio.h>

int main() 
{
	/* Declare variables */
	int Index, Product;
	
	/* Iterate ten times, starting from 1 */
	for (Index = 1; Index <= 10; ++Index) {
		/* Calculate the product for the current index */
		Product = Index * 5;
		
		/* Print the resulsts */
		printf("%d * 5 = %d\n", Index, Product);
	}

	/* The program ran successfully */
	return 0;
}
