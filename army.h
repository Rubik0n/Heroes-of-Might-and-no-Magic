#pragma once
#include <string>


class armyInterface
{
	virtual int dealDamage() = 0;
	virtual void beAttacked(int damage) = 0;
	virtual void move(int x, int y) = 0;
	virtual void wait() = 0;
	virtual void getInfo() = 0;
	virtual void sayWhoWeAre() = 0;
};

class army
{
public:
	army(
		std::string name,
		char abbreviation,
		int number,
		int unitHP,
		int damagedUnitHP,
		int unitDamage,
		int x,
		int y
		);

	int dealDamage();
	void beAttacked(int damage);
	void move(int x, int y);
	void wait();
	void getInfo();
	void sayWhoWeAre();

	std::string getName();
	bool isDead();
	int getNumber();
	char getAbbreviation();
	int getUnitHP();
	int getDamagedUnitHP();
	int getUnitDamage();
	int getX();
	int getY();

private:
	std::string name;		// name
	char abbreviation;		// abbreviation
	int number;				// number of units
	int unitHP;				// one unit's HP
	int damagedUnitHP;		// HP remained
	int unitDamage;			// one unit's damage
	int x, y;				// position		
};

class vampireLords : public army
{
public:
	vampireLords(int number, int x, int y);
	void sayWhoWeAre();

private:
	int number;				// number of units
	int x, y;				// position	
};

class lichs : public army
{
public:

	lichs(int number, int x, int y);
	void sayWhoWeAre();

private:
	int number;				
	int x, y;					
};

class skeletons :public army
{
public:
	skeletons(int number, int x, int y);
	void sayWhoWeAre();

private:

	int number;				
	int x, y;				
};

class archers : public army
{
public:
	archers(int number, int x, int y);
	void sayWhoWeAre();

private:
	int number;				
	int x, y;				
};

class centaurs : public army
{
public:
	centaurs(int number, int x, int y);
	void sayWhoWeAre();

private:
	int number;				
	int x, y;					
};

class dwarfs: public army
{
public:
	dwarfs(int number, int x, int y);
	void sayWhoWeAre();

private:
	int number;				
	int x, y;					
};