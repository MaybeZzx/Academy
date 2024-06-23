#pragma once
void SeparateArr(
    int* arr, const int size, int*& positiveArr,
    int& positiveSize, int*& negativeArr,
    int& negativeSize, int*& zeroArr, int& zeroSize
);