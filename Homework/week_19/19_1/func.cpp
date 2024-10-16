#include "func.h"

const char* GetPlates(const Car& car)
{
	return (car.plates.platesNum == -1)? car.plates.platesWord : std::to_string(car.plates.platesNum).c_str();
}

void ClearFields(Car& car)
{
	car.color = "";
	car.model = "";
	car.plates.platesNum = -1;
	car.plates.platesWord = "";
}

int StringLength(const char* string)
{
	int k = 0;
	while (string[k])
	{
		k++;
	}
	return k;
}
void InitCar(Car& car)
{
	SetColor(car);
	SetModel(car);
	SetPlates(car);
}

void SetPlates(Car& car)
{
	std::cout << "�������� ��� ������: " << std::endl;
	std::cout << "1. 5-���������" << std::endl;
	std::cout << "2. ����� �� 8 ����" << "\n: ";
	int choice;
	std::cin >> choice;
	
	while (choice < 1 || choice > 2)
	{
		std::cout << "������� �������� ��������! ���������� ��� ���";
		std::cout << ": ";
		std::cin >> choice;
	}

	std::string tmp;
	switch (choice)
	{
	case 1:
		std::cout << "������� 5-�� ������� ����� (10000 - 99999): ";
		std::cin >> car.plates.platesNum;
		while (car.plates.platesNum < 10000 || car.plates.platesNum > 99999)
		{
			std::cout << "������� �������� ��������! ��������� �������" << std::endl;
			std::cout << ": ";
			std::cin >> car.plates.platesNum;
		}
		break;
	case 2:
		std::cout << "������� ����� �� 8 ����: ";
		std::cin >> tmp;
		while (tmp.size() < 1 || tmp.size() > 8)
		{
			std::cout << "������� �������� ��������! ��������� �������" << std::endl;
			std::cout << ": ";
			std::cin >> tmp;
		}
		delete[] car.plates.platesWord;
		car.plates.platesWord = new char[tmp.length()+1];
		tmp += '\0';
		strcpy(const_cast<char*>(car.plates.platesWord), tmp.c_str());
		car.plates.platesNum = -1;
		break;
	default:
		break;
	}
}

void SetColor(Car& car)
{
	std::cout << "������� ���� ������: ";
	std::cin >> car.color;
}

void SetModel(Car& car)
{
	std::cout << "������� ������ ������: ";
	std::cin >> car.model;
}

void Print(const Car& car)
{
	std::cout << "������: " << car.model;
	std::cout << "����: " << car.color;
	std::cout << "�����: " << GetPlates(car) << std::endl;
}

void PrintByIndex(const std::vector<Car>& cars, const int index)
{
	Print(cars[index]);
}

void PrintCars(const std::vector<Car>& cars)
{
	for (int i = 0; i < cars.size(); ++i)
	{
		Print(cars[i]);
	}
}

void EditCar(Car& car)
{
	std::cout << "�������� ���� ��� ��������������: ";
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ������" << std::endl;
	std::cout << "3. �����" << std::endl;
	int choice;
	do
	{
		std::cout << ": ";
		std::cin >> choice;
	} while (choice < 1 && choice > 3);

	switch (choice)
	{
	case 1:
		ChangeColor(car);
		break;
	case 2:
		ChangeModel(car);
		break;
	case 3:
		ChangePlates(car);
		break;
	default:
		break;
	}
}

void ChangeColor(Car& car)
{
	std::cout << "������� ����: " << car.color << std::endl;
	std::cout << "������� ����� ����: ";
	std::cin >> car.color;
}

void ChangeModel(Car& car)
{
	std::cout << "������� ������: " << car.color << std::endl;
	std::cout << "������� ����� ������ ����: ";
	std::cin >> car.model;
}

void ChangePlates(Car& car)
{
	std::cout << "������� �����: " << GetPlates(car) << std::endl;
	std::cout << "������� ����� �����: ";
	std::string tmp;
	std::cin >> tmp;
	delete[] car.plates.platesWord;
	car.plates.platesWord = new char[tmp.length() + 1];
	car.plates.platesWord = tmp.c_str() + '\0';
}

int SearchCar(const std::vector<Car>& cars, const std::string& plates)
{
	int index = -1;
	for (int i = 0; i < cars.size(); ++i)
	{
		if (std::to_string(cars[i].plates.platesNum) == plates || cars[i].plates.platesWord == plates)
		{
			index = i;
		}
	}
	return index;
}