#include "func.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	std::cout << "������� ���-�� ��������: ";
	int columns;
	std::cin >> columns;
	std::cout << "������� ���-�� �����: ";
	int rows;
	std::cin >> rows;
	std::vector<std::vector<int>> matrix(rows);
	InitMatrix(matrix, rows, columns);
	std::cout << "������� �������� �������� �������: ";
	int range;
	std::cin >> range;
	FillMatrix(matrix, range);
	PrintMatrix(matrix);
	RemoveNullRows(matrix);
}