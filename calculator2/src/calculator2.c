/*
 * calculator2
 *
 * Simple calculator with a menu system using floats.
 *
 * Joacim Eriksson
 * 2016-04-02
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	/* Declare variables, boolean used to determine if the menu should be shown again */
	bool ShowMenu;
	float Number1, Number2, Result; 
	int MenuChoice, ReadIntegers;

	/* The program should show the menu the first time */
	ShowMenu = true;

	/* While the variable ShowMenu is set to true, show the menu */
	while(ShowMenu)
	{
		/* Print the menu and read user input */
		printf("Chose what operation to perform.\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Exit\n");
		ReadIntegers = scanf("%d", &MenuChoice);

		/* Make sure that the menu reads integers */
		if(ReadIntegers == 1)
		{
			/* If the user inputs valid operations that are not exit, ask for two numbers */
			if(MenuChoice >= 1 && MenuChoice <= 4)
			{
				printf("Enter two numbers.\n");
				scanf("%f%f", &Number1, &Number2);
			}
	
			/* Depending on what the user chose, run different pieces of code */
			switch(MenuChoice)
			{
				/* If the user chose 1, add the two numbers and print the sum */
				case 1:
					Result = Number1 + Number2;
					/* Print only with two decimals */
					printf("Sum: %.2f\n", Result);
				break;

				/*
				 * If the user chose 2, subtract the second number from the first and print the 
				 * difference
				 */
				case 2:
					Result = Number1 - Number2;
					printf("Difference: %.2f\n", Result);
				break;
				
				/* If the user chose 3, multiply the two numbers and print the product */
				case 3:
					Result = Number1 * Number2;
					printf("Product: %.2f\n", Result);
				break;

				/*
				 * If the user chose 4, first check if the second number is valid for division 
				 * (i.e. it should not be a 0)
				 */
				case 4:
					if (Number2 != 0)
					{
						/* If it is not a 0, calculate and print the quotient */
						Result = Number1 / Number2;
						printf("Quotient: %.2f\n", Result);
					}
					/* Otherwise, tell the user that he/she entered numbers invalid for division */
					else
					{
						printf("Not a valid division\n");
					}
				break;
			
				/*
				 * If the user inputs anything else, tell the program to not show the menu again and 
				 * will therafore exit
				 */
				default:
					ShowMenu = false;
				break;
			}
		}
		else
		{
			/* Don\t show the menu again */
			ShowMenu = false;
		}
	}
	
	/* The program ran without any problems */
	return 0;
}
