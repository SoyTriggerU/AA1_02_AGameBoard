#include "move.h"
#include "GameOver.h"

int main()
{
	Player player;
	int rows;
	int columns;

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		std::string label;
		myFile >> label >> rows;
		myFile >> label >> columns;

		myFile.close();
	}
	else
	{
		std::cout << "The configuration file could not be opened.\n";
		return 1;
	}

	initializeBoard(rows, columns, player);
	printBoard(rows, columns);

	char input;

	while (!gameOver(rows, columns, player))
	{
		std::cout << "Move with W A S D, Q for exiting: ";
		std::cin >> input;
		if (input == 'q' || input == 'Q')
			break;

		PlayerMovement move = translateInput(input);
		int newX;
		int newY;

		if (checkMovement(player, move, rows, columns, newX, newY))
		{
			board[player.x][player.y] = ' ';
			player.x = newX;
			player.y = newY;
			board[player.x][player.y] = 'P';
		}
		else
		{
			std::cout << "Invalid movement!. Try again\n";
		}
		system("cls");
		printBoard(rows, columns);
	}

	std::cout << "GAME OVER!!\n";

	for (int i = 0; i < rows; i++)
		delete[] board[i];
	delete[] board;

	return 0;
}