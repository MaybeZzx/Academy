#include <iostream>
#include "Func.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    const int size = 10;
    int* A = new int[size];
    int* B = new int[size];
    std::cout << "A: ";
    for (int i = 0; i < size; ++i)
    {
        A[i] = rand() % 100;
        std::cout << A[i] << " ";
    }
    std::cout << "\nB: ";
    for (int i = 0; i < size; ++i)
    {
        B[i] = rand() % 100;
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;
    int choice;
    std::cout << std::endl;
    std::cout << "\tΜενώ:\n1. max\n2. min\n3. avg\n: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        std::cout << "\nMax: " << Action(A, B, size, size, max);
        break;
    case 2:
        std::cout << "\nMin: " << Action(A, B, size, size, min);
        break;
    case 3:
        std::cout << "\nAverage: " << Action(A, B, size, size, avg);
        break;
    default:
        break;
    }
    delete[] A;
    delete[] B;
}