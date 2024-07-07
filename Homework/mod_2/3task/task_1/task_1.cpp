#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>

int main()
{
	setlocale(LC_ALL, "rus");
	std::vector<std::string> students(5);
	std::string lastName;
	std::cout << "Введите 5 фамилий студентов: " << std::endl;
	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << i+1 <<". ";
		std::getline(std::cin, lastName);
		students.push_back(lastName);
	}

	std::sort(students.begin(), students.end());

	std::cout << "Отсортированные фамилии студентов:" << std::endl;
	for (size_t i = 0; i < students.size(); ++i) {
		std::cout << students[i] << std::endl;
	}
}