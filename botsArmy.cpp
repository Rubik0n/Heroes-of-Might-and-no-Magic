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
	std::cout << "Урон:             ";
	std::cout << getUnitDamage() << std::endl;
	std::cout << "Кол-во:           ";
	std::cout << getNumber() << std::endl;
	std::cout << "Здоровье:         ";
	std::cout << getUnitHP() << std::endl;
	std::cout << "Остаток здоровья: ";
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
		std::cout << getNumber() << " " << name << " погибло\n\n";
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
	std::cout << killedUnits << " " << name << " погибло\n\n";
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
	"Archers",			// имя юнита
	'A',				// аббревиатура
	30,					// кол-во юнитов
	15,					// здоровье одного юнита
	15,					// остаток здоровья раненного юнита (изначально 15)
	10,					// урон одного юнита
	x,					// строка позиции
	y)					// столбец позиции
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
	"Dwarfs",			// имя юнита
	'D',				// аббревиатура
	50,					// кол-во юнитов
	20,					// здоровье одного юнита
	20,					// остаток здоровья раненного юнита (изначально 40)
	4,					// урон одного юнита
	x,					// строка позиции
	y)					// столбец позиции
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
	"Centaurs",			// имя юнита
	'C',				// аббревиатура
	70,					// кол-во юнитов
	10,					// здоровье одного юнита
	10,					// остаток здоровья раненного юнита (изначально 40)
	3,					// урон одного юнита
	x,					// строка позиции
	y)					// столбец позиции
{
	this->x = x;
	this->y = y;
};

int centaurs::attack()
{
	return 0;
}