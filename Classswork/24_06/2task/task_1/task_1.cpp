#include <iostream>
#include <vector>
#include <string>
#include "Func.h"

int main()

{
	std::vector<std::vector<std::string>> matrix = { {"hello", "world"}, {"test", "test_"} };
	std::vector<std::string> newString = { "new", "string" };
	AddRow(matrix, newString);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.size(); ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
