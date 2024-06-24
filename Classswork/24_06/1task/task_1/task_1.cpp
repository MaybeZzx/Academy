#include <iostream>
#include <string>
#include <sstream> 
#include "Func.h"
int main()
{
	setlocale(LC_ALL, "rus");
	int res;
	int* resArr;
	std::string wordToFind;
	std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit... Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	
	std::cout << "�����: " << std::endl;
	std::cout << text << std::endl;
	std::cout << "\n1. ����� ��������� �����" << std::endl;
	std::cout << "2. ������� ���-�� �����������" << std::endl;
	std::cout << "3. ������� ���-�� ����� � �������" << std::endl;
	std::cout << "4. ��������� ������ �������" << std::endl;
	std::cout << "5. ��������� ������� ����������� �� �����������" << std::endl;
	std::cout << ": ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "\n������� ����� ��� ������: ";
		std::cin >> wordToFind;
		res = FindWord(text, wordToFind);
		std::cout << "����� \'" << wordToFind << "\' ����������� � ������ " << res << " ���" << std::endl;
		break;
	case 2:
		res = CountPoint(text);
		std::cout << "�����������: " << res << std::endl;
		break;
	case 3:
		resArr = CountPunct(text);
		std::cout << "���-�� �����: " << resArr[0] << std::endl;
		std::cout << "���-�� �������: " << resArr[1] << std::endl;
		delete[] resArr;
		break;
	case 4:
		SwapText(text);
		std::cout << text << std::endl;
		break;
	case 5:
		SwapSentences(text);
		std::cout << text << std::endl;
		break;
	default:
		break;
	}
	

	

}