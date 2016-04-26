/* 
 * integer_separation
 *	
 * Let the user to input a five digit integer and separate from one another
 *
 * Joacim Eriksson
 * 2016-04-03
*/
#include <stdio.h>

int main() 
{
	/* Declare integers */
	int FiveDigitInteger, FirstDigit, SecondDigit, ThirdDigit, FourthDigit, FifthDigit;
	
	/* Ask the user for five digit integer and put it into a variable */
	printf("Enter a five digit integer.\n");
	scanf("%d", &FiveDigitInteger);
	
	/* While the integer has more or less than five digits */
	while ((FiveDigitInteger - (FiveDigitInteger % 10000))/10000 >= 10)
	{
		/* Ask the user for five digit integer, again, and put it into a variable */
		printf("Enter a _five_ digit integer.\n");
		scanf("%d", &FiveDigitInteger);
	}

	/* Extract the first digit */
	FirstDigit = (FiveDigitInteger - (FiveDigitInteger % 10000))/10000;
	/* Extract the second dgit */
	SecondDigit = ((FiveDigitInteger - (FirstDigit * 10000) - FiveDigitInteger % 1000))/1000;
	/* Extract the third digit */
	ThirdDigit = ((FiveDigitInteger - (FirstDigit * 10000) - (SecondDigit  * 1000)) - 
			(FiveDigitInteger % 100))/100;
	/* Extract the fourth digit */
	FourthDigit = ((FiveDigitInteger - (FirstDigit * 10000) - (SecondDigit * 1000) - 
				(ThirdDigit * 100)) - (FiveDigitInteger % 10))/10;
	/* Extract the fifth digit */
	FifthDigit = ((FiveDigitInteger - (FirstDigit * 10000) - (SecondDigit * 1000) - 
				(ThirdDigit * 100) - (FourthDigit * 10)));
	
	/* Print the separated digits, comma separated */
	printf("%d, %d, %d, %d, %d\n", FirstDigit, SecondDigit, ThirdDigit, FourthDigit, FifthDigit);

	/* The program ran without any problems */
	return 0;
}
