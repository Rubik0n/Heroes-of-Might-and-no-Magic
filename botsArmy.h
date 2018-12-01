#pragma once
#include <string>
#include <iostream>

class botsArmyInterface
{
	virtual void attack(std::string target) = 0;
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

	void beAttacked(int damage)
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

	bool isDead()
	{
		if (getNumber() <= 0)
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

class archers : public botsArmy
{
public:
	archers(
		int x,
		int y
		) :botsArmy(
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
	}

	void attack(std::string target)
	{

		return;
	};

	

private:
	int x, y;
};

class dwarfs :public botsArmy
{
public:
	dwarfs(
		int x,
		int y
		) :botsArmy(
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
	}

	void attack(std::string target)
	{

		return;
	};

private:
	int x, y;
};

class centaurs :public botsArmy
{
public:
	centaurs(
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
	}

	void attack(std::string target)
	{

		return;
	};

private:
	int x, y;
};