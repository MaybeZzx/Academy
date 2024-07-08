#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

struct GameField {
	unsigned short size;
	std::vector <std::vector<std::string>> Map;
};
