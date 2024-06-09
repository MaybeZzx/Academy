#include <iostream>
#include "FindPerfectNum.h"
int main()
{
	/*
		Число называется совершенным, если сумма
		всех его делителей равна ему самому.Напишите функцию
		поиска таких чисел во введенном интервале.
	*/
	setlocale(LC_ALL, "rus");
	std::cout << "Введите начало диапазона: ";
	int start;
	std::cin >> start;
	std::cout << "Введите конец диапазона: ";
	int end;
	std::cin >> end;
	std::cout << "Результат: ";
	FindPerfectNum(start, end);
	
}