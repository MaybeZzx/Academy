#include <iostream>
#include "isHappy.h"

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "������� 6-�� ������� �����: ";
	int num;
	std::cin >> num;
	if (num < 0)
	{
		std::cout << "\n������������� ����� �� �����������!" << std::endl;
		return -1;
	}
	int res = isHappy(num);
	if (res)
	{
		std::cout << "\n����� �������� ����������" << std::endl;
	}
	else
	{
		std::cout << "\n����� �� �������� ����������" << std::endl;
	}
}