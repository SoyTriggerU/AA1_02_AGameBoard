#pragma once
#include <iostream>
#include <fstream>
#include <string>

void FileInput(int rows, int columns)
{
	std::string file;
	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		myFile >> file >> rows;
		myFile >> file >> columns;

		myFile.close();
	}
}