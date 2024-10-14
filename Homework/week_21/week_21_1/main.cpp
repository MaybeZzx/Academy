#include "Func.h"

int main()
{
	setlocale(LC_ALL, "rus");

	std::string first = "text1.txt";
	std::string second = "text2.txt";

	std::cout << "First: " << std::endl;
	Display(first);
	std::cout << "\nSecond: " << std::endl;
	Display(second);
	std::cout << "==== Difference ======" << std::endl;
	CompareFiles(first, second);
}