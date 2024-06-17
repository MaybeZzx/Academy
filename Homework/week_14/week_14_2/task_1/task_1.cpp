#include <iostream>
#include "Func.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size = 5;
	int* arr = AllocateMemory(size);
	InitArray(arr, size);
	std::cout << "������������� �������: ";
	PrintArray(arr, size);

	AddElement(arr, size, 20);
	std::cout << "���������� ��������: ";
	PrintArray(arr, size);

	InsertElement(arr, size, 55, 5);
	std::cout << "���� ��������: ";
	PrintArray(arr, size);

	DeleteElement(arr, size, 2);
	std::cout << "�������� ��������: ";
	PrintArray(arr, size);

	DeleteArray(arr);
	return 0;
}