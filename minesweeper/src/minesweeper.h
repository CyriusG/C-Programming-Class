#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Constants */
#define BOARD_Y 15
#define BOARD_X 15

/* Clear the screen */
#define clear() printf("\033[H\033[J\n")

/* Structures */
struct cell 
{
	int x, y;
	int bomb, revealed, bombsAround;
};


/* Functions */
void generateBoard(struct cell gameBoard[], int boardY, int boardX);
void drawBoard(struct cell gameBoard[], int boardY, int boardX);
void selectCell(int *selectY, int *selectX);
int revealCell(struct cell gameBoard[], int boardY, int boardX, int selectIndex);
void revealAllBombs(struct cell gameBoard[], int boardY, int boardX);
int coordinatesToIndex(int y, int x, int boardY);
