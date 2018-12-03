#pragma once
#include <string>

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
		);
	
	void wait();
	void move(int x, int y);
	void getInfo();
	

	bool isDead();
	int getNumber();
	char getAbbreviation();
	int getUnitHP();
	int getDamagedUnitHP();
	int getUnitDamage();
	int getX();
	int getY();
	
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

	vampireLords(int number, int x, int y);
	int attack();
	
private:

	int number;				// number of units in the group 
	int x, y;				// position				
};

class lichs : public playersArmy
{
public:
	
	lichs(int number, int x, int y);
	int attack();
	
private:
	
	int number;				// number of units in the group 
	int x, y;				// position		

};

class skeletons :public playersArmy
{
public:
	
	skeletons(int number, int x, int y);
	int attack();

private:

	int number;				// number of units in the group 
	int x, y;				// position
};
