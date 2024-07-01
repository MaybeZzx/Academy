#include <iostream>
#include <string>
#include <vector>
#include "RemoveRow.h"

int main()
{
	std::vector<std::vector<std::string>> matrix = { {"hello", "world"}, {"test", "test_"}, {"new", "string"} };
	RemoveRow(matrix, 2);
	for (const auto& subArr : matrix) {
		for (const auto& str : subArr) {
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
}