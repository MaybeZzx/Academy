#include <iostream>
#include <string>
#include "ToDec.h"
int main()
{
	setlocale(LC_ALL, "rus");
	std::string numStr;
	std::cout << "Введите число в двоичной СС: ";
	std::getline(std::cin, numStr);
	int i = 0;

	//	Проверка на СС
	while (i < numStr.size())
	{
		if (numStr[i] != '1' && numStr[i] != '0')
		{
			std::cout << "Введено число в неверной СС!";
			return 1;
		}
		i++;
	}
	int num = std::stoi(numStr);

	std::cout << "Число " << num << " в десятичной СС = " << ToDec(num) << std::endl;
}