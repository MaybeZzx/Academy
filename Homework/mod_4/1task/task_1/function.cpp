#include "function.h"

void FillArrayInt(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i] = rand() % 20;
	}
}

void PrintArrayInt(const std::vector<int> const& arr)
{
	for (auto const& el : arr)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int FindMinInt(const std::vector<int> const& arr)
{
	return *std::min_element(arr.begin(), arr.end());
}

int FindMaxInt(const std::vector<int> const& arr)
{
	return *std::max_element(arr.begin(), arr.end());
}

void SortArrayInt(std::vector<int>& arr)
{
	std::sort(arr.begin(), arr.end());
}

void EditArrayInt(std::vector<int>& arr, int index, int const newValue)
{
	arr[index] = newValue;
}


void FillArrayChar(std::vector<char>& arr)
{
	std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (size_t i = 0; i < arr.size(); ++i)
	{
		arr[i] = charset[rand() % (charset.length() - 1)];
	}
}

void PrintArrayChar(const std::vector<char> const& arr)
{
	for (auto const& el : arr)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

char FindMinChar(const std::vector<char> const& arr)
{
	return *std::min_element(arr.begin(), arr.end());
}

char FindMaxChar(const std::vector<char> const& arr)
{
	return *std::max_element(arr.begin(), arr.end());
}

void SortArrayChar(std::vector<char>& arr)
{
	std::sort(arr.begin(), arr.end());
}

void EditArrayChar(std::vector<char>& arr, int index, char const newValue)
{
	arr[index] = newValue;
}


void FillArrayDouble(std::vector<double>& arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		arr[i] = rand() % 20 + (double)rand()/RAND_MAX;
	}
}

void PrintArrayDouble(const std::vector<double> const& arr)
{
	for (auto const& el : arr)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

double FindMinDouble(const std::vector<double> const& arr)
{
	return *std::min_element(arr.begin(), arr.end());
}

double FindMaxDouble(const std::vector<double> const& arr)
{
	return *std::max_element(arr.begin(), arr.end());
}

void SortArrayDouble(std::vector<double>& arr)
{
	std::sort(arr.begin(), arr.end());
}

void EditArrayDouble(std::vector<double>& arr, int index, double const newValue)
{
	arr[index] = newValue;
}
