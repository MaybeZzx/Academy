#include <iostream>
#include "ShowCard.h"

int main()
{	
	setlocale(LC_ALL, "rus");
	std::cout << "�������� ����� �����:" << std::endl;
	std::cout << "1. ������" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "4. ����\n: ";
	int choiceSuit;
	std::cin >> choiceSuit;
	if (choiceSuit < 1 || choiceSuit > 4)
	{
		std::cout << "������� �������� �����!" << std::endl;
		return 1;
	}
	std::cout << "\n�������� ����� (2-10, J - 11, Q - 12, K - 13, A - 14):" << std::endl;
	int choiceCard;
	std::cin >> choiceCard;
	if (choiceCard < 2 || choiceCard> 14)
	{
		std::cout << "������� �������� �����!" << std::endl;
		return 1;
	}
	ShowCard(choiceSuit, choiceCard);
	system("pause");
}