#include "minesweeper.h"

/*
 *	Generates a game board with randomly placed bombs.
 */
void generateBoard(struct cell gameBoard[], int boardY, int boardX)
{
	/* Declare variables */
	int index, xIndex = 0, yIndex = 0;
	int randomCell;
	
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

		/* Initialize the bomb variable. */	
		gameBoard[index].bomb = 0;
		/*gameBoard[index].bomb = 1;*/
		/* Make each cell hidden and set the amount of bombs around it to 0. */
		gameBoard[index].revealed = 0;
		gameBoard[index].bombsAround = 0;		
	
		 /*Debug code 	*/
		/*if(gameBoard[index].x == 2 && gameBoard[index].y == 4)*/
		/*{*/
			/*gameBoard[index].bomb = 5;*/
			/*gameBoard[index].revealed = 1;*/
			/*gameBoard[index].bombsAround = 0;*/
		/*}*/

		/*if(gameBoard[index].x == 4 && gameBoard[index].y == 6)*/
		/*{*/
			/*gameBoard[index].bomb = 1;*/
			/*gameBoard[index].revealed = 1;*/
			/*gameBoard[index].bombsAround = 3;*/
		/*}*/

		/*if(gameBoard[index].x == 6 && gameBoard[index].y == 8)*/
		/*{*/
			/*gameBoard[index].bomb = 0;*/
			/*gameBoard[index].revealed = 1;*/
			/*gameBoard[index].bombsAround = 0;*/
		/*}*/

		/* After each iteration, increment the xIndex. */
		++xIndex;
	}	

	/* Populate the board with bombs. */
	for (index = 0; index < 10; index++)
	{
		/* Generate a random index. */
		randomCell = rand() % (boardY * boardX);

		printf("%d\n", randomCell);
		/* While the generated index already has a bomb, generate a new index. */
		while(gameBoard[randomCell].bomb == BOMB)
		{
			randomCell = rand() % (boardY * boardX);
		}
		gameBoard[randomCell].bomb = 1;
	}	
	
}

/*
 *	Draw the gameboard.
 */
void drawBoard(struct cell gameBoard[], int boardY, int boardX, int score)
{	
	/* Declare index variables used by the for loops. */
	int index, headerX;

	/* Print the score */
	printf("%19s %d\n", "Current score:", score);

	/* Indent the x header by two positions. */
	printf("%3s", " ");

	/* Print the x header, 0 through BOARD_X. */
	for (headerX = 0; headerX < boardX; ++headerX) 
	{
		printf("%3d", headerX);
	}
	
	/* Print a new line when the x header has been printed. */	
	printf("\n");
	
	for (index = 0; index < boardY * boardX; ++index) 
	{	
		/* Print the y header if it is on the first x index. */
		if(gameBoard[index].x == 0)
		{
			printf("%3c", 65 + gameBoard[index].y);
		}
		
		/* If a cell is revealed with no bombs around and it is not a bomb, print an empty cell. */
		if(gameBoard[index].revealed == 1 && gameBoard[index].bombsAround == 0 && gameBoard[index].bomb != BOMB)
		{
			printf("%3s", " ");
		}
		/* If a cell is revealed, with bombs around it and it is not a bomb, print the number of bombs around. */
		else if(gameBoard[index].revealed == 1 && gameBoard[index].bombsAround != 0 && gameBoard[index].bomb != BOMB)
		{
			printf("%3d", gameBoard[index].bombsAround);
		}
		/* If a cell is revealed and it is a bomb, print an X. */
		else if(gameBoard[index].revealed == 1 && gameBoard[index].bomb == BOMB)
		{
			printf("%3s", "X");
		}
		/* Otherwise print an *. */
		else
		{
			printf("%3s", "*");
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

/*
 *	Reveals a cell on the inputed index.
 *
 *	Returns 1 if bomb, -1 if already revealed and 0 for empty cells not previously revelead.
 */
int revealCell(struct cell gameBoard[], int boardY, int boardX, int selectIndex)
{
	int returnValue;

	/* Check so that the cell is not already revealed. */
	if (gameBoard[selectIndex].revealed == 0)
	{
		/* Mark the cell as revealed. */
		gameBoard[selectIndex].revealed = 1;

		/* Check if it is a bomb, return 1 if it is otherwise return a 0. */
		if(gameBoard[selectIndex].bomb == BOMB)
		{
			returnValue =  1;
		}
		else
		{
			bombsAround(gameBoard, boardY, boardX, selectIndex);
			returnValue =  0;
		}
	}
	/* If the cell was already revealed -1 */
	else
	{
		returnValue =  -1;
	}

	return returnValue;
}

void bombsAround(struct cell gameBoard[], int boardY, int boardX, int selectIndex)
{
	int currentY = gameBoard[selectIndex].y;	
	int currentX = gameBoard[selectIndex].x;

	int indexRow, indexColumn;
	int lookY, lookX;
	
	int bombCounter = 0;

	for (indexRow = 0; indexRow < 3; ++indexRow) 
	{
		lookY = currentY - 1 + indexRow;
		if(lookY >= 0 && lookY < boardY)
		{
			for (indexColumn = 0; indexColumn < 3; ++indexColumn) 
			{
				lookX = currentX - 1 + indexColumn;
				
				if(lookX >= 0 && lookX < boardX)
				{	
					if((lookY != currentY || lookX != currentX) && gameBoard[coordinatesToIndex(lookY, lookX, boardY)].revealed == 0)
					{
						if(gameBoard[coordinatesToIndex(lookY, lookX, boardY)].bomb == BOMB)
						{
							++bombCounter;
						}						
					}
				}
			}
		}
	}

	gameBoard[selectIndex].bombsAround = bombCounter;
}

/*
 *	When the user reveals a bomb, reveal all bombs on the board.
 *
 *	Returns nothing.
 */
void revealAllBombs(struct cell gameBoard[], int boardY, int boardX)
{
	int boardIndex;

	/* Loop through the board index. */
	for (boardIndex = 0; boardIndex < boardY * boardX; ++boardIndex) 
	{
		/* If a bomb was found and it is not already revealed, reveal it. */
		if(gameBoard[boardIndex].bomb == BOMB && gameBoard[boardIndex].revealed == 0)
		{
			gameBoard[boardIndex].revealed = 1;
		}	
	}
}

/* 
 *	Checks the game board wether the last non-bomb cell has been revealed.
 *
 *	Returns 0 if there are non-bomb cells left, 1 if there are none.  
 */
int lastRevealed(struct cell gameBoard[], int boardY, int boardX)
{
	int boardIndex;

	/* Loops through the game board until an empty cell has been found. */
	for (boardIndex = 0; boardIndex < boardY * boardX; ++boardIndex) 
	{
		if(gameBoard[boardIndex].revealed == 0 && gameBoard[boardIndex].bomb != 0)
		{
			return 0;
		}
	}	

	/* If none is found, return 1. */
	return 1;
}
