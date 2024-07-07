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
			std::cout << "Имя: " << name << std::endl;
			std::cout << "Телефон: " << phoneBook[1][j] << std::endl;
			std::cout << "======================" << std::endl;
			check = true;
		}
	}
	if (!check)
	{
		std::cout << "Ничего не найдено" << std::endl;
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
			std::cout << "Имя: " << phoneBook[0][j]<< std::endl;
			std::cout << "Телефон: " << phone << std::endl;
			std::cout << "======================" << std::endl;
			check = true;
		}
	}
	if (!check)
	{
		std::cout << "Ничего не найдено" << std::endl;
		std::cout << "======================" << std::endl;
	}
}
void EditContact(std::vector<std::vector<std::string>>& phoneBook)
{
	std::cout << "Введите имя/номер контакта: ";
	std::string contact;
	std::cin >> contact;
	int count = 0;
	int index = -1;
	for (int i = 0; i < phoneBook[0].size(); ++i)
	{
		if (phoneBook[0][i] == contact)
		{
			std::cout << "Имя: " << contact << std::endl;
			std::cout << "Номер: " << phoneBook[1][i] << std::endl;
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
				std::cout << "Имя: " << phoneBook[0][i] << std::endl;
				std::cout << "Номер: " << contact << std::endl;
				index = i;
				count++;
			}
		}
	}
	if (index == -1 && count == 0)
	{
		std::cout << "Такая запись не найдена!\n" << std::endl;
		return;
	}
	else
	{
		std::cout << "\n1. Изменить имя" << std::endl;
		std::cout << "2. Изменить номер телефона" << std::endl;
		std::cout << ": ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Введите новое имя: ";
			std::cin >> contact;
			std::cout << "Старое имя: " << phoneBook[0][index] << std::endl;
			phoneBook[0][index] = contact;
			std::cout << "Новое имя: " << phoneBook[0][index] << std::endl;
			break;
		case 2:
			std::cout << "Введите новый номер телефона: ";
			std::cin >> contact;
			std::cout << "Старый номер телефона: " << phoneBook[1][index] << std::endl;
			phoneBook[1][index] = contact;
			std::cout << "Новый номер телефона: " << phoneBook[1][index] << std::endl;
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
			std::cout << "Имя: " << phoneBook[0][i] << "\tНомер: " << phoneBook[1][i] << "\n" << std::endl;
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
		std::cout << " 1. Добавить контакт" << std::endl;
		std::cout << " 2. Изменить контакт" << std::endl;
		std::cout << " 3. Поиск по имени" << std::endl;
		std::cout << " 4. Поиск по номеру телефона" << std::endl;
		std::cout << " 5. Просмотр списка контактов" << std::endl;
		std::cout << " 6. Выход" << std::endl;
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
			std::cout << "Введите имя: ";
			std::cin >> name;
			std::cout << "Введите номер телефона: ";
			std::cin >> phone;
			AddContact(phoneBook, name, phone);
			std::cout << "Контакт успешно добавлен!" << std::endl;
			ClearConsole();
			break;
		case 2:
			EditContact(phoneBook);
			ClearConsole();
			break;
		case 3:
			std::cout << "Введите имя: ";
			std::cin >> name;
			SearchByName(phoneBook, name);
			ClearConsole();
			break;
		case 4:
			std::cout << "Введите номер телефона: ";
			std::cin >> phone;
			SearchByPhone(phoneBook, std::to_string(phone));
			ClearConsole();
			break;
		case 5:
			PrintBook(phoneBook);
			std::cout << "\n y - Вернуться в меню" << std::endl;
			std::cout << " n - Выход" << std::endl;
			char symb_choice;
			std::cin >> symb_choice;
			switch (symb_choice)
			{
			case 'y':
				system("cls");
				break;
			case 'n':
				system("cls");
				std::cout << "Выход" << std::endl;
				system("pause");
				return;
			default:
				system("cls");
				break;
			}
		case 6:
			system("cls");
			std::cout << "Выход" << std::endl;
			system("pause");
			return;
		default:
			break;
		}
	} while (choice != 6);
}