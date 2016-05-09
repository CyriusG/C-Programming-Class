#include "minesweeper.h"

/*
 *	Generates a game board and places bombs randomly.
 */
void generateBoard(struct cell gameBoard[][BOARD_Y])
{
	/* Declare variables */
	int xIndex, yIndex;
	
	/* Iterate through the BOARD_X and BOARD_Y, populating the gameboard with cells. */
	for (xIndex = 0; xIndex < BOARD_X; xIndex++) 
	{
		for (yIndex = 0; yIndex < BOARD_Y; yIndex++) 
		{
			/*
			 * Place a bomb at the current x and y position.
			 */
			gameBoard[xIndex][yIndex].x = xIndex;
			gameBoard[xIndex][yIndex].y = yIndex;
			/* 
			 * Generate a number between 0 and 9, a 0 is considered a bomb making it currently a 
			 * 10% chance of generating a bomb. 
			 */	
			gameBoard[xIndex][yIndex].bomb = rand() % 10;
			/* Make each cell hidden and set the amount of bombs around it to 0. */
			gameBoard[xIndex][yIndex].revealed = 0;
			gameBoard[xIndex][yIndex].bombsAround = 0;
		}	
	}
}

/*
 *	Drwas the gameboard.
 */
void drawBoard(struct cell gameBoard[][BOARD_Y])
{
	/* Declare index variables used by the for loops. */
	int xIndex, yIndex, headerX;

	/* Indent the x header by two positions. */
	printf("%2s", " ");

	/* Print the x header, 0 through BOARD_X. */
	for (headerX = 0; headerX < BOARD_X; ++headerX) 
	{
		printf("%2d", headerX);
	}
	
	/* Print a new line when the x header has been printed. */	
	printf("\n");

	/* Iterate through each row. */
	for (yIndex = 0; yIndex < BOARD_Y; ++yIndex) 
	{
		/* Iterate through each item for every row */
		for (xIndex = 0; xIndex < BOARD_X; ++xIndex) 
		{
			/* If it is the first item, print the y header as a character. */
			if(xIndex == 0)
			{
				printf("%2c", 65 + yIndex);
			}
			
			/* Print each cell, make it take two positions to give some space between cells. */
			printf("%2s", "*");	
		}
		
		/* Print a new line if it is the end of a row. */
		printf("\n");
	}	
}
