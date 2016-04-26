/* 
 * factorial
 *	
 * Calcultes the factorial for a positive integer
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>
#include "../include/definitions.h"

int main(void) 
{
	/* Declare variables */
	unsigned int Integer, Factorial, ECounter = 1, ERaisedCounter = 1; 
	float ConstantE = 1, ConstantERaised = 1;

	/* Instruct the user to enter a nonzero integer */
	printf("Enter a nonzero integer: ");
	scanf("%u", &Integer);

	/* Calculate the factorial using the factorial function */
	Factorial = factorial(Integer);

	/* Calculate the e constant */	
	while(ECounter <= Integer)
	{
		/*
		 * For each iteration, add value of the float division 1/Counter!, using the function
		 * used previously
		 */
		ConstantE += ((float) 1 / factorial(ECounter));

		/* Increment the counter */
		ECounter++;
	}

	while(ERaisedCounter <= Integer)
	{
		ConstantERaised += ((float)raised(Integer, ERaisedCounter) / factorial(ERaisedCounter));

		ERaisedCounter++;
	}

	/* Print the results */
	printf("Factorial: %u\n", Factorial);
	printf("e Constant: %.2f\n", ConstantE);
	printf("e^x: %.2f\n", ConstantERaised);

	return 0;
}

/*
 * Takes an integer and calculates the factorial from that integer and returns that value
 */
int factorial(int FactorialInput)
{
	int FactorialCounter, FactorialInteger;

	/* Initialize variables, avoid having to use the input variable */	
	FactorialInteger = FactorialInput;
	FactorialCounter = FactorialInteger - 1;

	while(FactorialCounter > 0)
	{
		/* Calculate the factorial for the current iteration */
		FactorialInteger *= FactorialCounter;

		/* Decrement the counter */
		FactorialCounter--;
	}

	/* Return the results */
	return FactorialInteger;
}

/*
 * Takes and integer and multiplies itself a specified amount of times
 */
int raised (int RaisedInput, int TimesToRaise)
{
	/* Declare and initilize variables */
	int Product = RaisedInput, RaiseCounter = 1;

	/* Do not calculate anything if it's raised only once */
	if(TimesToRaise != 1)
	{	
		/* Calculate the product */
		while(RaiseCounter < TimesToRaise)
		{
			Product *= RaisedInput;

			RaiseCounter++;
		}
	}

	/* Return the product */
	return Product;
}
