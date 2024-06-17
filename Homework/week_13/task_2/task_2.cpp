#include <iostream>
using namespace std;

void PrintArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    const int size = 10;
    int arr[size] = { 1,2,3,4,5,6,7,8,9,10 };
    int* parrayS = &arr[size - 1];
    int* parrayE = &arr[0];

    PrintArr(arr, size);

    for (int i = 0; i < size / 2; i++)
    {
        *parrayS ^= *parrayE; // исключающее ИЛИ
        *parrayE ^= *parrayS;
        *parrayS ^= *parrayE; 

        parrayE++;
        parrayS--;
    }
   
    PrintArr(arr, size);

    return 0;
}