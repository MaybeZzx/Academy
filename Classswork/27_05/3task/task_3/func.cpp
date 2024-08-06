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
std::vector<std::vector<int>> MultMatrices(const std::vector<std::vector<int>>& firstMatrix, const std::vector<std::vector<int>>& secondMatrix)
{
	if (firstMatrix[0].size() != secondMatrix.size())
	{
		std::cout << "Умножение невозможно!" << std::endl;
		return std::vector<std::vector<int>>(0);
	}
	
	std::vector<std::vector<int>> newMatrix(firstMatrix.size());
	InitMatrix(newMatrix, newMatrix.size(), secondMatrix[0].size());

	for (int x = 0; x < newMatrix.size(); ++x)
	{
		for (int y = 0; y < newMatrix[0].size(); ++y)
		{
			newMatrix[x][y] = 0;
			for (int k = 0; k < newMatrix.size(); ++k)
			{
				newMatrix[x][y] += firstMatrix[x][k] * secondMatrix[k][y];
			}
		}
	}

	return newMatrix;
}