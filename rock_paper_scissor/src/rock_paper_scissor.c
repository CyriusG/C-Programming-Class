/* 
 * rock_paper_scissor
 *	
 * Simple rock, paper scissor game
 *
 * Joacim Eriksson
 * 2016-04-18
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/definitions.h"

int main(void) 
{
	/* Declare and initialize variables */
	int UserChoice, ComputerChoice = 0, UserWins = 0, ComputerWins = 0, Round = 1;

	/* Run while the round is less or equal to 10 */
	while(Round <= 10)
	{
		/* Print the current round */
		printf("\nRound: %d\n", Round);

		/* Run the function to ask if the user chooses rock, paper or scissor */
		UserChoice = userChoice();
		/* Get a random choice from the computer */
		ComputerChoice = computerChoice(ComputerChoice);
		
		/* If userchoice and computerchoice was the same, print draw */
		if(UserChoice == ComputerChoice)
		{
			/* Increment the round counter */
			Round++;
			/* Tell the user it was a draw */
			printf("Draw\n");
		}
		/* 
		 * Display and increment the different counters depending on what the user choice and what 
		 * the computer generated 
		 */
		else if(UserChoice == 1 && ComputerChoice == 2)
		{
			Round++;
			ComputerWins++;
			printf("User: Stone, Computer: Paper\nComputer Won.\n");
		}
		else if(UserChoice == 1 && ComputerChoice == 3)
		{
			Round++;
			UserWins++;	
			printf("User: Stone, Computer: Scissor\nUser Won.\n");
		}
		else if(UserChoice == 2 && ComputerChoice == 1)
		{
			Round++;
			UserWins++;
			printf("User: Paper, Computer: Rock\nUser Won.\n");
		}
		else if(UserChoice == 2 && ComputerChoice == 3)
		{
			Round++;
			ComputerWins++;
			printf("User: Paper, Computer: Scissor\nComputer Won.\n");

		}
		else if(UserChoice == 3 && ComputerChoice == 1)
		{
			Round++;
			ComputerChoice++;
			printf("User: Scissor, Computer: Rock\nComputer Won.\n");
		}
		else 
		{
			Round++;
			UserWins++;
			printf("User: Scissor, Computer: Paper\nUser Won.\n");
		}
		
	}
	
	/* Print the results and tell the user who won */
	printf("\nResults: User %d wins, Computer %d wins\n", UserWins, ComputerWins);
	if(UserWins > ComputerWins)
	{
		printf("User Won!\n");
	}
	else if(ComputerWins > UserWins)
	{
		printf("Computer Won!\n");
	}
	else
	{
		printf("Draw!\n");
	}

	/* The user ran without any problems */
	return 0;
}

/* Asks the user for rock, paper or scissor and returns the results as an integer */
int userChoice()
{
	/* Declare and initialize UserChoice each time the function is run */
	int UserChoice = 0;
	
	/* While the user inputs an invalid value, ask for a valid value */
	while(UserChoice < 1 || UserChoice > 3)
	{	
		printf("Chose Rock (1), Paper (2) or Scissor (3): ");
		scanf("%d", &UserChoice);
	}

	/* Return what the user chose */
	return UserChoice;
}

/* 
 * Generates a random number between 1 and 3 and uses the current unix timestamp as the random 
 * seed 
 */
int computerChoice(int ComputerChoice)
{
	/* Declare and initialize variables */
	int NewChoice = 0;
	unsigned int Seed = time(NULL);
	
	/* Set the random seed to the current unix timestamp */
	srand(Seed);	

	/* Generate a new number and make sure it is not the same as the last */
	while(NewChoice == ComputerChoice || NewChoice == 0)
	{
		NewChoice = (1 + rand() % 3);
	}

	/* Return the randomly generated number */
	return NewChoice;
}
