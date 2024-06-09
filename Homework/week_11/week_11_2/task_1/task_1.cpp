#include <iostream>
#include "FindKey.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	const int size = 20;
	int arr[size];
	std::cout << "��������������� ������: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "������� ���� ��� ������: ";
	int key;
	std::cin >> key;
	int res = FindKey(key, arr, size);
	if (res != -1)
	{
		std::cout << "������: " << res << std::endl;
	}
	else
	{
		std::cout << "����e�� �� ������" << std::endl;
	}
}