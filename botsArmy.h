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

	void beAttacked(int damage)
	{
		int totalHP = (getNumber() - 1) * getUnitHP() + getDamagedUnitHP();
		totalHP -= damage;
		int killedUnits = damage / getUnitHP();

		if (totalHP <= 0)
		{
			std::cout << getNumber() << " " << name << " �������\n\n";
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
		std::cout << killedUnits << " " << name << " �������\n\n";
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
	char abbreviation;		// ������������

	int number;				// ���-�� ������ � ������
	int unitHP;				// �������� ������ �����
	int damagedUnitHP;		// ������� �������� ��������� ����� (���������� 40)

	int unitDamage;			// ���� ������ �����

	int x, y;				// �������		

};

class archers : public botsArmy
{
public:
	archers(
		int x,
		int y
		) :botsArmy(
		"Archers",			// ��� �����
		'A',				// ������������
		30,					// ���-�� ������
		15,					// �������� ������ �����
		15,					// ������� �������� ��������� ����� (���������� 15)
		10,					// ���� ������ �����
		x,					// ������ �������
		y)					// ������� �������
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
		"Dwarfs",			// ��� �����
		'D',				// ������������
		50,					// ���-�� ������
		20,					// �������� ������ �����
		20,					// ������� �������� ��������� ����� (���������� 40)
		4,					// ���� ������ �����
		x,					// ������ �������
		y)					// ������� �������
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
		"Centaurs",			// ��� �����
		'C',				// ������������
		70,					// ���-�� ������
		10,					// �������� ������ �����
		10,					// ������� �������� ��������� ����� (���������� 40)
		3,					// ���� ������ �����
		x,					// ������ �������
		y)					// ������� �������
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