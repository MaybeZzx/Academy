#include <vector>
#include <iostream>

void PrintMatrix(std::vector<std::vector<int>>& matrix, const int& row, const int& col)
{
	for (auto& substr : matrix)
	{
		for (auto& num : substr)
		{
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
}
void FillMatrix(std::vector<std::vector<int>>& matrix, const int& row, const int& col)
{
	for (auto& substr : matrix)
	{
		for (auto& num : substr)
		{
			num = rand() % 10;
		}
	}
	PrintMatrix(matrix, row, col);
}

void SumMatrix(std::vector<std::vector<int>>& matrix_1, std::vector<std::vector<int>>& matrix_2, std::vector<std::vector<int>>& matrix_res, const int& row, const int& col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			matrix_res[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}
	PrintMatrix(matrix_res, row, col);
}