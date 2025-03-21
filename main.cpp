#include "move.h"
#include "GameOver.h"
#include "board.h"
#include "move.h"
#include "classes.h"

int rows;
int columns;
Player player;

void main()
{
	srand(time(NULL));

	readFile(rows, columns);
	initializeBoard(rows, columns, &player);
	printBoard(rows, columns);
	movePlayer(rows, columns, player);
	deleteBoard(rows, columns);
}