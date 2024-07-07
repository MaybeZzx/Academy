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

	std::cout <<"Максимальный элемент: " << FindMax(arr) << std::endl;
	std::cout << "Минимальный элемент: " << FindMin(arr) << std::endl;

	std::cout << "Отсортированный массив: ";
	SortArray(arr);
	PrintArray(arr);

	std::cout << "Измененный массив: ";
	EditArray(arr, 2, '+');
	PrintArray(arr);

}