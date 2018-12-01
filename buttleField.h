#pragma once
#include <string>
#include <iostream>

class buttleFieldInterface
{
	virtual bool cellFiller(char abbreviation, int x, int y) = 0;
	virtual void cellCleaner(int x, int y) = 0;
	virtual void printButtleField() = 0;
};

class buttleField :public buttleFieldInterface
{
public:

	buttleField()
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 10; j++)
				field[i][j] = '.';
	};
			

	bool cellFiller(char abbreviation, int x, int y)
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

	void cellCleaner(int x, int y)
	{
		field[x][y] = '.';
		return;
	};

	char cellInfo(int x, int y)
	{
		return field[x][y];
	}
	

	void printButtleField()
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

private:
	char field[5][10];

};