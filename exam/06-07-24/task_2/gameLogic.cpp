#include "gameLogic.h"

GameField gameField;

void Game()
{
	std::cout << "\n\t\tПятнашки" << std::endl;
	std::cout << "\n\tРазмер поля " << std::endl;
	std::cout << "\t1. 3x3" << std::endl;
	std::cout << "\t2. 4x4" << std::endl;
	std::cout << "\n\t0. Выход" << std::endl;
	unsigned short user_choice = 10;
	while (user_choice != 1 && user_choice != 2 && user_choice != 0)
	{
		std::cout << "\t: ";
		std::cin >> user_choice;
	}
}

std::vector<std::vector<std::string>> InitField(unsigned short const& user_choice)
{
	return user_choice == 1 ? std::vector<std::vector<std::string>>(3) : std::vector<std::vector<std::string>>(4);
}
bool SearchVal(std::vector<std::vector<std::string>>& map, std::string val)
{
	for (int x = 0; x < map.size(); ++x)
	{
		for (int y = 0; y < map[0].size(); ++y)
		{
			if (map[x][y] == val)
			{
				return true;
			}
		}
	}
	return false;
}
void InitMapAuto(std::vector<std::vector<std::string>>& map)
{
	for (auto& row: map)
	{
		row = std::vector<std::string>(map.size());
	}
	for (int x = 0; x < map.size(); ++x)
	{
		for (int y = 0; y < map[0].size(); ++y)
		{
			map[x][y] = std::to_string(rand() % (map.size() * map.size()));

			if (map[x][y].length() < 2)
			{
				map[x][y] = "0" + map[x][y];
			}
			if (SearchVal(map, map[x][y]))
			{
				y--;
			}
		}
	}
}
void InitMapManual(std::vector<std::vector<std::string>>& map) 
{
	for (auto& row : map)
	{
		row = std::vector<std::string>(map.size());
	}
	for (int x = 0; x < map.size(); ++x)
	{
		for (int y = 0; y < map[0].size(); ++y)
		{
			map[x][y] = 

		}
	}
}
