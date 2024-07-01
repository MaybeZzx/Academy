#include <iostream>
#include <vector>
#include <string>
#include "AddRowAt.h"

int main()

{
	std::vector<std::vector<std::string>> matrix = { {"hello", "world"}, {"test", "test_"} };
	std::vector<std::string> newString = { "new", "string" };
	AddRowAt(matrix, newString, 1);
	for (const auto& subArr : matrix) {
		for (const auto& str : subArr) {
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
}