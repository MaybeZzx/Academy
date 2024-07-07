#include <iostream>
#include <vector>
#include "Func.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	std::cout << "¬ведите кол-во столбцов: ";
	int col;
	std::cin >> col;
	std::cout << "¬ведите кол-во строк: ";
	int row;
	std::cin >> row;
	std::vector<std::vector<int>> matrix(row, std::vector<int>(col));
	FillMatrix(matrix, row, col);
	std::cout << "\n=================================\n" << std::endl;
	std::vector<std::vector<int>> transpMatrix = RotateMatrix(matrix);
	PrintMatrix(transpMatrix, col, row);
}