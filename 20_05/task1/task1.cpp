#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	setlocale(LC_ALL, "RUS");

	std::string str;
	std::cout << "������� ������: ";
	std::getline(std::cin, str);
	std::replace(str.begin(), str.end(), ' ', '\t');
	std::cout << "��������� ����� ������: " << str << std::endl;
}