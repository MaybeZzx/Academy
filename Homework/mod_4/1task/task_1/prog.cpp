#define DOUBLE
#include "function.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	std::vector<double> arr(30);
	FillArray(arr);
	PrintArray(arr);
	std::cout << std::endl;
	std::cout <<"������������ �������: " << FindMax(arr) << std::endl;
	std::cout << "����������� �������: " << FindMin(arr) << std::endl;
	SortArray(arr);
	std::cout << "��������������� ������: ";
	PrintArray(arr);

}