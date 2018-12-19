#include "army.h"
#include <iostream>

army::army(
	std::string name,
	char abbreviation,
	int number,
	int unitHP,
	int damagedUnitHP,
	int unitDamage,
	int x,
	int y
	)
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

int army::dealDamage()
{
	int totalDamage = getNumber() * getUnitDamage();
	return totalDamage;
};

void army::beAttacked(int damage)
{
	int totalHP = (getNumber() - 1) * getUnitHP() + getDamagedUnitHP();
	totalHP -= damage;
	int killedUnits = damage / getUnitHP();

	if (totalHP <= 0)
	{
		std::cout << getNumber() << " " << name << " died\n\n";
		number = 0;
		damagedUnitHP = 0;
		return;
	}

	if (totalHP % getUnitHP() != 0)
	{
		number = totalHP / getUnitHP() + 1;
		damagedUnitHP = totalHP % getUnitHP();
	}
	else
	{
		number = totalHP / getUnitHP();
		damagedUnitHP = getUnitHP();
	}
	std::cout << killedUnits << " " << name << " died\n\n";
	return;
};

void army::move(int x, int y)
{
	this->x = x;
	this->y = y;

	return;
};

void army::wait()
{
	return;
};

void army::getInfo()
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

void army::sayWhoWeAre()
{
	std::cout << "We r the greatest army!!!\n";
	return;
};

bool army::isDead()
{
	if (getNumber() <= 0)
		return true;
	else
		return false;
};

int army::getNumber()
{
	return number;
};

char army::getAbbreviation()
{
	return abbreviation;
};

int army::getUnitHP()
{
	return unitHP;
};

int army::getDamagedUnitHP()
{
	return damagedUnitHP;
};

int army::getUnitDamage()
{
	return unitDamage;
};

int army::getX()
{
	return x;
};

int army::getY()
{
	return y;
};


vampireLords::vampireLords(
	int number,
	int x,
	int y
	) :army(
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

void vampireLords::sayWhoWeAre()
{
	std::cout << "We r Vampire Lords!!!\n";
	return;
};

lichs::lichs(
	int number,
	int x,
	int y
	) :army(
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

void lichs::sayWhoWeAre()
{
	std::cout << "We r Lichs!!!\n";
	return;
};

skeletons::skeletons(
	int number,
	int x,
	int y
	) :army(
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

void skeletons::sayWhoWeAre()
{
	std::cout << "We r Skeletons!!!\n";
	return;
};

archers::archers(
	int number,
	int x,
	int y
	) : army(
	"Archers",			// name
	'A',				// abbreviation
	number,				// number of units
	15,					// one unit's HP
	15,					// HP remained
	10,					// one unit's damage
	x,
	y)
{
	this->number = number;
	this->x = x;
	this->y = y;
};

void archers::sayWhoWeAre()
{
	std::cout << "We r Archers!!!\n";
	return;
};

centaurs::centaurs(
	int number,
	int x,
	int y
	) :army(
	"Centaurs",			// name
	'C',				// abbreviation
	number,				// number of units
	10,					// one unit's HP
	10,					// HP remained
	3,					// one unit's damage
	x,
	y)
{
	this->number = number;
	this->x = x;
	this->y = y;
};

void centaurs::sayWhoWeAre()
{
	std::cout << "We r Centaurs!!!\n";
	return;
};

dwarfs::dwarfs(
	int number,
	int x,
	int y
	) : army(
	"Dwarfs",			// name
	'D',				// abbreviation
	number,				// number of units
	20,					// one unit's HP
	20,					// HP remained
	4,					// one unit's damage
	x,
	y)
{
	this->number = number;
	this->x = x;
	this->y = y;
};

void dwarfs::sayWhoWeAre()
{
	std::cout << "We r Dwarfs!!!\n";
	return;
};