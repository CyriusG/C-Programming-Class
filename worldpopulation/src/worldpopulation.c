/* 
 * worldpopulation
 *	
 * Calculates the estimated world population after one, two, three, four and five years.
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>

int main(void) 
{
	/* Declare and initilize variables */
	int Counter = 1, InternalCounter;
	float CurrentPopulation, GrowthRate, Population, TemporaryGrowth;

	/* Ask the user for the current world population and growth rate */
	printf("Input the current population (billion): ");	
	scanf("%f", &CurrentPopulation);
	printf("Input the current growth rate (decimal percentage): ");
	scanf("%f", &GrowthRate);
	
	/* External while loop iterates through each year */
	while(Counter <= 5)
	{
		/* If it is year 1, there is no need to calculate the growth rate */
		if(Counter == 1)
		{
			/* Calculate the population for year 1 and print the results */
			Population = CurrentPopulation * GrowthRate;
			printf("Year %d population: %f\n", Counter, Population);
		}
		/* Othersiee the program has to calculate the growth to that year */
		else
		{
			/* Reset the internal counter and growth rate */
			InternalCounter = 1;
			TemporaryGrowth = GrowthRate;

			/* Calculate the growth rate for the current year */
			while(InternalCounter <= Counter)
			{
				TemporaryGrowth *= GrowthRate;

				/* Increment the internal counter */
				InternalCounter++;
			}

			/* Calculate the population for the current year and print the results */
			Population = CurrentPopulation * TemporaryGrowth;
			printf("Year %d population: %f\n", Counter, Population);
		}

		/* Increment the external counter */
		Counter++;
	}

	/* The program ran without any problems */
	return 0;
}
