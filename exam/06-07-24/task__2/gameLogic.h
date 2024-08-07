#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
#include <iomanip>

struct GameField {
	const int smallSize = 3;
	const int largeSize = 4;

	unsigned short size;
	unsigned short X = 0, Y = 0;
	std::vector <std::vector<std::string>> Map;
	std::vector <std::vector<std::string>> rightMap;
};

enum Keys {
	KEY_DOWN = 80,
	KEY_UP = 72,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	ENTER = 13
};

void StartGame(unsigned short& choiceSize, unsigned short& choiceFill);
void Menu();
void InitField(unsigned short const& user_choice, GameField& gameField);
void PrintMap(GameField const& gameField);
void FillMapAuto(GameField& gameField);
void FillMapManual(GameField& gameField);
void SetNumber();
void DoMove(GameField& gameField, Keys key);
