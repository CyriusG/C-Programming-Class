/* 
 * bmi
 *	
 * Calculates the user's BMI using kg and cm and also prints a BMI chart.
 *
 * Joacim Eriksson
 * 2016-04-03
*/
#include <stdio.h>

int main() 
{
	float Weight, Height, BMI;

	/* The user inputs their weight in kg and height in m */
	printf("Enter your weight (kg): ");
	scanf("%f", &Weight);
	printf("Enter your height (m): ");
	scanf("%f", &Height);
	
	/* Calculate the BMI and print it with two decoimals */
	BMI = (Weight / (Height * Height));
	printf("Your BMI: %.2f\n", BMI);

	/* Print BMI chart */
	printf("BMI VALUES\n");
	printf("Underweight:	less than 18.5\n");
	printf("Normal:		between 18.5 and 24.9\n");
	printf("Overweight:	between 25 and 29.9\n");
	printf("Obese:		30 or greater\n");

	/* The program ran without problems */
	return 0;
}
