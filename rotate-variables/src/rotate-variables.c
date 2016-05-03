/* 
 * rotate-variables
 *	
 * Rotates three variables
 *
 * Joacim Eriksson
 * 2016-05-03
*/
#include <stdio.h>
#include "rotate-variables.h"

int main(void) 
{
	int a = 1, b = 2, c = 3;

	printf("%d, %d, %d\n", a, b, c);    
    
	rotateThree(&a, &b, &c);

	printf("%d, %d, %d\n", a, b, c);    

	return 0;
}

void rotateThree(int *a, int *b, int*c)
{
	int aTmp = *a, bTmp = *b, cTmp = *c;

	*a = bTmp;
	*b = cTmp;
	*c = aTmp;
}
