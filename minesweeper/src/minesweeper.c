/* 
 * minesweeper
 *	
 * <description>
 *
 * Joacim Eriksson
 * 2016-05-04
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "minesweeper.h"

int main(void) 
{
	int running = 1;
	int i, y;
	struct cell gameBoard[BOARD_X][BOARD_Y];
	
	/* Set the seed for the random number generator. */
	srand(time(NULL));
	
	generateBoard(gameBoard);

	for (i = 0; i < 10; ++i) 
	{
		for (y = 0; y < 10; ++y) 
		{
			printf("%d, %d, %d, %d, %d\n", gameBoard[i][y].x, gameBoard[i][y].y, gameBoard[i][y].bomb, gameBoard[i][y].revealed, gameBoard[i][y].bombsAround);

		}
		printf("\n");
	}

	return 0;
}

/*
 *	Generates a game board and places bombs randomly.
 */
void generateBoard(struct cell gameBoard[][BOARD_Y])
{
	int xIndex, yIndex;
	int randomBomb;
		
	randomBomb = rand() % 10;

	for (xIndex = 0; xIndex < BOARD_X; xIndex++) 
	{
		for (yIndex = 0; yIndex < BOARD_Y; yIndex++) 
		{
			gameBoard[xIndex][yIndex].x = xIndex;
			gameBoard[xIndex][yIndex].y = yIndex;
			gameBoard[xIndex][yIndex].bomb = rand() % 10;
			gameBoard[xIndex][yIndex].revealed = 0;
			gameBoard[xIndex][yIndex].bombsAround = 0;
		}	
	}
}
