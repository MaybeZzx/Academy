#include <iostream>
#include <string>
#include "ToDec.h"
int main()
{
	setlocale(LC_ALL, "rus");
	std::string numStr;
	std::cout << "������� ����� � �������� ��: ";
	std::getline(std::cin, numStr);
	int i = 0;

	//	�������� �� ��
	while (i < numStr.size())
	{
		if (numStr[i] != '1' && numStr[i] != '0')
		{
			std::cout << "������� ����� � �������� ��!";
			return 1;
		}
		i++;
	}
	int num = std::stoi(numStr);

	std::cout << "����� " << num << " � ���������� �� = " << ToDec(num) << std::endl;
}