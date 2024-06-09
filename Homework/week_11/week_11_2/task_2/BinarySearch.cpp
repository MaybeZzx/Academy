int BinarySearch(int key, int arr[], int size) 
{
    int l = 0; 
    int r = size-1; 
    int mid;

    while ((l <= r)) 
    {
        mid = (l + r) / 2; 
        if (arr[mid] == key) return mid; 
        if (arr[mid] > key) r = mid - 1; 
        else l = mid + 1;
    }
    return 0;
}