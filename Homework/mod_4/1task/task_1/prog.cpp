#define CHAR
#include "function.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	std::vector<char> arr(30);
	FillArray(arr);
	PrintArray(arr);
	std::cout << std::endl;

	std::cout <<"������������ �������: " << FindMax(arr) << std::endl;
	std::cout << "����������� �������: " << FindMin(arr) << std::endl;

	std::cout << "��������������� ������: ";
	SortArray(arr);
	PrintArray(arr);

	std::cout << "���������� ������: ";
	EditArray(arr, 2, '+');
	PrintArray(arr);

}