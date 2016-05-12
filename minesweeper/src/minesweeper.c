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
	int selectY, selectX;

	/* Declare a two dimensional array of cells as the gameboard. */
	struct cell gameBoard[BOARD_Y * BOARD_X];
	
	/* Set the seed for the random number generator. */
	srand(time(NULL));
	
	/* Generate a new gameboard. */	
	generateBoard(gameBoard, BOARD_Y, BOARD_X);

	/* Draw the gameboard once. */
	drawBoard(gameBoard, BOARD_Y, BOARD_X);

	/* Ask the user to select a cell and print the x and y coordinates. */
	selectCell(&selectY, &selectX);
	printf("%d, %d\n", selectY, selectX);

	return 0;
}

/* 
 * Asks the user to select a cell by specifying x and y coordinates and reveals the selected 
 * cell. 
 */
void selectCell(int *selectY, int *selectX)
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
		if(toupper(selectedY) - 65 >= 0 && toupper(selectedY) - 65 < BOARD_Y && selectedX >= 0 && selectedX < BOARD_X && 
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
