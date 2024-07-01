#include <iostream>
#include <vector>
#include <string>
#include "AddRowToBegin.h"

int main()

{
	std::vector<std::vector<std::string>> matrix = { {"hello", "world"}, {"test", "test_"} };
	std::vector<std::string> newString = { "new", "string" };
	AddRowToBegin(matrix, newString);
	for (const auto& subArr : matrix) {
		for (const auto& str : subArr) {
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
}