#include <iostream>
#include "isHappy.h"

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Введите 6-ти значное число: ";
	int num;
	std::cin >> num;
	if (num < 0)
	{
		std::cout << "\nОтрицательные числа не допускаются!" << std::endl;
		return -1;
	}
	int res = isHappy(num);
	if (res)
	{
		std::cout << "\nЧисло является счастливым" << std::endl;
	}
	else
	{
		std::cout << "\nЧисло не является счастливым" << std::endl;
	}
}