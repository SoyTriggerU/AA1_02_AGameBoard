#include <iostream>

enum class PlayerMovement {
	UP,
	DOWN,
	LEFT,
	RIGTH
};

struct Player {
	int x; // Inidicates the player's position in x coordinates
	int y; // Inidicates the player's position in y coordinates
	int score;
	PlayerMovement move;
};

// Local variable board
char** board;