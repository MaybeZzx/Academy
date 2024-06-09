#include <iostream>
int FindKey(int key, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}