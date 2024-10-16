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
	std::cout << "Выберите тип номера: " << std::endl;
	std::cout << "1. 5-тизначный" << std::endl;
	std::cout << "2. Слово до 8 букв" << "\n: ";
	int choice;
	std::cin >> choice;
	
	while (choice < 1 || choice > 2)
	{
		std::cout << "Введено неверное значение! Попробуйте еще раз";
		std::cout << ": ";
		std::cin >> choice;
	}

	std::string tmp;
	switch (choice)
	{
	case 1:
		std::cout << "Введите 5-ти значный номер (10000 - 99999): ";
		std::cin >> car.plates.platesNum;
		while (car.plates.platesNum < 10000 || car.plates.platesNum > 99999)
		{
			std::cout << "Введено неверное значение! Повторите попытку" << std::endl;
			std::cout << ": ";
			std::cin >> car.plates.platesNum;
		}
		break;
	case 2:
		std::cout << "Введите слово до 8 букв: ";
		std::cin >> tmp;
		while (tmp.size() < 1 || tmp.size() > 8)
		{
			std::cout << "Введено неверное значение! Повторите попытку" << std::endl;
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
}

void ChangeModel(Car& car)
{
	std::cout << "Текущая модель: " << car.color << std::endl;
	std::cout << "Введите новую модель авто: ";
	std::cin >> car.model;
}

void ChangePlates(Car& car)
{
	std::cout << "Текущий номер: " << GetPlates(car) << std::endl;
	std::cout << "Введите новый номер: ";
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