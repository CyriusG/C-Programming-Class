/* 
 * circlecalculations
 *	
 * Calculate the diameter, circumference and area of a circle
 *
 * Joacim Eriksson
 * 2016-04-09
*/
#include <stdio.h>

int main(void) 
{
	/* Declare variables and initilize Pi */
	float Pi = 3.14158, Radius, Diameter, Circumference, Area;

	/* Instruct the user to enter the radius and save that value to the Radius variable */
	printf("Enter the radius of a circle: ");
	scanf("%f", &Radius);

	/* Calculate the diameter, circumference and area of the circle */
	Diameter = Radius * 2;
	Circumference = Diameter * Pi;
	Area = Pi * (Radius * Radius);

	/* Print the results */
	printf("Radius: %.2f\n", Radius);
	printf("Diameter: %.2f\n", Diameter);
	printf("Circumference: %.2f\n", Circumference);
	printf("Area: %.2f\n", Area);

	/* The program ran without any problems */
	return 0;
}
