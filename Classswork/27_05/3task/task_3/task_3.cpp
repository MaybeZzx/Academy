#include "func.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int rows;
	int columns;

	std::cout << "¬ведите кол-во столбцов дл€ 1-й матрицы: ";
	std::cin >> columns;
	std::cout << "¬ведите кол-во строк: ";
	std::cin >> rows;

	std::vector<std::vector<int>> firstMatrix(rows);
	InitMatrix(firstMatrix, rows, columns);
	FillMatrix(firstMatrix);

	std::cout << "¬ведите кол-во столбцов дл€ 2-й матрицы: ";
	std::cin >> columns;
	std::cout << "¬ведите кол-во строк: ";
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
