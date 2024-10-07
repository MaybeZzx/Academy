#pragma once
#include <string>
#include <iostream>
#include <vector>



struct Car
{
	std::string color;
	std::string model;

	union CarPlate
	{
		char* plateWord = new char[9];
		int plateNum;
	} plates;
};

void ClearFields(Car& car);
void InitCar(Car& car);
void SetPlates(Car& car);
void SetColor(Car& car);
void SetModel(Car& car);
void Print(const Car& car);
void PrintCars(const std::vector<Car>& cars);
void EditCar(Car& car);
void ChangeColor(Car& car);
void ChangeModel(Car& car);
void ChangePlates(Car& car);
int SearchCar(const std::vector<Car>& cars, const std::string plates);
