#pragma once
#include "cin.h"

void initializeBoard(char** &board, int& rows, int& columns, Player player)
{
	FileInput(rows, columns);
	// Creating a dynamic array with the number of rows
	// and columns established by the txt
	board = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		board[i] = new char[columns];
	}

	// Establishing what each cell will have
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if ((i == 0 && j < columns) || (j == 0 && i < rows) ||
				(i == rows - 1 && j < columns) || (j == columns - 1 && i < rows))
			{
				board[i][j] = "*";
			}
			else
			{
				board[i][j] = " ";
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
		if (board[x][y] == " ")
		{
			board[x][y] = "S";
		}
	}

	// Initializing the cells that will have gems
	int numGems = rand() % (maxGems + 1);
	for (int i = 0;i < maxGems;i++)
	{
		int x = rand() % (rows - 2) + 1;
		int y = rand() % (columns - 2) + 1;
		if (board[x][y] == " ")
		{
			board[x][y] = "G";
		}
	}

	// Initializing in which cell the player will spawn
	player.x = rand() % (rows - 2) + 1;
	player.y = rand() % (columns - 2) + 1;
	if (player.x >= 1 && player.x < (rows - 1) && player.y >= 1
		&& player.y < (columns - 1))
	{
		board[player.x][player.y] = "P";
	}
}
