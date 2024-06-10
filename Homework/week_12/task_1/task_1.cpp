#include <iostream>
#include "MatrixFunc.h"
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int matrixI[SIZE][SIZE];
	double matrixD[SIZE][SIZE];
	char matrixCh[SIZE][SIZE];

	// int matrix
	InitMatrix(matrixI);
	PrintMatrix(matrixI);
	std::cout << std::endl;
	std::cout << "Макс. элемент: " << MaxElemMatrix(matrixI) << std::endl;
	std::cout << "Мин. элемент: " << MinElemMatrix(matrixI) << std::endl;
	std::cout << "Отсортированная матрица" << std::endl << std::endl;
	SortMatrix(matrixI);
	std::cout << "------------------------------------\n" << std::endl;
	// double matrix
	InitMatrix(matrixD);
	PrintMatrix(matrixD);
	std::cout << std::endl;
	std::cout << "Макс. элемент: " << MaxElemMatrix(matrixD) << std::endl;
	std::cout << "Мин. элемент: " << MinElemMatrix(matrixD) << std::endl;
	std::cout << "Отсортированная матрица" << std::endl << std::endl;
	SortMatrix(matrixD);
	std::cout << "------------------------------------\n" << std::endl;
	// char matrix
	InitMatrix(matrixCh);
	PrintMatrix(matrixCh);
	std::cout << std::endl;
	std::cout << "Макс. элемент: " << MaxElemMatrix(matrixCh) << std::endl;
	std::cout << "Мин. элемент: " << MinElemMatrix(matrixCh) << std::endl;
	std::cout << "Отсортированная матрица" << std::endl << std::endl;
	SortMatrix(matrixCh);
	std::cout << "------------------------------------\n" << std::endl;
}