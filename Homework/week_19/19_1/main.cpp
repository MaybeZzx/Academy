#include "func.h"

int main()
{
	setlocale(LC_ALL, "rus");

	std::vector<Car> cars;
	const int size = 2;
	for (int idx = 0; idx < size; ++idx)
	{
		Car tmpCar;
		std::cout << "\t������ #" << idx+1 << std::endl;
		InitCar(tmpCar);
		cars.push_back(tmpCar);
		std::cout << std::endl;
		ClearFields(tmpCar);
	}
	PrintCars(cars);
	EditCar(cars[5]);
	PrintCars(cars);
	std::cout << "������� ����� ��� ������ ����: ";
	std::string plate;
	std::cin >> plate;
	int idx = SearchCar(cars, plate);
	std::cout << "������ ��������� ������: " << idx << std::endl;
	Print(cars[idx]);

	for (int i = 0; i < cars.size(); ++i)
	{
		delete[] cars[i].plates.plateWord;
	}

}