#include "Func.h"

int main()
{
	srand(time(NULL));
	std::vector<std::vector<int>> matrix(5, std::vector<int> (5));
	FillMatrix(matrix, 5, 5);

	std::cout << "\n==============================\n" << std::endl;
	MoveElement(matrix, direction::Left, 1);
	PrintMatrix(matrix, 5, 5);
}