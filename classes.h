#pragma once
#include <iostream>
#include <fstream>
#include <string>

enum class PlayerMovement {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Player {
	int x; // Inidicates the player's position in x coordinates
	int y; // Inidicates the player's position in y coordinates
	int score = 0;
};