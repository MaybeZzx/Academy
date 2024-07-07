#include "Func.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    int rowsA, colsA, rowsB, colsB, rowsC, colsC;
    std::cout << "������� ���������� ����� � �������� ��� ������� A: ";
    std::cin >> rowsA >> colsA;
    std::cout << "������� ���������� ����� � �������� ��� ������� B: ";
    std::cin >> rowsB >> colsB;
    std::cout << "������� ���������� ����� � �������� ��� ������� C: ";
    std::cin >> rowsC >> colsC;

    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA));
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB));
    std::vector<std::vector<int>> C(rowsC, std::vector<int>(colsC));

    FillMatrix(A);
    FillMatrix(B);
    FillMatrix(C);

    std::cout << "����� ��������: ";
    std::vector<int> commonValues = FindCommonElements(A, B, C);
    PrintArr(commonValues);
    std::cout << "���������� ��������: ";
    std::vector<int> uniqueValues = FindUniqueValues(A, B, C);
    PrintArr(uniqueValues);


    std::cout << "����� �������� � � �: ";
    std::vector<int> commonValues_AC= FindCommonElements(A, C);
    PrintArr(commonValues_AC);

    std::cout << "������������� ��������: ";
    std::set<int> negativeSet;

    AddNegativeValues(A, negativeSet);
    AddNegativeValues(B, negativeSet);
    AddNegativeValues(C, negativeSet);

    std::vector<int> negativeValues;
    for (int val : negativeSet)
    {
        negativeValues.push_back(val);
    }
    PrintArr(negativeValues);
}