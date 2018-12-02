#include <conio.h>
#include "buttleField.h"
#include "playersArmy.h"
#include "botsArmy.h"



void setup()
{

	return;
};

void play()
{
	
	buttleField field;
	int number, x, y;

	// Archers' position
	x = 1;
	y = 8;
	archers Archers(x, y);
	field.cellFiller(Archers.getAbbreviation(), x, y);

	// Dwarfs' position
	x = 2;
	y = 8;
	dwarfs Dwarfs(x, y);
	field.cellFiller(Dwarfs.getAbbreviation(), x, y);

	// Centaurs' position
	x = 3;
	y = 8;
	centaurs Centaurs(x, y);
	field.cellFiller(Centaurs.getAbbreviation(), x, y);

	// Choosing Vampires' position
	field.printButtleField();
	while (true)
	{
		std::cout << "Number of Vampire Lords: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "One unit is necessary at least!\n";			
		}
	}
	while (true)
	{
		std::cout << "X position: ";
		std::cin >> x;
		std::cout << "Y position: ";
		std::cin >> y;
		if (field.cellFiller('V', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Number of Vampire Lords: " << number << std::endl;
			std::cout << "Choose another position!\n";
		}
	}
	vampireLords Vampires(number, x, y);
	system("cls");

	// Choosing Lichs' position
	field.printButtleField();
	while (true)
	{
		std::cout << "Number of Lichs: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "One unit is necessary at least!\n";
		}
	}
	while (true)
	{
		std::cout << "X position: ";
		std::cin >> x;
		std::cout << "Y position: ";
		std::cin >> y;
		if (field.cellFiller('L', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Number of Lichs:    " << number << std::endl;
			std::cout << "Choose another position!\n";
		}
	}
	lichs Lichs(number, x, y);
	system("cls");

	// Choosing Skeletons' position
	field.printButtleField();
	while (true)
	{
		std::cout << "Number of Skeletons: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "One unit is necessary at least!\n";
		}
	}
	while (true)
	{
		std::cout << "X position: ";
		std::cin >> x;
		std::cout << "Y position: ";
		std::cin >> y;
		if (field.cellFiller('S', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Number of Skeletons: " << number << std::endl;
			std::cout << "Choose another position!\n";
		}
	}
	skeletons Skelets(number, x, y);
	system("cls");
	
	// After placing information
	field.printButtleField();
	Vampires.getInfo();
	Lichs.getInfo();
	Skelets.getInfo();
	Archers.getInfo();
	Dwarfs.getInfo();
	Centaurs.getInfo();
	system("pause");
	system("cls");


	// Courses
	int action;
	while ((!Vampires.isDead() || !Lichs.isDead() || !Skelets.isDead()) &&
		(!Archers.isDead() || !Centaurs.isDead() || !Dwarfs.isDead()))
	{
		// Vampire Lords' course
		if (!Vampires.isDead())
		{
			system("cls");
			field.printButtleField();
			std::cout << "Vampire Lords' course!\n";
			Vampires.getInfo();
					
			
			std::cout << "Choose the action:\n";
			std::cout << "1 - Attack\n";
			std::cout << "2 - Change the position\n";
			std::cout << "3 - Wait\n";

			while (true)
			{
				
				std::cin >> action;

				if (action == 1 || action == 2 || action == 3)
					break;
				else
				{
					system("cls");
					field.printButtleField();
					Vampires.getInfo();
					std::cout << "Unknown command! Repeat!\n";
					std::cout << "Choose the action:\n";
					std::cout << "1 - Attack\n";
					std::cout << "2 - Change the position\n";
					std::cout << "3 - Wait\n";
					
				}
			}
			system("cls");

			switch (action)
			{
				case 1:				// attack
				{
					// whether Archers are near
					bool canAttackArchers = false;
					for (int i = -1; i <= 1; i++)
						for (int j = -1; j <= 1; j++)
						{
							if (field.cellInfo(Vampires.getX() + i, Vampires.getY() + j) == Archers.getAbbreviation())
							{
								canAttackArchers = true;
								break;
							}
						}

					// whether Centaurs are near
					bool canAttackCentaurs = false;
					for (int i = -1; i <= 1; i++)
						for (int j = -1; j <= 1; j++)
						{
							if (field.cellInfo(Vampires.getX() + i, Vampires.getY() + j) == Centaurs.getAbbreviation())
							{
								canAttackCentaurs = true;
								break;
							}
						}

					// whether Dwarfs are near
					bool canAttackDwarfs = false;
					for (int i = -1; i <= 1; i++)
						for (int j = -1; j <= 1; j++)
						{
							if (field.cellInfo(Vampires.getX() + i, Vampires.getY() + j) == Dwarfs.getAbbreviation())
							{
								canAttackDwarfs = true;
								break;
							}
						}

					// if it's possible to attack someone
					if (canAttackArchers || canAttackCentaurs || canAttackDwarfs)
					{
						system("cls");
						field.printButtleField();
						Vampires.getInfo();
												
						if (canAttackArchers)
							Archers.getInfo();
												
						if (canAttackCentaurs)
							Centaurs.getInfo();
						
						if (canAttackDwarfs)
							Dwarfs.getInfo();
						

						std::cout << "Choose the enemy: ";
						if (canAttackArchers)
							std::cout << "Archers ";
						if (canAttackCentaurs)
							std::cout << "Centaurs ";
						if (canAttackDwarfs)
							std::cout << "Dwarfs";
						std::cout << "\n";


						std::string target;
						while (true)
						{
							std::cin >> target;
							if (target == "Archers" || target == "Centaurs" || target == "Dwarfs")
							{
								// if target - Archers
								if (target == "Archers")										
								{
									if (canAttackArchers)
									{
										system("cls");
										field.printButtleField();
										Vampires.getInfo();
										Archers.getInfo();

										Archers.beAttacked(Vampires.attack());
										if (Archers.isDead())
											field.cellCleaner(Archers.getX(), Archers.getY());

										field.printButtleField();
										Archers.getInfo();

										break;
									}
									else // incorrect choosing
									{
										if (Archers.isDead())
											std::cout << "Archers are dead! Choose another target!\n\n";
										else
											std::cout << "You can't attack Archers! Choose another target!\n\n";
										continue;
									}
								}

								// if target - Centaurs
								if (target == "Centaurs")
								{
									if (canAttackCentaurs)
									{
										system("cls");
										field.printButtleField();
										Vampires.getInfo();
										Centaurs.getInfo();

										Centaurs.beAttacked(Vampires.attack());
										if (Centaurs.isDead())
											field.cellCleaner(Centaurs.getX(), Centaurs.getY());

										field.printButtleField();
										Centaurs.getInfo();

										break;
									}
									else // incorrect choosing
									{
										if (Centaurs.isDead())
											std::cout << "Centaurs are dead! Choose another target!\n\n";
										else
											std::cout << "You can't attack Centaurs! Choose another target!\n\n";
										continue;
									}
								}

								// if target - Dwarfs
								if (target == "Dwarfs")
								{
									if (canAttackDwarfs)
									{
										system("cls");
										field.printButtleField();
										Vampires.getInfo();
										Dwarfs.getInfo();

										Dwarfs.beAttacked(Vampires.attack());
										if (Dwarfs.isDead())
											field.cellCleaner(Dwarfs.getX(), Dwarfs.getY());

										field.printButtleField();
										Dwarfs.getInfo();

										break;
									}
									else // incorrect choosing
									{
										if (Dwarfs.isDead())
											std::cout << "Dwarfs are dead! Choose another target!\n\n";
										else
											std::cout << "You can't attack Centaurs! Choose another target!\n\n";
										continue;
									}
								}
							}
							else
							{
								std::cout << "Incorrect input!\n";
								continue;
							}
						}
					}

					else		// if Vampires can attack noone
					{
						system("cls");
						field.printButtleField();
						Vampires.getInfo();
						std::cout << "There is nobody nearby! Choose another action!\n";
						std::cout << "1 - Change the position\n";
						std::cout << "2 - Wait\n";
						
						int correctAction;

						while (true)
						{

							std::cin >> correctAction;

							if (correctAction == 1 || correctAction == 2)
								break;
							else
							{
								system("cls");
								field.printButtleField();
								Vampires.getInfo();
								std::cout << "Unknown command! Repeat!\n";
								std::cout << "1 - Change the position\n";
								std::cout << "2 - Wait\n";
							}
						}

						switch (correctAction)
						{
							case 1:		// change the position
							{
								system("cls");
								field.printButtleField();
								while (true)
								{
									std::cout << "Vampire Lords' course!\n";
									std::cout << "Change X position: ";
									std::cin >> x;
									std::cout << "Change Y position: ";
									std::cin >> y;
									if (field.cellFiller('V', x, y))
										break;
									else
									{
										system("cls");
										field.printButtleField();
										std::cout << "Choose another position!\n";
									}
								}
								field.cellCleaner(Vampires.getX(), Vampires.getY());
								Vampires.move(x, y);
								system("cls");
								field.printButtleField();


								break;
							}
							case 2:		// wait
							{
								Vampires.wait();
								break;
							}
							default:
								break;
						}
					}

					break;
				}
				case 2:		// change the position
				{
					
					field.printButtleField();
					while (true)
					{
						std::cout << "Vampire Lords' course!\n";
						std::cout << "Change X position: ";
						std::cin >> x;
						std::cout << "Change Y position: ";
						std::cin >> y;
						if (field.cellFiller('V', x, y))
							break;
						else
						{
							system("cls");
							field.printButtleField();
							std::cout << "Choose another position!\n";
						}
					}
					field.cellCleaner(Vampires.getX(), Vampires.getY());
					Vampires.move(x, y);
					system("cls");
					field.printButtleField();

					break;
				}
				case 3:		// wait
				{
					Vampires.wait();
					break;
				}
				default:
					break;
			}
			
			system("pause");
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Centaurs' course
		if (!Centaurs.isDead())
		{

		}

		// Lichs' course
		if (!Lichs.isDead())
		{

		}

		// Archers' course
		if (!Archers.isDead())
		{

		}

		// Skeletons' course
		if (!Skelets.isDead())
		{

		}

		// Dwarfs' course
		if (!Dwarfs.isDead())
		{

		}


		//_getch();














	}

	system("cls");
	field.printButtleField();
	if (Archers.isDead() && Centaurs.isDead() && Dwarfs.isDead())
		std::cout << "Victory!\n";
	else
		std::cout << "Defeat!\n";

	return;
};


int main()
{
	setlocale(0, "rus");

	
	play();
	
	
	

	_getch();
	return 0;
}