#include "PhoneBook.h"

void AddContact(std::vector<std::vector<std::string>>& phoneBook, const std::string& name, const int& phone)
{
	phoneBook[0].push_back(name);
	phoneBook[1].push_back(std::to_string(phone));
}
void SearchByName(std::vector<std::vector<std::string>>& phoneBook, const std::string& name)
{
	bool check = false;
	for (int j = 0; j < phoneBook[0].size(); ++j)
	{
		if (phoneBook[0][j] == name)
		{
			std::cout << "���: " << name << std::endl;
			std::cout << "�������: " << phoneBook[1][j] << std::endl;
			std::cout << "======================" << std::endl;
			check = true;
		}
	}
	if (!check)
	{
		std::cout << "������ �� �������" << std::endl;
		std::cout << "======================" << std::endl;
	}
}
void SearchByPhone(std::vector<std::vector<std::string>>& phoneBook, const std::string& phone)
{
	bool check = false;
	for (int j = 0; j < phoneBook[1].size(); ++j)
	{
		if (phoneBook[1][j] == phone)
		{
			std::cout << "���: " << phoneBook[0][j]<< std::endl;
			std::cout << "�������: " << phone << std::endl;
			std::cout << "======================" << std::endl;
			check = true;
		}
	}
	if (!check)
	{
		std::cout << "������ �� �������" << std::endl;
		std::cout << "======================" << std::endl;
	}
}
void EditContact(std::vector<std::vector<std::string>>& phoneBook)
{
	std::cout << "������� ���/����� ��������: ";
	std::string contact;
	std::cin >> contact;
	int count = 0;
	int index = -1;
	for (int i = 0; i < phoneBook[0].size(); ++i)
	{
		if (phoneBook[0][i] == contact)
		{
			std::cout << "���: " << contact << std::endl;
			std::cout << "�����: " << phoneBook[1][i] << std::endl;
			count++;
			index = i;
		}
	}
	if (count == 0)
	{
		for (int i = 0; i < phoneBook[1].size(); ++i)
		{
			if (phoneBook[1][i] == contact)
			{
				std::cout << "���: " << phoneBook[0][i] << std::endl;
				std::cout << "�����: " << contact << std::endl;
				index = i;
				count++;
			}
		}
	}
	if (index == -1 && count == 0)
	{
		std::cout << "����� ������ �� �������!\n" << std::endl;
		return;
	}
	else
	{
		std::cout << "\n1. �������� ���" << std::endl;
		std::cout << "2. �������� ����� ��������" << std::endl;
		std::cout << ": ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "������� ����� ���: ";
			std::cin >> contact;
			std::cout << "������ ���: " << phoneBook[0][index] << std::endl;
			phoneBook[0][index] = contact;
			std::cout << "����� ���: " << phoneBook[0][index] << std::endl;
			break;
		case 2:
			std::cout << "������� ����� ����� ��������: ";
			std::cin >> contact;
			std::cout << "������ ����� ��������: " << phoneBook[1][index] << std::endl;
			phoneBook[1][index] = contact;
			std::cout << "����� ����� ��������: " << phoneBook[1][index] << std::endl;
			break;
		default:
			break;
		}
	}

}
void ClearConsole()
{
	Sleep(1500);
	system("cls");
}
void PrintBook(const std::vector<std::vector<std::string>>& phoneBook)
{
	if (phoneBook[0].size() != 0 && phoneBook[1].size() != 0)
	{
		for (int i = 0; i < phoneBook[0].size(); ++i)
		{
			std::cout << "���: " << phoneBook[0][i] << "\t�����: " << phoneBook[1][i] << "\n" << std::endl;
		}
	}
}
void Menu()
{
	std::vector<std::vector<std::string>> phoneBook(2);
	int choice = 0;
	do
	{
		std::cout << "\tMenu:" << std::endl;
		std::cout << " 1. �������� �������" << std::endl;
		std::cout << " 2. �������� �������" << std::endl;
		std::cout << " 3. ����� �� �����" << std::endl;
		std::cout << " 4. ����� �� ������ ��������" << std::endl;
		std::cout << " 5. �������� ������ ���������" << std::endl;
		std::cout << " 6. �����" << std::endl;
		std::cout << " : ";
		std::cin >> choice;
		while (choice < 1 || choice > 6)
		{
			std::cin >> choice;
		}
		system("cls");
		std::string name;
		int phone;
		switch (choice)
		{
		case 1:
			std::cout << "������� ���: ";
			std::cin >> name;
			std::cout << "������� ����� ��������: ";
			std::cin >> phone;
			AddContact(phoneBook, name, phone);
			std::cout << "������� ������� ��������!" << std::endl;
			ClearConsole();
			break;
		case 2:
			EditContact(phoneBook);
			ClearConsole();
			break;
		case 3:
			std::cout << "������� ���: ";
			std::cin >> name;
			SearchByName(phoneBook, name);
			ClearConsole();
			break;
		case 4:
			std::cout << "������� ����� ��������: ";
			std::cin >> phone;
			SearchByPhone(phoneBook, std::to_string(phone));
			ClearConsole();
			break;
		case 5:
			PrintBook(phoneBook);
			std::cout << "\n y - ��������� � ����" << std::endl;
			std::cout << " n - �����" << std::endl;
			char symb_choice;
			std::cin >> symb_choice;
			switch (symb_choice)
			{
			case 'y':
				system("cls");
				break;
			case 'n':
				system("cls");
				std::cout << "�����" << std::endl;
				system("pause");
				return;
			default:
				system("cls");
				break;
			}
		case 6:
			system("cls");
			std::cout << "�����" << std::endl;
			system("pause");
			return;
		default:
			break;
		}
	} while (choice != 6);
}