#include <vector>
#include <iostream>

enum direction {
	Up,
	Right,
	Down,
	Left
};

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

void AddColumnAt(std::vector<std::vector<int>>& matrix, int pos , int value = 0)
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
void MoveElement(std::vector<std::vector<int>>& matrix, direction direction)
{
	int temp;
	int row = matrix.size() - 1;
	int col = matrix[0].size() - 1;
	switch (direction)
	{
	case Up:
		break;
	case Right:
		for (size_t i = 0; i <row; ++i)
		{
			temp = matrix[i][col];
			for (size_t j = 0; j < col; ++j)
			{
				std::cout << matrix[i][j] << " " << matrix[i][j + 1] << std::endl;
				matrix[i][j] = matrix[i][j + 1];

			}
			matrix[i][0] = temp;
			std::cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << " " << matrix[i][3] << " " << matrix[i][4] << " " << std::endl;
		}
		break;
	case Down:
		break;
	case Left:
		for (size_t i = 0; i < row; ++i)
		{
			temp = matrix[i][0];
			for (size_t j = col; j > 0; --j)
			{
				std::cout << matrix[i][j] << " " << matrix[i][j - 1] << std::endl;
				matrix[i][j] = matrix[i][j - 1];
			}
			matrix[i][col] = temp;
			std::cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << " " << matrix[i][3] << " " << matrix[i][4] << " " << std::endl;
		}
		break;
	default:
		break;
	}
}