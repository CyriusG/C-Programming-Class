#include "minesweeper.h"

/*
 *	Generates a game board with randomly placed bombs.
 */
void generateBoard(struct cell gameBoard[], int boardY, int boardX)
{
	/* Declare variables */
	int index, xIndex = 0, yIndex = 0;
	
	/* Iterate through the BOARD_X and BOARD_Y, populating the gameboard with cells. */
	for (index = 0; index < boardY * boardX; index++) 
	{
		/* If it has reached the end of the row, increment the yIndex and reset the xIndex. */
		if(xIndex == boardX)
		{
			++yIndex;
			xIndex = 0;
		}

		/*
		 * Generate a cell at the current x and y position.
		 */
		gameBoard[index].y = yIndex;
		gameBoard[index].x = xIndex;
		/* 
		 * Generate a number between 0 and 9, a 0 is considered a bomb making it currently 
		 * a 10% chance of generating a bomb. 
		 */	
		gameBoard[index].bomb = rand() % 10;
		/* Make each cell hidden and set the amount of bombs around it to 0. */
		gameBoard[index].revealed = 0;
		gameBoard[index].bombsAround = 0;		
	
		/* Debug code */	
		if(gameBoard[index].x == 2 && gameBoard[index].y == 4)
		{
			gameBoard[index].bomb = 5;
			gameBoard[index].revealed = 1;
			gameBoard[index].bombsAround = 0;
		}

		if(gameBoard[index].x == 4 && gameBoard[index].y == 6)
		{
			gameBoard[index].bomb = 1;
			gameBoard[index].revealed = 1;
			gameBoard[index].bombsAround = 3;
		}

		if(gameBoard[index].x == 6 && gameBoard[index].y == 8)
		{
			gameBoard[index].bomb = 0;
			gameBoard[index].revealed = 1;
			gameBoard[index].bombsAround = 0;
		}

		/* After each iteration, increment the xIndex. */
		++xIndex;
	}	
}

/*
 *	Draw the gameboard.
 */
void drawBoard(struct cell gameBoard[], int boardY, int boardX)
{
	/* Declare index variables used by the for loops. */
	int index, headerX;

	/* Indent the x header by two positions. */
	printf("%2s", " ");

	/* Print the x header, 0 through BOARD_X. */
	for (headerX = 0; headerX < boardX; ++headerX) 
	{
		printf("%2d", headerX);
	}
	
	/* Print a new line when the x header has been printed. */	
	printf("\n");
	
	for (index = 0; index < boardY * boardX; ++index) 
	{	
		/* Print the y header if it is on the first x index. */
		if(gameBoard[index].x == 0)
		{
			printf("%2c", 65 + gameBoard[index].y);
		}
		
		/* If a cell is revealed with no bombs around and it is not a bomb, print an empty cell. */
		if(gameBoard[index].revealed && gameBoard[index].bombsAround == 0 && gameBoard[index].bomb != 0)
		{
			printf("%2s", " ");
		}
		/* If a cell is revealed, with bombs around it and it is not a bomb, print the number of bombs around. */
		else if(gameBoard[index].revealed && gameBoard[index].bombsAround != 0 && gameBoard[index].bomb !=0)
		{
			printf("%2d", gameBoard[index].bombsAround);
		}
		/* If a cell is revealed and it is a bomb, print an X. */
		else if(gameBoard[index].revealed && gameBoard[index].bomb == 0)
		{
			printf("%2s", "X");
		}
		/* Otherwise print an *. */
		else
		{
			printf("%2s", "*");
		}
		
		/* New line if it is the last cell in the row. */
		if(gameBoard[index].x == boardX - 1)
		{
			printf("\n");
		}
		
		/* Print a new line if every board item has been printed. */
		if(index == (boardY * boardX - 1))
		{
			printf("\n");
		}
	}
}
