#include "func.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	std::cout << "¬ведите кол-во столбцов: ";
	int columns;
	std::cin >> columns;
	std::cout << "¬ведите кол-во строк: ";
	int rows;
	std::cin >> rows;
	std::vector<std::vector<int>> matrix(rows);
	InitMatrix(matrix, rows, columns);
	std::cout << "¬ведите диапазон значений матрицы: ";
	int range;
	std::cin >> range;
	FillMatrix(matrix, range);
	PrintMatrix(matrix);
	RemoveNullRows(matrix);
}