#include <iostream>
#include "../MyLib/MyLib/lib.h"
int main()
{
	setlocale(LC_ALL, "rus");

	const char* str = "Hello World"; 
	const char* strToCopy = "12345";
	const char* strToConcat = "world";
	const char symbToFind = 'h';
	
	std::cout << mystrlen(str) << std::endl;

	char copy[50];
	std::cout << mystrcpy(copy, strToCopy) << std::endl;
	
	char strConcat[100] = "hello ";
	std::cout << mystrcat(strConcat, strToConcat) << std::endl;

	char* symbFind = mystrchr(const_cast<char*>(str), symbToFind);
	if (symbFind)
	{
		std::cout << "������ <" << symbToFind << "> ��������� � ������: " << symbFind << std::endl;
	}
	else
	{
		std::cout << "������ <" << symbToFind << "> �� ������ � �������� ������ "<< std::endl;
		std::cout << "������: " << str << std::endl;
	}

	const char strToFind[] = "orld";
	char* strFind = mystrstr(const_cast<char*>(str), const_cast<char*>(strToFind));
	if (strFind)
	{
		std::cout << "������ < " << strToFind << " > ������� � ������: " << str << std::endl;
	}
	else
	{
		std::cout << "������ <" << strToFind << "> �� ������� � �������� ������ " << std::endl;
		std::cout << "������: " << str << std::endl;
	}
}