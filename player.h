#pragma once
#include "army.h"
#include <vector>
#include <iostream>

class playerInterface
{
	//virtual void addArmy(army newArmy) = 0;
	//virtual void getArmyInfo() = 0;
	virtual void action(int actionNumber) = 0;
};

class player: public playerInterface
{
	
public:
	player()
	{
		
	};

	void getArmyInfo()
	{
		/*if (countArmies < 1)
		{
			std::cout << "Army is empty!\n";
			return;
		}

		for (int i = 0; i < countArmies; i++)
		{
			armies[i].getInfo();
			std::cout << std::endl;
		}*/
		return;
	};

	

	void action(int actionNumber)
	{
		switch (actionNumber)
		{
		case 1:
			attack();
			break;
		case 2:
			move();
			break;
		case 3:
			wait();
			break;

		default:
			break;
		}
		return;
	};

	void attack()
	{
		return;
	};
	void move()
	{

	};
	void wait()
	{

	};

private:
	
	
};

//class bot: public player
//{
//public:
//	//bot();
//	void action(int actionNumber);
//
//private:
//
//};