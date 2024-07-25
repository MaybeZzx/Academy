#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
#include <iomanip>

struct GameField {
	unsigned short size;
	unsigned short X = 0, Y = 0;
	std::vector <std::vector<std::string>> Map;
	std::vector <std::vector<std::string>> rightMap;

};
void Game();
void InitField(unsigned short const& user_choice, GameField& gameField);
void PrintMap(GameField const& gameField);
void FillMapAuto(GameField& gameField);
void FillMapManual(GameField& gameField);
void Move(GameField& gameField, int const& inputKey);
