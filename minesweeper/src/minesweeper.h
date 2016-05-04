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
