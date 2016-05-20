/* 
 * minesweeper
 *	
 * Make a safe passage through the minefield.
 * Reveal cells, but try to avoid any mines!
 *
 * Joacim Eriksson
 * 2016-05-04
*/
#include "minesweeper.h"

int main(void) 
{ 
	int running = 1, difficult;
	int boardY, boardX, bombs;
	int selectY, selectX, revealCellReturn;
	
	/* Declare a pointer to the gameBoard */
	struct cell *gameBoard;

	int score;

	
	difficult = difficultSetting();

	switch(difficult)
	{
		case 1:
			boardY = 10;
			boardX = 10;
			bombs = 10;
		break;

		case 2:
			boardY = 16;
			boardX = 16;
			bombs = 40;
		break;

		case 3:
			boardY = 25;
			boardX = 25;
			bombs = 100;
		break;

		case 4:
			boardY = 10;
			boardX = 10;
			bombs = 2;
		break;
	}
	
	/* Allocate memory for the gameboard. */
	gameBoard = (struct cell *) malloc((boardY * boardX) * sizeof(struct cell));

	score = boardY * boardX - bombs;

	if(gameBoard == NULL)
	{
		printf("Out of memory.\n");
		return 0;
	}
	
	/* Set the seed for the random number generator. */
	srand(time(NULL));
	
	/* Generate a new gameboard. */	
	generateBoard(gameBoard, boardY, boardX, bombs);

	/* Game loop */
	while(running)
	{
		/* Draw the gameboard once. */
		drawBoard(gameBoard, boardY, boardX, score);

		/* Ask the user to select a cell and print the x and y coordinates. */
		selectCell(&selectY, &selectX, boardY, boardX);
		
		revealCellReturn = revealCell(gameBoard, boardY, boardX, coordinatesToIndex(selectY, selectX, boardY), &score);

		/* If the user revealed a bomb, reveal all bombs, redraw the board and end the game. */
		if(revealCellReturn == 1)
		{
			revealAllBombs(gameBoard, boardY, boardX);
			drawBoard(gameBoard, boardY, boardX, score);
			running = 0;
		}

		/* If the user revealed a cell, check wether it was the last cell to be revealed, redraw the board and end the game */
		if(revealCellReturn == 0)
		{
			/* Check if the last cell was revealed. */
			if(lastRevealed(gameBoard, boardY, boardX))
			{
				drawBoard(gameBoard, boardY, boardX, score);
				running = 0;
			}
		}
	}

	/* Free gameBoard from memory. */
	free(gameBoard);

	return 0;
}

/* 
 * Asks the user to select a cell by specifying x and y coordinates and reveals the selected 
 * cell. 
 */
void selectCell(int *selectY, int *selectX, int boardY, int boardX)
{
	/* Declare variables used to read the input. */
	char selectedY;
	int selectedX, validInputs;
	
	/* Used to keep track whether the user input correct data. */
	int correctInput = 0;

	/* 
	 * Ask the user to enter coordinates to the cell to reveal and in what format, the program 
	 * accepts both lower and uppercase letters and will automatically convert any lowercase 
	 * letters to uppercase when converting to an integer. 
	 */
	printf("Enter the coordinates of the cell you want to reveal starting with Y followed by X (e.g. B 2): ");
	do
	{
		validInputs = scanf("%c%d", &selectedY, &selectedX);
	
		/* Does a sanity check to make sure that the user input is within the gameboard. */	
		if(toupper(selectedY) - 65 >= 0 && toupper(selectedY) - 65 < boardY && selectedX >= 0 && selectedX < boardX && 
			validInputs == 2) 
		{
			correctInput = 1;
		}

	}
	while(!correctInput);

	/* When the sanity checks went well the Y and X variables will be updated using the pointers. */
	*selectY = toupper(selectedY) - 65;
	*selectX = selectedX;
}

int difficultSetting()
{
	int difficultSetting;

	printf("1) Easy (10x10 - 10 bombs)\n");
	printf("2) Medium (16x16 - 40 bombs)\n");
	printf("3) Hard (25x25 - 100 bombs)\n");

	printf("Enter difficult setting (1 - 3): ");
	scanf("%d", &difficultSetting);

	return difficultSetting;
}

/*
 *	Converts two coordinates to an index.
 *
 *	Returns the index for those two coordinates.
 */
int coordinatesToIndex(int y, int x, int boardY)
{
	return (y * boardY) + x;	
}
