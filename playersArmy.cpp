#include "playersArmy.h"
#include <iostream>

playersArmy::playersArmy(
	std::string name,
	char abbreviation,
	int number,
	int unitHP,
	int damagedUnitHP,
	int unitDamage,
	int x,
	int y)
{
	this->name = name;
	this->abbreviation = abbreviation;
	this->number = number;
	this->unitHP = unitHP;
	this->damagedUnitHP = damagedUnitHP;
	this->unitDamage = unitDamage;
	this->x = x;
	this->y = y;
};

void playersArmy::wait()
{
	return;
};

void playersArmy::move(int x, int y)
{
	this->x = x;
	this->y = y;

	return;
};

void playersArmy::getInfo()
{
	for (int i = 0; i < name.length(); i++)
		std::cout << name[i];
	std::cout << std::endl;
	std::cout << "Damage:      ";
	std::cout << getUnitDamage() << std::endl;
	std::cout << "Number:      ";
	std::cout << getNumber() << std::endl;
	std::cout << "HP:          ";
	std::cout << getUnitHP() << std::endl;
	std::cout << "HP remained: ";
	std::cout << getDamagedUnitHP() << std::endl;
	std::cout << std::endl;
	return;
};

bool playersArmy::isDead()
{
	if (getNumber() == 0)
		return true;
	else
		return false;
};

int playersArmy::getNumber()
{
	return number;
};

char playersArmy::getAbbreviation()
{
	return abbreviation;
};

int playersArmy::getUnitHP()
{
	return unitHP;
};

int playersArmy::getDamagedUnitHP()
{
	return damagedUnitHP;
};

int playersArmy::getUnitDamage()
{
	return unitDamage;
};

int playersArmy::getX()
{
	return x;
};

int playersArmy::getY()
{
	return y;
};



vampireLords::vampireLords(
	int number,
	int x,
	int y
	) :playersArmy(
	"Vampire Lords",	// name
	'V',				// abbreviation
	number,				// number of units
	40,					// one unit's HP
	40,					// HP remained
	8,					// one unit's damage
	x,
	y)
{
	this->number = number;
	this->x = x;
	this->y = y;
};

int vampireLords::attack()
{
	int totalDamage = getNumber() *getUnitDamage();
	std::cout << "Damage dealt: " << totalDamage << std::endl;
	return totalDamage;
};

lichs::lichs(
	int number,
	int x,
	int y
	) :playersArmy(
	"Lichs",			// name
	'L',				// abbreviation
	number,				// number of units
	30,					// one unit's HP
	30,					// HP remained
	15,					// one unit's damage
	x,
	y)
{
	this->number = number;
	this->x = x;
	this->y = y;
};

int lichs::attack()
{
	return 0;
};

skeletons::skeletons(
	int number,
	int x,
	int y
	) :playersArmy(
	"Skeletons",		// name
	'S',				// abbreviation
	number,				// number of units
	6,					// one unit's HP
	6,					// HP remained
	3,					// one unit's damage
	x,
	y)
{
	this->number = number;
	this->x = x;
	this->y = y;
};

int skeletons::attack()
{
	return 0;
};