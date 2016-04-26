/* 
 * valuesequence
 *	
 * <description>
 *
 * Joacim Eriksson
 * 2016-04-10
*/
#include <stdio.h>

int main(void) 
{
	int x = 3, y = 8, a = 4, b = 4, g = 6, i = 6, j = 5;

	printf("!(x < 5) && !(y >= 7) = %d \n", !(x < 5) && !(y >= 7));
	printf("!((x < 5) || (y >= 7)) = %d\n", !((x < 5) || (y >= 7)));
	
	printf("\n");
	
	printf("!(a == b) || !(g != 5) = %d\n", !(a == b) || !(g != 5));	
	printf("!((a == b) && (g != 5)) = %d\n", !((a == b) && (g != 5)));

	printf("\n");

	printf("!((x <= 8) && (y > 4)) = %d\n", !((x <= 8) && (y > 4)));
	printf("!(x <= 8) || !(y > 4) = %d\n", !(x <= 8) || !(y > 4));

	printf("\n");

	printf("!((i > 4) || (j <= 6)) = %d\n", !((i > 4) || j <= 6));
	printf("!(i > 4) && !(j <= 6) = %d\n", !(i > 4) && !(j <= 6));

	return 0;
}
