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
	std::cout << "����. �������: " << MaxElemMatrix(matrixI) << std::endl;
	std::cout << "���. �������: " << MinElemMatrix(matrixI) << std::endl;
	std::cout << "��������������� �������" << std::endl << std::endl;
	SortMatrix(matrixI);
	std::cout << "------------------------------------\n" << std::endl;
	// double matrix
	InitMatrix(matrixD);
	PrintMatrix(matrixD);
	std::cout << std::endl;
	std::cout << "����. �������: " << MaxElemMatrix(matrixD) << std::endl;
	std::cout << "���. �������: " << MinElemMatrix(matrixD) << std::endl;
	std::cout << "��������������� �������" << std::endl << std::endl;
	SortMatrix(matrixD);
	std::cout << "------------------------------------\n" << std::endl;
	// char matrix
	InitMatrix(matrixCh);
	PrintMatrix(matrixCh);
	std::cout << std::endl;
	std::cout << "����. �������: " << MaxElemMatrix(matrixCh) << std::endl;
	std::cout << "���. �������: " << MinElemMatrix(matrixCh) << std::endl;
	std::cout << "��������������� �������" << std::endl << std::endl;
	SortMatrix(matrixCh);
	std::cout << "------------------------------------\n" << std::endl;
}