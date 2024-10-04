#pragma once
#include <string>
#include <iostream>
#include <vector>


union CarPlate
{
	const char* plateWord;
	int plateNum = -1;
};
struct Car
{
	std::string color;
	std::string model;
	CarPlate plates;
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
