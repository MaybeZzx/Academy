#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

struct GameField {
	unsigned short size;
	unsigned short X = 0, Y = 0;
	std::vector <std::vector<std::string>> Map;
};
void InitField(unsigned short const& user_choice, GameField& gameField);
bool SearchVal(std::vector<std::vector<std::string>>& map, int const& x_, int const& y_);
void PrintMap(GameField const& gameField);
void FillMapAuto(GameField& gameField);
void FillMapManual(GameField& gameField);
void Move(GameField& gameField, int const& inputKey);
