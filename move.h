#pragma once
#include "board.h"
#include "GameOver.h"

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

bool checkMovement(Player* player, PlayerMovement move)
{
	int newX = player->x;
	int newY = player->y;

	switch (move)
	{
		case PlayerMovement::UP:
			newX--;
			break;
		case PlayerMovement::DOWN:
			newX++;
			break;
		case PlayerMovement::LEFT:
			newY--;
			break;
		case PlayerMovement::RIGHT:
			newY++;
			break;
		default:
			return false;
	}
	system("cls");

	// Check if movement is valid
	if (board[newX][newY] == '*') 
	{
		std::cout << "Invalid movement. Try again\n";
		return false;
		system("cls");
	}
	return true;
}

void movePlayer(int rows, int columns, Player player)
{
	char input;

	while (!gameOver(rows, columns, &player))
	{
		std::cout << "Move with W A S D, Q for exiting: ";
		std::cin >> input;
		if (input == 'q' || input == 'Q')
			break;

		PlayerMovement move = translateInput(input);

		if (checkMovement(&player, move))
		{
			board[player.x][player.y] = ' '; // Delete last position
			switch (move)
			{
			case PlayerMovement::UP:
				player.x--;
				break;
			case PlayerMovement::DOWN:
				player.x++;
				break;
			case PlayerMovement::LEFT:
				player.y--;
				break;
			case PlayerMovement::RIGHT:
				player.y++;
				break;
			}
			if (gameOver(rows, columns, &player)) {
				std::cout << "GAME OVER!!\n";
				break;
			}

			board[player.x][player.y] = 'P'; // New player's position
		}
		printBoard(rows, columns);
	}
}