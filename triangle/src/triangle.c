/* 
 * triangle
 *	
 * Read three nonzero integers and calculate wether they are part of a triangle or not
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>

int main(void) 
{
	int Integer1, Integer2, Integer3, Side1, Side2, Hypotenuse, TriangeHeight, TriangeWidth;

	/* Instruct the user to enter three nonzero integers */
	printf("Enter three nonzero integers: ");
	scanf("%d%d%d", &Integer1, &Integer2, &Integer3);

	/* Instruct the user to input a nonzero integer if they do not follow the previous instruction */
	while(Integer1 <= 0 && Integer2 <= 0 && Integer3 <= 0)
	{
		printf("Enter three _nonzero_ integers: ");
		scanf("%d%d%d", &Integer1, &Integer2, &Integer3);
	}

	/* Find out what integer would be the Hypotenuse */
	if (Integer1 > Integer2 && Integer1 > Integer3) 
	{
		Hypotenuse = Integer1;
		Side1 = Integer2;
		Side2 = Integer3;
	}
	else if (Integer2 > Integer1 && Integer2 > Integer3) 
	{
		Hypotenuse = Integer2;
		Side1 = Integer1;
		Side2 = Integer3;
	}
	else
	{
		Hypotenuse = Integer3;
		Side1 = Integer1;
		Side2 = Integer2;
	}

	/* If Side1^2 + Side2^2 is equal to Hypotenuse^2, it is a valid triange */
	if (Side1 * Side1 + Side2 * Side2 == Hypotenuse * Hypotenuse) 
	{
		printf("Valid triangle\n");
	}
	else
	{
		printf("Not a valid triangle\n");
	}

	return 0;
}
