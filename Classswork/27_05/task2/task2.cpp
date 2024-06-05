#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	setlocale(LC_ALL, "rus");
	std::string text = "Lorem ipsum dolor sit amet. consectetur adipiscing elit. sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	std::cout << "Word to find: ";
	std::string strToFind;
	std::getline(std::cin, strToFind);
	std::cout << "Word " << strToFind << " found in text " << text.find(strToFind);
}