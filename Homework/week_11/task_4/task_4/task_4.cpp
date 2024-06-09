#include <iostream>
#include "ShowCard.h"

int main()
{	
	setlocale(LC_ALL, "rus");
	std::cout << "Выберите масть карты:" << std::endl;
	std::cout << "1. Крести" << std::endl;
	std::cout << "2. Бубны" << std::endl;
	std::cout << "3. Черви" << std::endl;
	std::cout << "4. Пики\n: ";
	int choiceSuit;
	std::cin >> choiceSuit;
	if (choiceSuit < 1 || choiceSuit > 4)
	{
		std::cout << "Выбрана неверная масть!" << std::endl;
		return 1;
	}
	std::cout << "\nВыберите карту (2-10, J - 11, Q - 12, K - 13, A - 14):" << std::endl;
	int choiceCard;
	std::cin >> choiceCard;
	if (choiceCard < 2 || choiceCard> 14)
	{
		std::cout << "Выбрана неверная карта!" << std::endl;
		return 1;
	}
	ShowCard(choiceSuit, choiceCard);
	system("pause");
}