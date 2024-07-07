#include "func.h"


void SetValues(Automobile& automobile, int length, int roadClearance, double engineVolume, int wheelDiameter, int horsePower, std::string color, std::string transmission)
{
	automobile.length = length;
	automobile.roadClearance = roadClearance;
	automobile.engineVolume = engineVolume;
	automobile.wheelDiameter = wheelDiameter;
	automobile.horsePower = horsePower;
	automobile.color = color;
	automobile.transmission = transmission;
}

void SetColor(Automobile& automobile, std::string color)
{
	automobile.color = color;
}

void SetTransmission(Automobile& automobile, std::string transmission)
{
	automobile.transmission = transmission;
}

void SetLength(Automobile& automobile, int length)
{
	automobile.length = length;
}

void SetRoadClearance(Automobile& automobile, int roadClearance)
{
	automobile.roadClearance = roadClearance;
}

void SetEngineVolume(Automobile& automobile, double engineVolume)
{
	automobile.engineVolume = engineVolume;
}

void SetWheelDiameter(Automobile& automobile, int wheelDiameter)
{
	automobile.wheelDiameter = wheelDiameter;
}

void ShowInfo(Automobile const& automobile)
{
	std::cout << "Цвет: " << automobile.color << std::endl;
	std::cout << "Коробка передач: " << automobile.transmission << std::endl;
	std::cout << "Объем двигателя: " << automobile.engineVolume << std::endl;
	std::cout << "Мощность: " << automobile.horsePower << std::endl;
	std::cout << "Длина: " << automobile.length << std::endl;
	std::cout << "Диаметр колес: " << automobile.wheelDiameter << std::endl;
	std::cout << "Клиренс: " << automobile.roadClearance << std::endl;
	std::cout << "==================\n" << std::endl;
}

