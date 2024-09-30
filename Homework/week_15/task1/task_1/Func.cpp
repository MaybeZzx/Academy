#include <iostream>



double max(int* a, int* b, int const& size_A, int const& size_B)
{
	double result = a[0];
	for (int i = 0; i < size_A; i++)
	{
		if (result < a[i])
		{
			result = a[i];
		}
	}
	for (int i = 0; i < size_B; i++)
	{
		if (result < b[i])
		{
			result = b[i];
		}
	}
	
	return result;
}

double min(int* a, int* b, int const& size_A, int const& size_B)
{
	double result = a[0];
	for (int i = 0; i < size_A; i++)
	{
		if (result > a[i])
		{
			result = a[i];
		}
	}
	for (int i = 0; i < size_B; i++)
	{
		if (result > b[i])
		{
			result = b[i];
		}
	}
	return result;

}
double avg(int* a, int* b, int const& size_A, int const& size_B)
{
	double result = 0;
	for (int i = 0; i < size_A; i++)
	{
		result += a[i];
	}
	for (int i = 0; i < size_B; i++)
	{
		result += b[i];
	}
	result /= ((size_A + size_B) * 2);
	return result;

}
double Action(int* a, int* b, int const& size_A, int const& size_B, double(*func)(int* , int* , int const&, int const&))
{
	return func(a,b,size_A,size_B);

}