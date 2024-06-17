#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	const int SIZE = 10;
	int arr1[SIZE];
	int arr2[SIZE];
	for (int index = 0; index < SIZE; ++index)
	{
		arr1[index] = rand() % 10;
		std::cout << arr1[index] << " ";
	}
	std::cout << std::endl;

	int* parr1 = arr1;
	int* parr2 = arr2;
	int* end{ arr1 + SIZE };

	while(parr1 != end){
		*parr2 = *parr1;
		std::cout << *parr2 << ' ';
		parr2++;
		parr1++;
	}
	std::cout << std::endl;

	
}