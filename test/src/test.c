/* 
 * test
 *	
 * <description>
 *
 * Joacim Eriksson
 * 2016-05-22
*/
#include <stdio.h>
	
struct S
{
	int a;
	char b;
	struct S *nextPtr;
};
	
int main(void)
{
	struct S data;

	scanf("%d", data->a);
	data->b='A';
	data->nextPtr=NULL;	
	printf("%d\n", data.a);

	return 0;
}

