#include <iostream>
#include <vector>
#include "RemoveNull.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	std::cout << "������� ���-�� �����: ";
	int row;
	std::cin >> row;
	std::cout << "������� ���-�� ��������: ";
	int col;
	std::cin >> col;

	std::vector<std::vector<int>> matrix(row, std::vector<int>(col));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			matrix[i][j] = rand() % 10;
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n������ ����� �������� ����� � ������: " << std::endl;
	RemoveNull(matrix, row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}