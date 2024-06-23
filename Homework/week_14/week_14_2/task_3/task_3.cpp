#include <iostream>
#include "Func.h"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    const int n = 20;
    int arr[n];
    std::cout << "Изначальный массив: ";
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 30 - 15;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int* posArr;
    int* negArr;
    int* zeroArr;
    int posSize, negSize, zeroSize;

    SeparateArr(arr, n, posArr, posSize, negArr, negSize, zeroArr, zeroSize);

    std::cout << "Положительные эл-ты: ";
    for (int i = 0; i < posSize; i++) {
        std::cout << posArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отрицательные эл-ты: ";
    for (int i = 0; i < negSize; i++) {
        std::cout << negArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Нулевые эл-ты: ";
    for (int i = 0; i < zeroSize; i++) {
        std::cout << zeroArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] posArr;
    delete[] negArr;
    delete[] zeroArr;

    return 0;
}
