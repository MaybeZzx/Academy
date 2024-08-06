#include "func.h"




void InitMatrix(std::vector<std::vector<int>>& matrix, const int& rows, const int& columns)
{
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = std::vector<int>(columns);
	}
}

void FillMatrix(std::vector<std::vector<int>>& matrix, const int& range)
{
	for (int x = 0; x < matrix.size(); ++x)
	{
		for (int y = 0; y < matrix[0].size(); ++y)
		{
			matrix[x][y] = rand() % range;
		}
	}
}

void PrintMatrix(const std::vector<std::vector<int>>& matrix)
{
	std::cout << std::endl;
	for (int x = 0; x < matrix.size(); ++x)
	{
		std::cout << "  ";
		for (int y = 0; y < matrix[0].size(); ++y)
		{
			std::cout << matrix[x][y] << " ";
		}
		std::cout << std::endl;
	}
}

void RemoveNullRows(std::vector<std::vector<int>>& matrix)
{
	std::vector<std::vector<int>> newMatrix;

	for (int x = 0; x < matrix.size(); ++x)
	{
		bool isZero = false;
		for (int y = 0; y < matrix[0].size(); ++y)
		{
			if (matrix[x][y] == 0)
			{
				isZero = true;
				break;
			}
		}
		if (!isZero)
		{
			newMatrix.push_back(matrix[x]);
		}
	}
	matrix = newMatrix;
}