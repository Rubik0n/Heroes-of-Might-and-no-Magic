#pragma once

class buttleFieldInterface
{
	virtual bool cellFiller(char abbreviation, int x, int y) = 0;
	virtual void cellCleaner(int x, int y) = 0;
	virtual char cellInfo(int x, int y) = 0;
	virtual void printButtleField() = 0;
};

class buttleField :public buttleFieldInterface
{
public:
	buttleField();
	bool cellFiller(char abbreviation, int x, int y);
	void cellCleaner(int x, int y);
	char cellInfo(int x, int y);
	void printButtleField();
	
private:
	char field[5][10];
};