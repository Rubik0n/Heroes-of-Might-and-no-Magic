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

	// Позиция Лучников
	x = 1;
	y = 8;
	archers Archers(x, y);
	field.cellFiller(Archers.getAbbreviation(), x, y);

	// Позиция Гномов
	x = 2;
	y = 8;
	dwarfs Dwarfs(x, y);
	field.cellFiller(Dwarfs.getAbbreviation(), x, y);

	// Позиция Кентавров
	x = 3;
	y = 8;
	centaurs Centaurs(x, y);
	field.cellFiller(Centaurs.getAbbreviation(), x, y);

	// Выбор позиции Вампиров
	field.printButtleField();
	while (true)
	{
		std::cout << "Кол-во Vampire Lords: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Должен быть хотя бы один юнит!\n";			
		}
	}
	while (true)
	{
		std::cout << "Строка позиции:       ";
		std::cin >> x;
		std::cout << "Столбец позиции:      ";
		std::cin >> y;
		if (field.cellFiller('V', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Кол-во Vampire Lords: " << number << std::endl;
			std::cout << "Выберете другую позицию!\n";
		}
	}
	vampireLords Vampires(number, x, y);
	system("cls");

	// Выбор позиции Личей
	field.printButtleField();
	while (true)
	{
		std::cout << "Кол-во Lichs:    ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Должен быть хотя бы один юнит!\n";
		}
	}
	while (true)
	{
		std::cout << "Строка позиции:  ";
		std::cin >> x;
		std::cout << "Столбец позиции: ";
		std::cin >> y;
		if (field.cellFiller('L', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Кол-во Lichs:    " << number << std::endl;
			std::cout << "Выберете другую позицию!\n";
		}
	}
	lichs Lichs(number, x, y);
	system("cls");

	// Выбор позиции Скелетов
	field.printButtleField();
	while (true)
	{
		std::cout << "Кол-во Skeletons: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Должен быть хотя бы один юнит!\n";
		}
	}
	while (true)
	{
		std::cout << "Строка позиции:   ";
		std::cin >> x;
		std::cout << "Столбец позиции:  ";
		std::cin >> y;
		if (field.cellFiller('S', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "Кол-во Skeletons: " << number << std::endl;
			std::cout << "Выберете другую позицию!\n";
		}
	}
	skeletons Skelets(number, x, y);
	system("cls");
	
	// Информация после расставления войск
	field.printButtleField();
	Vampires.getInfo();
	Lichs.getInfo();
	Skelets.getInfo();
	Archers.getInfo();
	Dwarfs.getInfo();
	Centaurs.getInfo();
	system("pause");
	system("cls");


	// Ходы 
	int action;
	while ((!Vampires.isDead() || !Lichs.isDead() || !Skelets.isDead()) &&
		(!Archers.isDead() || !Centaurs.isDead() || !Dwarfs.isDead()))
	{
		// Ход Вампир Лордов
		if (!Vampires.isDead())
		{
			system("cls");
			field.printButtleField();
			std::cout << "Ход Vampire Lords!\n";
			Vampires.getInfo();

			
			

			//есть ли рядом вражеские отряды
			/*if (
				field.cellInfo(Vampires.getX() - 1, Vampires.getY() - 1) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX() - 1, Vampires.getY() - 1) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX() - 1, Vampires.getY() - 1) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX() - 1, Vampires.getY()) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX() - 1, Vampires.getY()) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX() - 1, Vampires.getY()) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX() - 1, Vampires.getY() + 1) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX() - 1, Vampires.getY() + 1) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX() - 1, Vampires.getY() + 1) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX(), Vampires.getY() - 1) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX(), Vampires.getY() - 1) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX(), Vampires.getY() - 1) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX(), Vampires.getY() + 1) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX(), Vampires.getY() + 1) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX(), Vampires.getY() + 1) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX() + 1, Vampires.getY() - 1) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX() + 1, Vampires.getY() - 1) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX() + 1, Vampires.getY() - 1) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX() + 1, Vampires.getY()) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX() + 1, Vampires.getY()) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX() + 1, Vampires.getY()) == Dwarfs.getAbbreviation() ||

				field.cellInfo(Vampires.getX() + 1, Vampires.getY() + 1) == Archers.getAbbreviation() ||
				field.cellInfo(Vampires.getX() + 1, Vampires.getY() + 1) == Centaurs.getAbbreviation() ||
				field.cellInfo(Vampires.getX() + 1, Vampires.getY() + 1) == Dwarfs.getAbbreviation()
				)*/
			
			
			
			std::cout << "Выберете действие:\n";
			std::cout << "1 - Атаковать\n";
			std::cout << "2 - Поменять позицию\n";
			std::cout << "3 - Остаться на месте\n";

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
					std::cout << "Неизвестная команда! Повторите ввод!\n";
					std::cout << "Выберете действие:\n";
					std::cout << "1 - Атаковать\n";
					std::cout << "2 - Поменять позицию\n";
					std::cout << "3 - Остаться на месте\n";
					
				}
			}
			system("cls");

			switch (action)
			{
				case 1:				// атаковать
				{
					// есть ли рядом лучники
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

					// есть ли рядом кентавры
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

					// есть ли рядом гномы
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

					// если есть кого атаковать
					if (canAttackArchers || canAttackCentaurs || canAttackDwarfs)
					{
						system("cls");
						field.printButtleField();
						Vampires.getInfo();
						
											
						// есть ли рядом лучники;  если есть - пишим инфу о них
						if (canAttackArchers)
							Archers.getInfo();
												
						// есть ли рядом кентавры;  если есть - пишим инфу о них
						if (canAttackCentaurs)
							Centaurs.getInfo();
						
						// есть ли рядом гномы;  если есть - пишим инфу о них
						if (canAttackDwarfs)
							Dwarfs.getInfo();
						

						std::cout << "Выберете, кого атаковать: ";
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
								// если цель Archers
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
									else // если по ошибке ввели имя отряда, который нельзя атаковать
									{
										if (Archers.isDead())
											std::cout << "Archers уже мертвы! Выберете другую цель!\n\n";
										else
											std::cout << "Вы не можете атаковать Archers! Выберете другую цель!\n\n";
										continue;
									}
								}

								// если цель Centaurs
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
									else // если по ошибке ввели имя отряда, который нельзя атаковать
									{
										if (Centaurs.isDead())
											std::cout << "Centaurs уже мертвы! Выберете другую цель!\n\n";
										else
											std::cout << "Вы не можете атаковать Centaurs! Выберете другую цель!\n\n";
										continue;
									}
								}

								// если цель Dwarfs
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
									else // если по ошибке ввели имя отряда, который нельзя атаковать
									{
										if (Dwarfs.isDead())
											std::cout << "Dwarfs уже мертвы! Выберете другую цель!\n\n";
										else
											std::cout << "Вы не можете атаковать Dwarfs! Выберете другую цель!\n\n";
										continue;
									}
								}
							}
							else
							{
								std::cout << "Некорректный ввод!\n";
								continue;
							}
						}
					}

					else		// если некого атаковать
					{
						system("cls");
						field.printButtleField();
						Vampires.getInfo();
						std::cout << "Рядом никого нет! Выберете другое действие!\n";
						std::cout << "1 - Поменять позицию\n";
						std::cout << "2 - Остаться на месте\n";
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
								std::cout << "Неизвестная команда! Повторите ввод!\n";
								std::cout << "1 - Поменять позицию\n";
								std::cout << "2 - Остаться на месте\n";
							}
						}

						switch (correctAction)
						{
							case 1:		// поменять позицию
							{
								system("cls");
								field.printButtleField();
								while (true)
								{
									std::cout << "Ход Vampires Lords!\n";
									std::cout << "Перейти на позицию по X: ";
									std::cin >> x;
									std::cout << "Перейти на позицию по Y: ";
									std::cin >> y;
									if (field.cellFiller('V', x, y))
										break;
									else
									{
										system("cls");
										field.printButtleField();
										std::cout << "Выберете другую позицию!\n";
									}
								}
								field.cellCleaner(Vampires.getX(), Vampires.getY());
								Vampires.move(x, y);
								system("cls");
								field.printButtleField();


								break;
							}
							case 2:		// остаться на месте
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
				case 2:		// поменять позицию
				{
					
					field.printButtleField();
					while (true)
					{
						std::cout << "Ход Vampires Lords!\n";
						std::cout << "Перейти на позицию по X: ";
						std::cin >> x;
						std::cout << "Перейти на позицию по Y: ";
						std::cin >> y;
						if (field.cellFiller('V', x, y))
							break;
						else
						{
							system("cls");
							field.printButtleField();
							std::cout << "Выберете другую позицию!\n";
						}
					}
					field.cellCleaner(Vampires.getX(), Vampires.getY());
					Vampires.move(x, y);
					system("cls");
					field.printButtleField();

					break;
				}
				case 3:		// остаться на месте
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

		// ход Centaurs
		if (!Centaurs.isDead())
		{

		}

		// ход Lichs
		if (!Lichs.isDead())
		{

		}

		// ход Archers
		if (!Archers.isDead())
		{

		}

		// ход Skeletons
		if (!Skelets.isDead())
		{

		}

		// ход Dwarfs
		if (!Dwarfs.isDead())
		{

		}


		//_getch();














	}

	system("cls");
	field.printButtleField();
	if (Archers.isDead() && Centaurs.isDead() && Dwarfs.isDead())
		std::cout << "Победа!\n";
	else
		std::cout << "Поражение!\n";

	return;
};


int main()
{
	setlocale(0, "rus");

	
	play();
	
	
	

	_getch();
	return 0;
}