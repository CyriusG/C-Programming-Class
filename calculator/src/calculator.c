/* 
*	calculator
*	
*	Very simple calculator that takes two integers and add them together, subtract the first with the second
*	multiply the two and divide the first with the second, if it is valid (i.e. no divide by 0).
*
*	Joacim Eriksson
*	2016-04-02
*/
#include <stdio.h>
#include <stdbool.h>

int main(void) 
{
	/* Declare the variables */
	int Integer1, Integer2, Addition, Subtraction, Multiplication, Division;
	/* Boolean variable to keep track if the divsion is valid or not throughout the program */
	bool DivisionValid;

	/* Instruct the user to input two integers and read them into two variables, Integer1 and Integer2. */
	printf("Enter two integers.\n");
	scanf("%d%d", &Integer1, &Integer2);

	/* Calculate the different operations */
	Addition = Integer1 + Integer2;
	Subtraction = Integer1 - Integer2;
	Multiplication = Integer1 * Integer2;
	/* If Integer2 is not 0, i.e. valid for division. */
	if(Integer2 != 0)
	{
		/* Divide Integer1 with Integer2 and set the DivsionValid variable to true, to indicate that the
		 * division was valid */
		Division = Integer1 / Integer2;
		DivisionValid = true;
	}
	/* Otherwise, set DivisionValid to false, to indicate that the division was not valid */
	else
	{
		DivisionValid = false;
	}
	
	/* Print the results */
	printf("Addition: %d\n", Addition);
	printf("Subtraction: %d\n", Subtraction);
	printf("Multiplication: %d\n", Multiplication);
	/* Print the division results if it was a valid division */
	if (DivisionValid)
	{
		printf("Division: %d\n", Division);
	}
	/* Otherwise, print out a message telling the user that the division was not valid */
	else
	{
		printf("Divsion not valid\n");
	}
	
	/* The program ran through normally */
	return 0;
}
