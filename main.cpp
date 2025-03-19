#include "move.h"

int main() 
{
	Player player;
	int rows;
	int columns;

	std::string file;
	std::ifstream myFile("exemple.txt");
	if (myFile.is_open())
	{
		myFile >> file >> rows;
		myFile >> file >> columns;

		myFile.close();
	}

	board = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		board[i] = new char[columns];
	}

	initializeBoard(rows, columns, player);
	printBoard(rows, columns);
}