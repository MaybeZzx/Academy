#include "func.h"

const int range = 20;

void InitMatrix(std::vector<std::vector<int>>& matrix, const int& rows, const int& columns)
{
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = std::vector<int>(columns);
	}
}

void FillMatrix(std::vector<std::vector<int>>& matrix)
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

std::vector<std::vector<int>> SumMatrices(const std::vector<std::vector<int>>& firstMatrix, const std::vector<std::vector<int>>& secondMatrix)
{
	std::vector<std::vector<int>> totalMatrix(firstMatrix.size());
	InitMatrix(totalMatrix, totalMatrix.size(), firstMatrix[0].size());

	for (int x = 0; x < totalMatrix.size(); ++x)
	{
		for (int y = 0; y < totalMatrix[0].size(); y++)
		{
			totalMatrix[x][y] = firstMatrix[x][y] + secondMatrix[x][y];
		}
	}
	return totalMatrix;
}