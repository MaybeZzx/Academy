#include <iostream>
#include "Func.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size = 5;
	int* arr = AllocateMemory(size);
	InitArray(arr, size);
	std::cout << "Инициализация массива: ";
	PrintArray(arr, size);

	AddElement(arr, size, 20);
	std::cout << "Добавление элемента: ";
	PrintArray(arr, size);

	InsertElement(arr, size, 55, 5);
	std::cout << "Ввод элемента: ";
	PrintArray(arr, size);

	DeleteElement(arr, size, 2);
	std::cout << "Удаление элемента: ";
	PrintArray(arr, size);

	DeleteArray(arr);
	return 0;
}