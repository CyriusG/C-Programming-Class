/* 
 * arithmetic
 *	
 * Ask the user for three integers and print the sum, average, product,
 * the smallest integer and the largest.
 *
 * Joacim Eriksson
 * 2016-04-03
*/
#include <stdio.h>

int main() 
{
	int Integer1, Integer2, Integer3, Sum, Average, Product, Smallest, Largest;

	printf("Enter three integers: ");
	scanf("%d%d%d", &Integer1, &Integer2, &Integer3);
	
	Sum = Integer1 + Integer2 + Integer3;
	Average = (Integer1 + Integer2 + Integer3) / 3;
	Product = Integer1 * Integer2 * Integer3;

	if (Integer1 < Integer2 && Integer1 < Integer3) 
	{
		Smallest = Integer1;
	}
	else if (Integer2 < Integer1 && Integer2 < Integer3) 
	{
		Smallest = Integer2;
	}
	else
	{
		Smallest = Integer3;
	}	
	
	if (Integer1 > Integer2 && Integer1 > Integer3) 
	{
		Largest = Integer1;
	}
	else if (Integer2 > Integer1 && Integer2 > Integer3) 
	{
		Largest = Integer2;
	}
	else
	{
		Largest = Integer3;
	}

	printf("Sum: %d\n", Sum);
	printf("Average: %d\n", Average);
	printf("Product: %d\n", Product);
	printf("Smallest: %d\n", Smallest);
	printf("Largest: %d\n", Largest);

	return 0;
}
