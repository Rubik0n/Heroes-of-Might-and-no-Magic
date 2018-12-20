#include "player.h"
#include <iostream>
#include <ctime>

player::player(int teamNumber, int countArmies, army **armies)
{
	this->armies = armies;
	this->countArmies = countArmies;
	this->teamNumber = teamNumber;
};

player::~player()
{
	delete[] armies;
};

void player::getArmyInfo()
{
	if (countArmies < 1)
	{
		std::cout << "Army is empty!\n";
		return;
	}

	std::cout << "Team number: " << teamNumber << std::endl;
	for (int i = 0; i < countArmies; i++)
	{
		armies[i]->getInfo();
		std::cout << std::endl;
	}
	return;
};

void player::attack(std::string attacker, player *defensePlayer, std::string defenseGroup)
{
	int dealDamage;
	for (int i = 0; i < countArmies; i++)
		if (armies[i]->getName() == attacker)
		{
			dealDamage = armies[i]->dealDamage();
			break;
		}

	for (int i = 0; i < defensePlayer->getCountArmies(); i++)
		if (defensePlayer->armies[i]->getName() == defenseGroup)
		{
			defensePlayer->armies[i]->beAttacked(dealDamage);
			break;
		}

	return;
};

void player::move(std::string group, int x, int y)
{
	for (int i = 0; i < countArmies; i++)
		if (armies[i]->getName() == group)
		{
			armies[i]->move(x, y);
			break;
		}
	return;
};

void player::wait()
{
	return;
};

bool player::isAlive()
{
	for (int i = 0; i < countArmies; i++)
		if (!armies[i]->isDead())
			return true;
	return false;
};

int player::getCountArmies()
{
	return countArmies;
};
