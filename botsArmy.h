#pragma once
#include <string>
#include <iostream>

class botsArmyInterface
{
	virtual int attack() = 0;
	virtual void move(int x, int y) = 0;
	virtual void getInfo() = 0;
	virtual void beAttacked(int damage) = 0;
};

class botsArmy : public botsArmyInterface
{
public:

	botsArmy(
		std::string name,
		char abbreviation,
		int number,
		int unitHP,
		int damagedUnitHP,
		int unitDamage,
		int x,
		int y
		);

	void move(int x, int y);
	void getInfo();
	void beAttacked(int damage);


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
	char abbreviation;		// аббревиатура

	int number;				// кол-во юнитов в отряде
	int unitHP;				// здоровье одного юнита
	int damagedUnitHP;		// остаток здоровья раненного юнита (изначально 40)

	int unitDamage;			// урон одного юнита

	int x, y;				// позиция		

};

class archers : public botsArmy
{
public:
	
	archers(int x, int y);
	int attack();
	
private:
	int x, y;
};

class dwarfs :public botsArmy
{
public:
	
	dwarfs(int x, int y);
	int attack();

private:
	int x, y;
};

class centaurs :public botsArmy
{
public:
	
	centaurs(int x,	int y);
	int attack();
	
private:
	int x, y;
};