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
		return;
	};

	void move(int x, int y)
	{
		this->x = x;		
		this->y = y;

		return;
	};

	void getInfo()
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
	char abbreviation;		// abbreviation

	int number;				// number of units
	int unitHP;				// one unit's HP
	int damagedUnitHP;		// HP remained

	int unitDamage;			// one unit's damage

	int x, y;				// position				
};

class vampireLords : public playersArmy
{
public:

	vampireLords(
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
	}

	int attack()
	{
		int totalDamage = getNumber() *getUnitDamage();
		std::cout << "Damage dealt: " << totalDamage << std::endl;
		return totalDamage;
	};

private:

	int number;				// number of units in the group 
	int x, y;				// position				
};

class lichs : public playersArmy
{
public:
	lichs(
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
	}

	int attack()
	{

		return 0;
	};

private:
	
	int number;				// number of units in the group 
	int x, y;				// position		

};

class skeletons :public playersArmy
{
public:
	skeletons(
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
	}

	int attack()
	{

		return 0;
	};

private:

	int number;				// number of units in the group 
	int x, y;				// position
};
