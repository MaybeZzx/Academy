#include <iostream>
#include <vector>
#include "Func.h"

int main()

{
	std::vector<int> matrix(5);
	AddRow(matrix, 5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i, j] = 0;
			std::cout << matrix[i, j] << " ";
		}
		std::cout << std::endl;
	}
}