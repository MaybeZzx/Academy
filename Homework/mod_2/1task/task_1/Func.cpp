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
void MoveElement(std::vector<std::vector<int>>& matrix, direction direction, int countShift)
{
	int temp;
	int row = matrix.size();
	int col = matrix[0].size();
	switch (direction)
	{
	case Up:
		for (int j = 0; j < col; ++j) {
			for(int k = 0; k < countShift; ++k)
			{
				int temp = matrix[0][j];
				for (int i = 0; i < row - 1; ++i) {
					matrix[i][j] = matrix[i + 1][j];
				}
				matrix[row - 1][j] = temp;
			}
		}
		break;
	case Right:
		for (size_t i = 0; i < row; ++i)
		{
			for (int k = 0; k < countShift; ++k)
			{
				temp = matrix[i][col - 1];
				for (size_t j = col - 1; j > 0; --j)
				{
					matrix[i][j] = matrix[i][j - 1];
				}
				matrix[i][0] = temp;
			}
		}
		break;
	case Down:
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < countShift; ++k)
			{
				int temp = matrix[row - 1][j];
				for (int i = row - 1; i > 0; i--) {
					matrix[i][j] = matrix[i - 1][j];
				}
				matrix[0][j] = temp;
			}
		}
		break;
	case Left:
		for (size_t i = 0; i < row; ++i)
		{
			for (int k = 0; k < countShift; ++k)
			{
				temp = matrix[i][0];
				for (size_t j = 0; j < col - 1; ++j)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
				matrix[i][col - 1] = temp;
			}
		}
		break;
	default:
		break;
	}
}