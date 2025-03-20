#pragma once

bool gameOver(int rows, int columns, Player player)
{
	if (board[player.x][player.y] == 'S')  // If you step on a spike, the game ends.
		return true;

	// Verify if there are gems left
	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < columns; j++)
		{
			if (board[i][j] == 'G')
				return false; // If there's still 1 gem left, the game continues
		}
	}
	return true; // If there are no gems left
}