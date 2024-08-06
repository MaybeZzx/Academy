#include "func.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int rows;
	int columns;

	std::cout << "������� ���-�� �������� ��� 1-� �������: ";
	std::cin >> columns;
	std::cout << "������� ���-�� �����: ";
	std::cin >> rows;

	std::vector<std::vector<int>> firstMatrix(rows);
	InitMatrix(firstMatrix, rows, columns);
	FillMatrix(firstMatrix);

	std::cout << "������� ���-�� �������� ��� 2-� �������: ";
	std::cin >> columns;
	std::cout << "������� ���-�� �����: ";
	std::cin >> rows;

	std::vector<std::vector<int>> secondMatrix(rows);
	InitMatrix(secondMatrix, rows, columns);
	FillMatrix(secondMatrix);

	std::cout << "==========================";
	PrintMatrix(firstMatrix);
	std::cout << "==========================";
	PrintMatrix(secondMatrix);
	std::cout << "==========================";
	std::vector<std::vector<int>> totalMatrix = MultMatrices(firstMatrix, secondMatrix);
	PrintMatrix(totalMatrix);

}
