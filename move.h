#pragma once
#include "board.h"

// mirar si funciona
PlayerMovement translateInput(char input)
{
	if (input == 'w' || input == 'W')
		return PlayerMovement::UP;
	else if (input == 's' || input == 'S')
		return PlayerMovement::DOWN;
	else if (input == 'a' || input == 'A')
		return PlayerMovement::LEFT;
	else if (input == 'd' || input == 'D')
		return PlayerMovement::RIGHT;
}

bool checkMovement(Player player, PlayerMovement move)
{
	int rows;
	int columns;
	char input;
	initializeBoard(rows, columns, player);
	translateInput(input); // mirar si està ben implementat
	switch (move)
	{
	case PlayerMovement::UP:
		if (board[player.x--][player.y] != '*')
			return true;
		else
			return false;
	case PlayerMovement::DOWN:
		if (board[player.x++][player.y] != '*')
			return true;
		else
			return false;
	case PlayerMovement::LEFT:
		if (board[player.x][player.y--] != '*')
			return true;
		else
			return false;
	case PlayerMovement::RIGHT:
		if (board[player.x][player.y++] != '*')
			return true;
		else
			return false;

	}
}