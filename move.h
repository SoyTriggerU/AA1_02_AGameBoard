#pragma once
#include "board.h"

bool checkMovement(char** board, Player player)
{
	int rows;
	int columns;
	initializeBoard(board, rows, columns);
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)
		{
			if (board[i][j] == "P")
			{
				switch (player.move)
				{
				case PlayerMovement::UP:
					if (board[i - 1][j] != "*")
					{
						return true;
					}
					else
					{
						return false;
					}
				case PlayerMovement::DOWN:
					if (board[i+1][j] != "*")
					{
						return true;
					}
					else
					{
						return false;
					}
				case PlayerMovement::LEFT:
					if (board[i][j-1] != "*")
					{
						return true;
					}
					else
					{
						return false;
					}
				case PlayerMovement::RIGHT:
					if (board[i][j+1] != "*")
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
}