bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}
int* RemovePrimes(int* arr, int& size)
{
    int j = 0;
    for (int i = 0; i < size; ++i)
    {
        if (!isPrime(arr[i]))
            arr[j++] = arr[i];
    }
    size = j;
    int* arr_2 = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr_2[i] = arr[i];
    }
    return arr_2;
}