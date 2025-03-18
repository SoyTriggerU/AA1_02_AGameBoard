#pragma once
#include "cin.h"

enum class BoardCell
{
	WALL,
	SPIKE,
	GEM,
	PLAYER,
	EMPTY
};

void initializeBoard(BoardCell** &board, int& rows, int& columns)
{
	FileInput(rows, columns);
	// Creating a dynamic array with the number of rows
	// and columns established by the txt
	board = new BoardCell* [rows];

	for (int i = 0; i < rows; i++)
	{
		board[i] = new BoardCell[columns];
	}

	// Establishing what each cell will have
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if ((i == 0 && j < columns) || (j == 0 && i < rows) ||
				(i == rows - 1 && j < columns) || (j == columns - 1 && i < rows))
			{
				board[i][j] = BoardCell::WALL;
			}
			else
			{
				board[i][j] = BoardCell::EMPTY;
			}
		}
	}

	int totalCells = (rows - 2) + (columns - 2);
	int maxSpikes = totalCells / 10;
	int maxGems = totalCells / 4;

	// Initializing the cells that will have spikes
	int numSpikes = rand() % (maxSpikes + 1);
	for (int i = 0;i < numSpikes;i++)
	{
		int x = rand() % (rows - 2) + 1;
		int y = rand() % (columns - 2) + 1;
		if (board[x][y] == BoardCell::EMPTY)
		{
			board[x][y] = BoardCell::SPIKE;
		}
	}

	// Initializing the cells that will have gems
	int numGems = rand() % (maxGems + 1);
	for (int i = 0;i < maxGems;i++)
	{
		int x = rand() % (rows - 2) + 1;
		int y = rand() % (columns - 2) + 1;
		if (board[x][y] == BoardCell::EMPTY)
		{
			board[x][y] = BoardCell::GEM;
		}
	}

	// Initializing in which cell the player will spawn
	int spawnPlayerX = rand() % (rows - 2) + 1;
	int spawnPlayerY = rand() % (columns - 2) + 1;
	if (spawnPlayerX >= 1 && spawnPlayerX < (rows - 1) && spawnPlayerY >= 1
		&& spawnPlayerY < (columns - 1))
	{
		board[spawnPlayerX][spawnPlayerY] = BoardCell::PLAYER;
	}
}
