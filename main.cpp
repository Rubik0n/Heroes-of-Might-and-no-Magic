#include <conio.h>
#include "buttleField.h"
#include "army.h"
#include <ctime>
#include "player.h"


#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	srand(time(0));

	army *vampiresPlayer = new vampireLords(4, 1, 1);
	army *lichsPlayer = new lichs(5, 2, 2);
	army *archersPlayer = new archers(5, 3, 4);

	army *archersBot = new archers(40, 2, 7);
	army *centaursBot = new centaurs(40, 1, 6);
	army *dwarfsBot = new dwarfs(40, 3, 8);
	
	player *Player = new player(1, 3, new army *[3]{vampiresPlayer, lichsPlayer, archersPlayer});
	player *Bot = new bot (2, 3, new army*[3]{archersBot, centaursBot, dwarfsBot});
	
	int currentPlayer;
		
	while (Player->isAlive() && Bot->isAlive())
	{
		int action;
		std::string groupName;
		std::string targetName;
				
		cout << "Choose group of ur army for action: \n";
		Player->getArmyInfo();
		cin >> groupName;
				
		cout << "Choose action: \n";
		cout << "1 - Attack\n";
		cout << "2 - Move\n";
		cout << "3 - Wait\n\n";
		cin >> action;
		
				
		if (action == 1)
		{
			cout << "Choose target: \n";
			Bot->getArmyInfo();
			cin >> targetName;

			cout << groupName << " attacked " << targetName << endl;
			Player->attack(groupName, Bot, targetName);
			_getch();
			system("cls");
		}
					
		if (action == 2)
		{
			int x, y;
			cout << "Choose new position: \n";
			cout << "X: ";
			cin >> x;
			cout << "Y: ";
			cin >> y;
			Player->move(groupName, x, y);
		}
		
		if (action == 3)
			Player->wait();
			
				
		cout << "\n\n";

		///////////////////////////////////////////////////////////////
		//Bot always wants to attack
		Bot->attack(groupName, Player, targetName);
		_getch();
	}


	if (Player->isAlive())
		cout << "Player won!\n";
	else
		cout << "Bot won!\n";
	

	_getch();
	return 0;
}