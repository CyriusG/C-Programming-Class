/* 
 * grade
 *
 * Grades the user depending on what they input.
 *
 * Joacim Eriksson
 * 2016-04-02
 */
#include <stdio.h>

int main() 
{
	/* Declare the 'Grade' variable */
	int Grade;

	/* Ask the user for a grade and scan the answer into the 'Grade' variable */
	printf("What is the grade?\n");
	scanf("%d", &Grade);

	/* If grade is larger or equal to 80, the grade is a 5 */
	if (Grade >= 80) 
	{
		printf("Grade: 5\n");
	}
	/* If grade is smaller than 80 but larger or equal to 60, the grade is a 4 */
	else if (Grade >= 60) 
	{
		printf("Grade: 4\n");
	}
	/* If grade is smaller than 60 but larger or equal to 40, the grade is a 3 */
	else if (Grade >= 40) 
	{
		printf("Grade: 3\n");
	}
	/* Otherwise the grade is an F */
	else 
	{
		printf("Grade: F\n");
	}
	
	/* The program ran without problems */
	return 0;
}
