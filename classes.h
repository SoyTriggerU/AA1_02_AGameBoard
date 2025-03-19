#include <iostream>

enum class PlayerMovement {
	UP,
	DOWN,
	LEFT,
	RIGTH
};

enum class BoardCell
{
	WALL,
	SPIKE,
	GEM,
	PLAYER,
	EMPTY
};

struct Player {
	int x; // Inidicates the player's position in x coordinates
	int y; // Inidicates the player's position in y coordinates
	int score;
	PlayerMovement move;
	BoardCell cell;
};