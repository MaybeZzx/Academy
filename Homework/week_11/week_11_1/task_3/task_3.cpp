#include <iostream>
#include "FindPerfectNum.h"
int main()
{
	/*
		����� ���������� �����������, ���� �����
		���� ��� ��������� ����� ��� ������.�������� �������
		������ ����� ����� �� ��������� ���������.
	*/
	setlocale(LC_ALL, "rus");
	std::cout << "������� ������ ���������: ";
	int start;
	std::cin >> start;
	std::cout << "������� ����� ���������: ";
	int end;
	std::cin >> end;
	std::cout << "���������: ";
	FindPerfectNum(start, end);
	
}