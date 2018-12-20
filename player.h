#pragma once
#include "army.h"
#include <vector>
#include <iostream>

class player
{
	
public:
	player(int teamNumber, int countArmies, army **armies);
	~player();
	void getArmyInfo();

	virtual void attack(std::string attacker, player *defensePlayer, std::string defenseGroup);
	void move(std::string group, int x, int y);
	void wait();

	bool isAlive();
	int getCountArmies();
		
protected:
	int teamNumber;
	int countArmies;
public:
	army **armies;
};



class bot: public player
{
public:
	bot(int teamNumber, int countArmies, army **armies) :
		player(teamNumber, countArmies, armies)
	{};
	void attack(std::string attacker, player *defensePlayer, std::string defenseGroup)
	{
		int randomAttackGroup;
		int dealDamage;
		while (true)
		{
			randomAttackGroup = rand() % countArmies;
			dealDamage = armies[randomAttackGroup]->dealDamage();
			system("cls");
			if (!armies[randomAttackGroup]->isDead())
				break;

		}

		int randomTargetGroup;
		while (true)
		{
			randomTargetGroup = rand() % (defensePlayer->getCountArmies());
			if (!defensePlayer->armies[randomTargetGroup]->isDead())
				break;
		}

		std::cout << "Team number: " << teamNumber << std::endl;
		std::cout << armies[randomAttackGroup]->getName() << " attacked " << defensePlayer->armies[randomTargetGroup]->getName();
		std::cout << std::endl;
		std::cout << "Damage dealed: " << dealDamage << std::endl;

		defensePlayer->armies[randomTargetGroup]->beAttacked(dealDamage);
		return;
	};
private:
};