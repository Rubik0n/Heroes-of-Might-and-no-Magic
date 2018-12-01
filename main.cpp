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

	// ������� ��������
	x = 1;
	y = 8;
	archers Archers(x, y);
	field.cellFiller(Archers.getAbbreviation(), x, y);

	// ������� ������
	x = 2;
	y = 8;
	dwarfs Dwarfs(x, y);
	field.cellFiller(Dwarfs.getAbbreviation(), x, y);

	// ������� ���������
	x = 3;
	y = 8;
	centaurs Centaurs(x, y);
	field.cellFiller(Centaurs.getAbbreviation(), x, y);

	// ����� ������� ��������
	field.printButtleField();
	while (true)
	{
		std::cout << "���-�� Vampire Lords: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "������ ���� ���� �� ���� ����!\n";			
		}
	}
	while (true)
	{
		std::cout << "������ �������:       ";
		std::cin >> x;
		std::cout << "������� �������:      ";
		std::cin >> y;
		if (field.cellFiller('V', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "���-�� Vampire Lords: " << number << std::endl;
			std::cout << "�������� ������ �������!\n";
		}
	}
	vampireLords Vampires(number, x, y);
	system("cls");

	// ����� ������� �����
	field.printButtleField();
	while (true)
	{
		std::cout << "���-�� Lichs:    ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "������ ���� ���� �� ���� ����!\n";
		}
	}
	while (true)
	{
		std::cout << "������ �������:  ";
		std::cin >> x;
		std::cout << "������� �������: ";
		std::cin >> y;
		if (field.cellFiller('L', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "���-�� Lichs:    " << number << std::endl;
			std::cout << "�������� ������ �������!\n";
		}
	}
	lichs Lichs(number, x, y);
	system("cls");

	// ����� ������� ��������
	field.printButtleField();
	while (true)
	{
		std::cout << "���-�� Skeletons: ";
		std::cin >> number;
		if (number > 0)
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "������ ���� ���� �� ���� ����!\n";
		}
	}
	while (true)
	{
		std::cout << "������ �������:   ";
		std::cin >> x;
		std::cout << "������� �������:  ";
		std::cin >> y;
		if (field.cellFiller('S', x, y))
			break;
		else
		{
			system("cls");
			field.printButtleField();
			std::cout << "���-�� Skeletons: " << number << std::endl;
			std::cout << "�������� ������ �������!\n";
		}
	}
	skeletons Skelets(number, x, y);
	system("cls");
	
	// ���������� ����� ������������ �����
	field.printButtleField();
	Vampires.getInfo();
	Lichs.getInfo();
	Skelets.getInfo();
	Archers.getInfo();
	Dwarfs.getInfo();
	Centaurs.getInfo();
	system("pause");
	system("cls");


	// ���� 
	int action;
	while ((!Vampires.isDead() || !Lichs.isDead() || !Skelets.isDead()) &&
		(!Archers.isDead() || !Centaurs.isDead() || !Dwarfs.isDead()))
	{
		// ��� ������ ������
		if (!Vampires.isDead())
		{
			system("cls");
			field.printButtleField();
			std::cout << "��� Vampire Lords!\n";
			Vampires.getInfo();

			
			

			//���� �� ����� ��������� ������
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
			
			
			
			std::cout << "�������� ��������:\n";
			std::cout << "1 - ���������\n";
			std::cout << "2 - �������� �������\n";
			std::cout << "3 - �������� �� �����\n";

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
					std::cout << "����������� �������! ��������� ����!\n";
					std::cout << "�������� ��������:\n";
					std::cout << "1 - ���������\n";
					std::cout << "2 - �������� �������\n";
					std::cout << "3 - �������� �� �����\n";
					
				}
			}
			system("cls");

			switch (action)
			{
				case 1:				// ���������
				{
					// ���� �� ����� �������
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

					// ���� �� ����� ��������
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

					// ���� �� ����� �����
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

					// ���� ���� ���� ���������
					if (canAttackArchers || canAttackCentaurs || canAttackDwarfs)
					{
						system("cls");
						field.printButtleField();
						Vampires.getInfo();
						
											
						// ���� �� ����� �������;  ���� ���� - ����� ���� � ���
						if (canAttackArchers)
							Archers.getInfo();
												
						// ���� �� ����� ��������;  ���� ���� - ����� ���� � ���
						if (canAttackCentaurs)
							Centaurs.getInfo();
						
						// ���� �� ����� �����;  ���� ���� - ����� ���� � ���
						if (canAttackDwarfs)
							Dwarfs.getInfo();
						

						std::cout << "��������, ���� ���������: ";
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
								// ���� ���� Archers
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
									else // ���� �� ������ ����� ��� ������, ������� ������ ���������
									{
										if (Archers.isDead())
											std::cout << "Archers ��� ������! �������� ������ ����!\n\n";
										else
											std::cout << "�� �� ������ ��������� Archers! �������� ������ ����!\n\n";
										continue;
									}
								}

								// ���� ���� Centaurs
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
									else // ���� �� ������ ����� ��� ������, ������� ������ ���������
									{
										if (Centaurs.isDead())
											std::cout << "Centaurs ��� ������! �������� ������ ����!\n\n";
										else
											std::cout << "�� �� ������ ��������� Centaurs! �������� ������ ����!\n\n";
										continue;
									}
								}

								// ���� ���� Dwarfs
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
									else // ���� �� ������ ����� ��� ������, ������� ������ ���������
									{
										if (Dwarfs.isDead())
											std::cout << "Dwarfs ��� ������! �������� ������ ����!\n\n";
										else
											std::cout << "�� �� ������ ��������� Dwarfs! �������� ������ ����!\n\n";
										continue;
									}
								}
							}
							else
							{
								std::cout << "������������ ����!\n";
								continue;
							}
						}
					}

					else		// ���� ������ ���������
					{
						system("cls");
						field.printButtleField();
						Vampires.getInfo();
						std::cout << "����� ������ ���! �������� ������ ��������!\n";
						std::cout << "1 - �������� �������\n";
						std::cout << "2 - �������� �� �����\n";
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
								std::cout << "����������� �������! ��������� ����!\n";
								std::cout << "1 - �������� �������\n";
								std::cout << "2 - �������� �� �����\n";
							}
						}

						switch (correctAction)
						{
							case 1:		// �������� �������
							{
								system("cls");
								field.printButtleField();
								while (true)
								{
									std::cout << "��� Vampires Lords!\n";
									std::cout << "������� �� ������� �� X: ";
									std::cin >> x;
									std::cout << "������� �� ������� �� Y: ";
									std::cin >> y;
									if (field.cellFiller('V', x, y))
										break;
									else
									{
										system("cls");
										field.printButtleField();
										std::cout << "�������� ������ �������!\n";
									}
								}
								field.cellCleaner(Vampires.getX(), Vampires.getY());
								Vampires.move(x, y);
								system("cls");
								field.printButtleField();


								break;
							}
							case 2:		// �������� �� �����
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
				case 2:		// �������� �������
				{
					
					field.printButtleField();
					while (true)
					{
						std::cout << "��� Vampires Lords!\n";
						std::cout << "������� �� ������� �� X: ";
						std::cin >> x;
						std::cout << "������� �� ������� �� Y: ";
						std::cin >> y;
						if (field.cellFiller('V', x, y))
							break;
						else
						{
							system("cls");
							field.printButtleField();
							std::cout << "�������� ������ �������!\n";
						}
					}
					field.cellCleaner(Vampires.getX(), Vampires.getY());
					Vampires.move(x, y);
					system("cls");
					field.printButtleField();

					break;
				}
				case 3:		// �������� �� �����
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

		// ��� Centaurs
		if (!Centaurs.isDead())
		{

		}

		// ��� Lichs
		if (!Lichs.isDead())
		{

		}

		// ��� Archers
		if (!Archers.isDead())
		{

		}

		// ��� Skeletons
		if (!Skelets.isDead())
		{

		}

		// ��� Dwarfs
		if (!Dwarfs.isDead())
		{

		}


		//_getch();














	}

	system("cls");
	field.printButtleField();
	if (Archers.isDead() && Centaurs.isDead() && Dwarfs.isDead())
		std::cout << "������!\n";
	else
		std::cout << "���������!\n";

	return;
};


int main()
{
	setlocale(0, "rus");

	
	play();
	
	
	

	_getch();
	return 0;
}