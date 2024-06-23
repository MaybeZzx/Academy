#include <iostream>
#include "Func.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int size = 10;
	int* arr = new int[size];

	std::cout << "Изначальный массив: ";
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 15;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int* arr_2 = RemovePrimes(arr, size);
	std::cout << "Полученный массив: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr_2[i] << " ";
	}
	std::cout << std::endl;
}