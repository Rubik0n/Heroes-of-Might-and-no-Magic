#pragma once
#include <string>
#include <iostream>

class playersArmyInterface
{
	virtual int attack() = 0;
	virtual void move(int x, int y) = 0;
	virtual void wait() = 0;
	virtual void getInfo() = 0;
};

class playersArmy : public playersArmyInterface
{
public:

	playersArmy(
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
	}


	void wait()
	{
		// ничего не делать :)
		return;
	};

	void move(int x, int y)
	{
		this->x = x;		// если не занята клетка
		this->y = y;

		return;
	};

	void getInfo()
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

	bool isDead()
	{
		if (getNumber() == 0)
			return true;
		else
			return false;
	};

	int getNumber()
	{
		return number;
	};

	char getAbbreviation()
	{
		return abbreviation;
	};
		
	int getUnitHP()
	{
		return unitHP;
	};

	int getDamagedUnitHP()
	{
		return damagedUnitHP;
	};
	
	int getUnitDamage()
	{
		return unitDamage;
	};

	int getX()
	{
		return x;
	};

	int getY()
	{
		return y;
	};

	

private:

	std::string name;
	char abbreviation;		// аббревиатура

	int number;				// кол-во юнитов в отряде
	int unitHP;				// здоровье одного юнита
	int damagedUnitHP;		// остаток здоровья раненного юнита (изначально 40)

	int unitDamage;			// урон одного юнита

	int x, y;				// позиция				
};

class vampireLords : public playersArmy
{
public:

	vampireLords(
		int number,
		int x,
		int y
		) :playersArmy(
		"Vampire Lords",	// имя юнита
		'V',				// аббревиатура
		number,				// кол-во юнитов
		40,					// здоровье одного юнита
		40,					// остаток здоровья раненного юнита (изначально 40)
		8,					// урон одного юнита
		x,
		y)
	{
		this->number = number;
		this->x = x;
		this->y = y;
	}

	int attack()
	{
		int totalDamage = getNumber() *getUnitDamage();
		std::cout << "Урона нанесено: " << totalDamage << std::endl;
		return totalDamage;
	};

private:

	int number;				// кол-во юнитов в отряде 
	int x, y;				// позиция				
};

class lichs : public playersArmy
{
public:
	lichs(
		int number,
		int x,
		int y
		) :playersArmy(
		"Lichs",			// имя юнита
		'L',				// аббревиатура
		number,				// кол-во юнитов
		30,					// здоровье одного юнита
		30,					// остаток здоровья раненного юнита (изначально 40)
		15,					// урон одного юнита
		x,
		y)
	{
		this->number = number;
		this->x = x;
		this->y = y;
	}

	int attack()
	{

		return 0;
	};

private:
	
	int number;				// кол-во юнитов в отряде 
	int x, y;				// позиция		

};

class skeletons :public playersArmy
{
public:
	skeletons(
		int number,
		int x,
		int y
		) :playersArmy(
		"Skeletons",		// имя юнита
		'S',				// аббревиатура
		number,				// кол-во юнитов
		6,					// здоровье одного юнита
		6,					// остаток здоровья раненного юнита (изначально 40)
		3,					// урон одного юнита
		x,
		y)
	{
		this->number = number;
		this->x = x;
		this->y = y;
	}

	int attack()
	{

		return 0;
	};

private:

	int number;				// кол-во юнитов в отряде 
	int x, y;				// позиция	
};
