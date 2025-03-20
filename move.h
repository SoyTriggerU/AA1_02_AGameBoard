#pragma once
#include "board.h"

// mirar si funciona
PlayerMovement translateInput(char input)
{
	switch (input)
	{
	case 'w': 
	case 'W':
		return PlayerMovement::UP;
	case 's':
	case 'S':
		return PlayerMovement::DOWN;
	case 'a':
	case 'A':
		return PlayerMovement::LEFT;
	case 'd':
	case 'D':
		return PlayerMovement::RIGHT;
	default:
		return PlayerMovement::UP;  //Movement by default in case of invalid input
	}
}

bool checkMovement(Player player, PlayerMovement move, int rows, int columns, int& newX, int& newY)
{
	newX = player.x;
	newY = player.y;

	switch (move)
	{
		case PlayerMovement::UP:
		{
			newX--;
			break;
		}
		case PlayerMovement::DOWN:
		{
			newX++;
			break;
		}
		case PlayerMovement::LEFT:
		{
			newY--;
			break;
		}
		case PlayerMovement::RIGHT:
		{
			newY++;
			break;
		}

		// Check if movement is valid
		if (newX <= 0 || newX >= rows - 1 || newY <= 0 || newY >= columns - 1 || board[newX][newY] == '*')
		{
			std::cout << "Invalid movement. Try again\n";
			return false;
		}

		return true;
	}
}