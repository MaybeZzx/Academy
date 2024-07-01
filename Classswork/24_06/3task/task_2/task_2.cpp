#include <vector>
#include <iostream>
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

	std::vector<std::vector<int>> matrix_1(row, std::vector<int>(col));
	std::vector<std::vector<int>> matrix_2(row, std::vector<int>(col));
	std::vector<std::vector<int>> matrix_res(row, std::vector<int>(col));

	std::cout << "Matrix 1: " << std::endl;
	FillMatrix(matrix_1, row, col);
	std::cout << "\nMatrix 2: " << std::endl;
	FillMatrix(matrix_2, row, col);
	std::cout << "\nMatrix 3: " << std::endl;
	SumMatrix(matrix_1,matrix_2,matrix_res, row, col);


}