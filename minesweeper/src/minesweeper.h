#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Constants */
#define BOARD_Y 10
#define BOARD_X 10

#define BOMB 1

/* Structures */
struct cell 
{
	int y, x;
	int bomb, revealed, bombsAround;
};


/* Functions */
void generateBoard(struct cell gameBoard[], int boardY, int boardX, int bombs);
void drawBoard(struct cell gameBoard[], int boardY, int boardX, int score);
void selectCell(int *selectY, int *selectX, int boardY, int boardX);
int revealCell(struct cell gameBoard[], int boardY, int boardX, int selectIndex, int *score);
int bombsAround(struct cell gameBoard[], int boardY, int boardX, int selectIndex);
void revealAllBombs(struct cell gameBoard[], int boardY, int boardX);
int lastRevealed(struct cell gameBoard[], int boardY, int boardX);
int coordinatesToIndex(int y, int x, int boardY);
int difficultSetting();
