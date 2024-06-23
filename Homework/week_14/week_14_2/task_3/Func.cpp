#include <iostream>

void SeparateArr(
                  int* arr, const int size, int*& posArr,
                  int& posSize, int*& negArr, 
                  int& negSize, int*& zeroArr, int& zeroSize
                ) 
{
    posSize = 0;
    negSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posSize++;
        }
        else if (arr[i] < 0) {
            negSize++;
        }
        else {
            zeroSize++;
        }
    }

    posArr = new int[posSize];
    negArr = new int[negSize];
    zeroArr = new int[zeroSize];

    int ipos = 0;
    int ineg = 0;
    int izero = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posArr[ipos] = arr[i];
            ipos++;
        }
        else if (arr[i] < 0) {
            negArr[ineg] = arr[i];
            ineg++;
        }
        else {
            zeroArr[izero] = arr[i];
            izero++;
        }
    }
}

