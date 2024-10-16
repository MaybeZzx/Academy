#pragma once
#include <string>
#include <iostream>
#include <vector>


union MyPlate
{
	const char* platesWord = new char[8];
	int platesNum;
};
struct Car
{
	MyPlate plates;
	std::string color;
	std::string model;
	
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
int SearchCar(const std::vector<Car>& cars, const std::string& plates);
