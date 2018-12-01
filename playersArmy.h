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
		// ������ �� ������ :)
		return;
	};

	void move(int x, int y)
	{
		this->x = x;		// ���� �� ������ ������
		this->y = y;

		return;
	};

	void getInfo()
	{
		for (int i = 0; i < name.length(); i++)
			std::cout << name[i];
		std::cout << std::endl;
		std::cout << "����:             ";
		std::cout << getUnitDamage() << std::endl;
		std::cout << "���-��:           ";
		std::cout << getNumber() << std::endl;
		std::cout << "��������:         ";
		std::cout << getUnitHP() << std::endl;
		std::cout << "������� ��������: ";
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
	char abbreviation;		// ������������

	int number;				// ���-�� ������ � ������
	int unitHP;				// �������� ������ �����
	int damagedUnitHP;		// ������� �������� ��������� ����� (���������� 40)

	int unitDamage;			// ���� ������ �����

	int x, y;				// �������				
};

class vampireLords : public playersArmy
{
public:

	vampireLords(
		int number,
		int x,
		int y
		) :playersArmy(
		"Vampire Lords",	// ��� �����
		'V',				// ������������
		number,				// ���-�� ������
		40,					// �������� ������ �����
		40,					// ������� �������� ��������� ����� (���������� 40)
		8,					// ���� ������ �����
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
		std::cout << "����� ��������: " << totalDamage << std::endl;
		return totalDamage;
	};

private:

	int number;				// ���-�� ������ � ������ 
	int x, y;				// �������				
};

class lichs : public playersArmy
{
public:
	lichs(
		int number,
		int x,
		int y
		) :playersArmy(
		"Lichs",			// ��� �����
		'L',				// ������������
		number,				// ���-�� ������
		30,					// �������� ������ �����
		30,					// ������� �������� ��������� ����� (���������� 40)
		15,					// ���� ������ �����
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
	
	int number;				// ���-�� ������ � ������ 
	int x, y;				// �������		

};

class skeletons :public playersArmy
{
public:
	skeletons(
		int number,
		int x,
		int y
		) :playersArmy(
		"Skeletons",		// ��� �����
		'S',				// ������������
		number,				// ���-�� ������
		6,					// �������� ������ �����
		6,					// ������� �������� ��������� ����� (���������� 40)
		3,					// ���� ������ �����
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

	int number;				// ���-�� ������ � ������ 
	int x, y;				// �������	
};
