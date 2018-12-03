#include "botsArmy.h"
#include <iostream>

botsArmy::botsArmy(
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

void botsArmy::move(int x, int y)
{
	this->x = x;
	this->y = y;

	return;
};

void botsArmy::getInfo()
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

void botsArmy::beAttacked(int damage)
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

bool botsArmy::isDead()
{
	if (getNumber() <= 0)
		return true;
	else
		return false;
};

int botsArmy::getNumber()
{
	return number;
};

char botsArmy::getAbbreviation()
{
	return abbreviation;
};

int botsArmy::getUnitHP()
{
	return unitHP;
};

int botsArmy::getDamagedUnitHP()
{
	return damagedUnitHP;
};

int botsArmy::getUnitDamage()
{
	return unitDamage;
};

int botsArmy::getX()
{
	return x;
};

int botsArmy::getY()
{
	return y;
};



archers::archers(
	int x,
	int y
	) : botsArmy(
	"Archers",			// name
	'A',				// abbreviation
	30,					// number of units
	15,					// one unit's HP
	15,					// HP remained
	10,					// one unit's damage
	x,					
	y)					
{
	this->x = x;
	this->y = y;
};

int archers::attack()
{
	return 0;
};


dwarfs::dwarfs(
	int x,
	int y
	) : botsArmy(
	"Dwarfs",			// name
	'D',				// abbreviation
	50,					// number of units
	20,					// one unit's HP
	20,					// HP remained
	4,					// one unit's damage
	x,					
	y)					
{
	this->x = x;
	this->y = y;
};

int dwarfs::attack()
{
	return 0;
};


centaurs::centaurs(
	int x,
	int y
	) :botsArmy(
	"Centaurs",			// name
	'C',				// abbreviation
	70,					// number of units
	10,					// one unit's HP
	10,					// HP remained
	3,					// one unit's damage
	x,					
	y)					
{
	this->x = x;
	this->y = y;
};

int centaurs::attack()
{
	return 0;
}