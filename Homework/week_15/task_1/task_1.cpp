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
        A[i] = rand() % 20;
        std::cout << A[i] << " ";
    }
    std::cout << "\nB: ";
    for (int i = 0; i < size; ++i)
    {
        B[i] = rand() % 20;
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;
    std::cout << Action(A, B, size);
}