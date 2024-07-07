#include <vector>
#include <iostream>


std::vector <std::vector<int>> RotateMatrix(const std::vector <std::vector<int>>& matrix)
{
	int col = matrix[0].size();
	int row = matrix.size();

	std::vector<std::vector<int>> transposedMatrix(col, std::vector<int>(row));

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			transposedMatrix[j][i] = matrix[i][j];
		}
	}
	return transposedMatrix;
}

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