#include <iostream>
#include <vector>
#include <string>
#include "AddRow.h"

int main()

{
	std::vector<std::vector<std::string>> matrix = { {"hello", "world"}, {"test", "test_"} };
	std::vector<std::string> newString = { "new", "string" };
	AddRow(matrix, newString);

	for (const auto& subArr : matrix) {
		for (const auto& str : subArr) {
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
}
