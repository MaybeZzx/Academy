#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Automobile
{
	std::string color, transmission;
	int length = 0;
	int roadClearance = 0;
	double engineVolume = 0.0;
	int wheelDiameter = 0;
	int horsePower = 0;
};

void SetValues(Automobile& automobile, int length, int roadClearance, double engineVolume, int wheelDiameter, int horsePower, std::string color, std::string transmission);
void SetColor(Automobile& automobile, std::string color);
void SetTransmission(Automobile& automobile, std::string transmission);
void SetLength(Automobile& automobile, int length);
void SetRoadClearance(Automobile& automobile, int roadClearance);
void SetEngineVolume(Automobile& automobile, double engineVolume);
void SetWheelDiameter(Automobile& automobile, int wheelDiameter);
void ShowInfo(Automobile const& automobile);

template <typename T>
Automobile* SearchBy(std::vector<Automobile>& automobileList, T valueToSearch, T Automobile::* value)
{
	for (auto& car : automobileList)
	{
		if (car.*value == valueToSearch)
		{
			return &car;
		}
	}
	return nullptr;
}
