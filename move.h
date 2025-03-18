#pragma once
#include "board.h"

bool checkMovement(BoardCell** board, PlayerMovement move)
{
	int rows;
	int columns;
	initializeBoard(board, rows, columns);
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)
		{
			if (board[i][j] == BoardCell::PLAYER)
			{
				switch (move)
				{
				case PlayerMovement::UP:
					if (board[i-1][j] != BoardCell::WALL)
					{
						return true;
					}
					else
					{
						return false;
					}
				case PlayerMovement::DOWN:
					if (board[i+1][j] != BoardCell::WALL)
					{
						return true;
					}
					else
					{
						return false;
					}
				case PlayerMovement::LEFT:
					if (board[i][j-1] != BoardCell::WALL)
					{
						return true;
					}
					else
					{
						return false;
					}
				case PlayerMovement::RIGHT:
					if (board[i][j+1] != BoardCell::WALL)
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