#include <iostream>



double max(int* a, int* b, int const& size)
{
	double result = a[0];
	for (int i = 0; i < size; i++)
	{
		if (result < a[i])
		{
			result = a[i];
		}
		if (result < b[i])
		{
			result = b[i];
		}
	}
	return result;
}

double min(int* a, int* b, int const& size)
{
	double result = a[0];
	for (int i = 0; i < size; i++)
	{
		if (result > a[i])
		{
			result = a[i];
		}
		if (result > a[i])
		{
			result = b[i];
		}
	}
	return result;

}
double avg(int* a, int* b, int const& size)
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		result += a[i] + b[i];
	}
	result /= (size * 2);
	return result;

}
double Action(int* a, int* b, int const& size_A, int const& size_B, double(*function(int*a, int* b, int const& size)))
{
	int choice;
	std::cout << "Μενώ:\n1. max\n2. min\n3. avg\n: ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		function = max;
		break;
	case 2:
		break;
	case 3:
		return avg(a, b, size);
		break;
	default:
		break;
	}
	return 0;

}