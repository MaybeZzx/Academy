#define DOUBLE
#include "function.h"
#ifdef INTEGER
std::vector<int> arr(10);
#elif defined(CHAR)
std::vector<char> arr(10);
#elif defined(DOUBLE)
std::vector<double> arr(10);
#endif

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	FillArray(arr);
	PrintArray(arr);
	std::cout << std::endl;

	std::cout <<"������������ �������: " << FindMax(arr) << std::endl;
	std::cout << "����������� �������: " << FindMin(arr) << std::endl;

	std::cout << "��������������� ������: ";
	SortArray(arr);
	PrintArray(arr);

	std::cout << "���������� ������: ";
#ifdef INTEGER
	EditArray(arr, 2, 100);
#elif defined(CHAR)
	EditArray(arr, 2, '+');
#elif defined(DOUBLE)
	EditArray(arr, 2, 999.9);
#endif
	PrintArray(arr);

}