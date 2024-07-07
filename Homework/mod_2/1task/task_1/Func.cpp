#include "Func.h"

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

void AddColumnAt(std::vector<std::vector<int>>& matrix, int pos , int value)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		matrix[i].insert(matrix[i].begin() + pos, value);
	}
}
void RemoveColumn(std::vector<std::vector<int>>& matrix, int pos)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		matrix[i].erase(matrix[i].begin() + pos);
	}
}
void MovingHorizontally(std::vector<std::vector<int>>& matrix, int countShift, int direction)
{
	size_t temp;
	size_t row = matrix.size();
	size_t col = matrix[0].size();
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t k = 0; k < countShift; ++k)
		{
			if (direction == 1)
			{
				temp = matrix[i][col - 1];
				for (size_t j = col - 1; j > 0; --j)
				{
					matrix[i][j] = matrix[i][j - 1];
				}
				matrix[i][0] = temp;
			}
			else
			{
				temp = matrix[i][0];
				for (size_t j = 0; j < col - 1; ++j)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
				matrix[i][col - 1] = temp;
			}
		}
	}
}
void MovingVertically(std::vector<std::vector<int>>& matrix, int countShift, int direction)
{
	size_t temp;
	size_t row = matrix.size();
	size_t col = matrix[0].size();
	for (size_t j = 0; j < col; ++j) {
		for (size_t k = 0; k < countShift; ++k)
		{
			if (direction == 1)
			{
				temp = matrix[0][j];
				for (size_t i = 0; i < row - 1; ++i)
				{
					matrix[i][j] = matrix[i + 1][j];
				}
				matrix[row - 1][j] = temp;
			}
			else
			{
				temp = matrix[row - 1][j];
				for (size_t i = row - 1; i > 0; i--) {
					matrix[i][j] = matrix[i - 1][j];
				}
				matrix[0][j] = temp;
			}
		}
	}
}
void MoveElement(std::vector<std::vector<int>>& matrix, direction direction, int countShift)
{
	switch (direction)
	{
	case Up:
		MovingVertically(matrix, countShift, 1);
		break;
	case Right:
		MovingHorizontally(matrix, countShift, 1);
		break;
	case Down:
		MovingVertically(matrix, countShift, 0);
		break;
	case Left:
		MovingHorizontally(matrix, countShift, 0);
		break;
	default:
		break;
	}
}