#include "func.h"

std::string GetPlates(const Car& car)
{
	return car.plates.plateNum
		? std::to_string(car.plates.plateNum)
		: car.plates.plateWord;
}

void CheckFields(Car& car)
{
	if (car.plates.plateNum != -1)
	{
		while (car.plates.plateNum < 10000 || car.plates.plateNum > 99999)
		{
			std::cout << "Введено неверное значение! (10000 - 99999)" << "\nПопробуйте еще раз" << std::endl;
			std::cout << ": ";
			std::cin >> car.plates.plateNum;
		}
	}
	else
	{
		std::string tmp = car.plates.plateWord;
		while (tmp.size() < 1 || tmp.size() > 8)
		{
			std::cout << "Введено неверное значение! (Длина слова до 8 букв)" << "\nПопробуйте еще раз" << std::endl;
			std::cout << ": ";
			std::cin >> tmp;
		}
		car.plates.plateWord = tmp.c_str();
	}
}

void ClearFields(Car& car)
{
	car.color = "";
	car.model = "";
	car.plates.plateNum = 0;
	car.plates.plateWord = "";
}

void InitCar(Car& car)
{
	SetColor(car);
	SetModel(car);
	SetPlates(car);
}

void SetPlates(Car& car)
{
	std::cout << "Выберите тип номера: " << std::endl;
	std::cout << "1. 5-тизначный" << std::endl;
	std::cout << "2. Слово из 8 букв" << "\n: ";
	int choice;
	std::cin >> choice;

	while (choice < 1 || choice > 2)
	{
		std::cout << "Введено неверное значение! Попробуйте еще раз";
		std::cout << ": ";
		std::cin >> choice;
	}

	if (choice == 1)
	{
		std::cout << "Введите 5-тизначное число: ";
		std::cin >> car.plates.plateNum;
		CheckFields(car);
	}
	else
	{
		std::cout << "Введите слово длиной до 8 букв: ";
		std::string tmp;
		std::cin >> tmp;
		car.plates.plateWord = tmp.c_str();
		CheckFields(car);
	}
}

void SetColor(Car& car)
{
	std::cout << "Введите цвет машины: ";
	std::cin >> car.color;
}

void SetModel(Car& car)
{
	std::cout << "Введите модель машины: ";
	std::cin >> car.model;
}

void Print(const Car& car)
{
	std::cout << "Модель: " << car.model;
	std::cout << "Цвет: " << car.color;
	std::cout << "Номер: " << GetPlates(car) << std::endl;
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
	std::cout << "Выберите поле для редактирования: ";
	std::cout << "1. Цвет" << std::endl;
	std::cout << "2. Модель" << std::endl;
	std::cout << "3. Номер" << std::endl;
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
	std::cout << "Текущий цвет: " << car.color << std::endl;
	std::cout << "Введите новый цвет: ";
	std::cin >> car.color;
	CheckFields(car);
}

void ChangeModel(Car& car)
{
	std::cout << "Текущая модель: " << car.color << std::endl;
	std::cout << "Введите новую модель авто: ";
	std::cin >> car.model;
	CheckFields(car);
}

void ChangePlates(Car& car)
{
	std::cout << "Текущий номер: " << GetPlates(car) << std::endl;
	std::cout << "Введите новый номер: ";
	std::string tmp;
	std::cin >> tmp;
	car.plates.plateWord = tmp.c_str();
	CheckFields(car);
}

int SearchCar(const std::vector<Car>& cars, const std::string plates)
{
	int index = -1;
	for (int i = 0; i < cars.size(); ++i)
	{
		if (std::to_string(cars[i].plates.plateNum) == plates || cars[i].plates.plateWord == plates)
		{
			index = i;
		}
	}
	return index;
}