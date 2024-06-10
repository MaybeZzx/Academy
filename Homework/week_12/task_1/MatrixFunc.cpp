#include <iostream>
#include <iomanip>
const int SIZE = 10;
void InitMatrix(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}
void InitMatrix(double arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = (double) rand()/RAND_MAX + rand()%10;
		}
	}
}
void InitMatrix(char arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = 'a' + rand() % 25;
		}
	}
}
void PrintMatrix(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void PrintMatrix(double arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout<< std::setprecision(3) <<arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void PrintMatrix(char arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int MaxElemMatrix(int arr[][SIZE])
{
	int max = 0;
	for (int i = 0, j = i; i < SIZE; i++)
	{
		if (arr[i][j] > max)
		{
			max = arr[i][j];
		}
	}
	return max;
}
double MaxElemMatrix(double arr[][SIZE])
{
	double max = 0;
	for (int i = 0, j = i; i < SIZE; i++)
	{
		if (arr[i][j] > max)
		{
			max = arr[i][j];
		}
	}
	return max;
}
char MaxElemMatrix(char arr[][SIZE])
{
	char max = 'a';
	for (int i = 0, j = i; i < SIZE; i++)
	{
		if (arr[i][j] > max)
		{
			max = arr[i][j];
		}
	}
	return max;
}
int MinElemMatrix(int arr[][SIZE])
{
	int min = arr[0][0];
	for (int i = 0, j = i; i < SIZE; i++)
	{
		if (arr[i][j] < min)
		{
			min = arr[i][j];
		}
	}
	return min;
}
double MinElemMatrix(double arr[][SIZE])
{
	double min = arr[0][0];
	for (int i = 0, j = i; i < SIZE; i++)
	{
		if (arr[i][j] < min)
		{
			min = arr[i][j];
		}
	}
	return min;
}
char MinElemMatrix(char arr[][SIZE])
{
	char min = arr[0][0];
	for (int i = 0, j = i; i < SIZE; i++)
	{
		if (arr[i][j] < min)
		{
			min = arr[i][j];
		}
	}
	return min;
}

void SortMatrix(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE-1; j++)
		{
			for (int k = 0; k < SIZE - 1; k++)
			{
				if (arr[i][k] > arr[i][k + 1])
					std::swap(arr[i][k], arr[i][k + 1]);
			}

		}
	}
	PrintMatrix(arr);
}
void SortMatrix(double arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			for (int k = 0; k < SIZE - 1; k++)
			{
				if (arr[i][k] > arr[i][k + 1])
					std::swap(arr[i][k], arr[i][k + 1]);
			}
		}
	}
	PrintMatrix(arr);
}
void SortMatrix(char arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			for (int k = 0; k < SIZE - 1; k++)
			{
				if (arr[i][k] > arr[i][k + 1])
					std::swap(arr[i][k], arr[i][k + 1]);
			}
		}
	}
	PrintMatrix(arr);
}
