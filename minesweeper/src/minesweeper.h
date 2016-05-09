#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Constants */
#define BOARD_X 10
#define BOARD_Y 10

/* Structures */
struct cell 
{
	int x, y;
	int bomb, revealed, bombsAround;
};


/* Functions */
void generateBoard(struct cell gameBoard[][BOARD_Y]);
void drawBoard(struct cell gameBoard[][BOARD_Y]);
void selectCell(int *selectY, int *selectX);
