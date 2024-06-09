#include <iostream>
#include <algorithm>
#include "BinarySearch.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	const int size = 20;
	int arr[size];
	std::cout << "—генерированный массив: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::sort(arr, arr + size);
	std::cout << "ќтсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "¬ведите ключ дл€ поиска: ";
	int key;
	std::cin >> key;
	
	int res = BinarySearch(key, arr, size);
	if (res != -1)
	{
		std::cout << "»ндекс: " << res << std::endl;
	}
	else
	{
		std::cout << "Ёлемeнт не найден" << std::endl;
	}
}