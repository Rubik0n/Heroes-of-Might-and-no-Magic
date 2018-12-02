#include "buttleField.h"
#include <iostream>

buttleField::buttleField()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++)
			field[i][j] = '.';
};

bool buttleField::cellFiller(char abbreviation, int x, int y)
{
	if ((x < 0) || (x > 9))
		return false;
	if ((y < 0) || (y > 9))
		return false;
	if (field[x][y] == '.')
	{
		field[x][y] = abbreviation;
		return true;
	}
	else
		return false;
};

void buttleField::cellCleaner(int x, int y)
{
	field[x][y] = '.';
	return;
};

char buttleField::cellInfo(int x, int y)
{
	return field[x][y];
};

void buttleField::printButtleField()
{
	std::cout << "  ";
	for (int i = 0; i < 10; i++)
		std::cout << " " << i;
	std::cout << "\n" << "  ";
	for (int i = 0; i < 10; i++)
		std::cout << "__";
	std::cout << "\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << " |\n";
		std::cout << i << "| ";
		for (int j = 0; j < 10; j++)
			std::cout << field[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
};