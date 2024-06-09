#include <iostream>

void ShowCard(int suit, int num)
{
	// Условие (suit == 2 || suit == 3) сделано для более красивого вывода карты
	
	char charCard[13] = { '2','3','4','5','6','7','8','9','0','J','Q','K','A'};

	if (suit < 1 || suit > 4 || num < 2 || num > 14)
	{
		std::cout << "Выбрана неверная карта!" << std::endl;
		return;
	}
	std::cout << "\nКарта:" << std::endl;
	if (suit == 3 || suit == 2)
		std::cout << "\t.--------.\n\t|";
	else
		std::cout << "\t.-------.\n\t|";

	if (num == 10)
	{
		std::cout << '1';
		std::cout << charCard[num - 2];
	}
	else
	{
		std::cout << charCard[num - 2];
		std::cout << ' ';
	}

	if (suit == 3 || suit == 2)
		std::cout << "      |" << std::endl;
	else
		std::cout << "     |" << std::endl;

	switch (suit) {
	case 1:
		std::cout << "\t|   _   |\n\t|  ( )  |\n\t| (_x_) |\n\t|   Y   |" << std::endl;
		break;
	case 2:
		std::cout << "\t|   /\\   |\n\t|  /  \\  |\n\t|  \\  /  |\n\t|   \\/   |" << std::endl;
		break;
	case 3:
		std::cout << "\t|  _  _  |\n\t| ( \\/ ) |\n\t|  \\  /  |\n\t|   \\/   |" << std::endl;
		break;
	case 4:
		std::cout << "\t|   .   |\n\t|  / \\  |\n\t| (_,_) |\n\t|   I   |" << std::endl;
		break;
	}

	if (suit == 3 || suit == 2) 
		std::cout << "\t|      ";
	else
		std::cout << "\t|     ";

	if (num == 10)
		std::cout << '1';
	else
		std::cout << ' ';

	std::cout << charCard[num-2];
	if (suit == 3 || suit == 2)
		std::cout << "|\n\t'--------'" << std::endl;
	else
		std::cout << "|\n\t'-------'" << std::endl;

}

