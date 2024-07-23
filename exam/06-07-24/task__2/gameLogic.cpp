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

void InitField(unsigned short const& user_choice, GameField& gameField)
{
	if (user_choice == 1)
	{
		gameField.size = 3;
	}
	else
	{
		gameField.size = 4;
	}
	gameField.Map = std::vector<std::vector<std::string>>(gameField.size);
	for (auto& row : gameField.Map)
	{
		row = std::vector<std::string>(gameField.size, "--");
	}
}
bool SearchVal(std::vector<std::vector<std::string>>& map, int const& x_, int const& y_)
{
	for (int x = 0; x < map.size(); ++x)
	{
		for (int y = 0; y < map[0].size(); ++y)
		{
			if (map[x][y] == map[x_][y_])
			{
				if (x == x_ && y == y_)
				{
					continue;
				}
				return true;
			}
		}
	}
	return false;
}
void PrintMap(GameField const& gameField)
{
	std::cout << "\n\n\t\t============" << std::endl;
	for (int i = 0; i < gameField.size; ++i)
	{
		std::cout << "\t\t| ";
		for (int j = 0; j < gameField.size; ++j)
		{

			std::cout << gameField.Map[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "\t\t============" << std::endl;
}
void FillMapAuto(GameField& gameField)
{
	int xZero = 0, yZero = 0;

	for (int x = 0; x < gameField.Map.size(); ++x)
	{
		for (int y = 0; y < gameField.Map[0].size(); ++y)
		{
			gameField.Map[x][y] = std::to_string(rand() % (gameField.Map.size() * gameField.Map.size()));
			if (gameField.Map[x][y].length() < 2)
			{
				gameField.Map[x][y] = "0" + gameField.Map[x][y];
			}
			if (SearchVal(gameField.Map, x, y))
			{
				y--;
				continue;
			}
			if (gameField.Map[x][y] == "00")
			{
				xZero = x;
				yZero = y;
			}
		}
	}
	gameField.Map[xZero][yZero] = "**";
	gameField.X = xZero;
	gameField.Y = yZero;

}
void FillMapManual(GameField& gameField)
{
	int inputKey;
	int rightValue = 1;
	std::string rightValue_string;
	std::string previous_rightValue;

	for (int x = 0; x < gameField.Map.size(); ++x)
	{
		for (int y = 0; y < gameField.Map.size(); ++y)
		{
			PrintMap(gameField);
			inputKey = _getch();
			do
			{
				inputKey = _getch();
				if (gameField.Map[gameField.X][gameField.Y] == "--")
				{
					if (rightValue < 10)
					{
						rightValue_string = "0" + std::to_string(rightValue);
						gameField.Map[gameField.X][gameField.Y] = rightValue_string;
					}
					else
					{
						rightValue_string = std::to_string(rightValue);
						gameField.Map[gameField.X][gameField.Y] = rightValue_string;
					}
				}
				else
				{
					for (int x_ = 0; x_ < gameField.size; ++x_)
					{
						for (int y_ = 0; y_ < gameField.size; ++y_)
						{
							if (gameField.Map[x_][y_] != previous_rightValue)
							{
								gameField.X = x_;
								gameField.Y = y_;
								x_ = 2;
							}
						}
					}
				}
				Move(gameField, inputKey);
				gameField.Map[gameField.X][gameField.Y] = "--";
				std::cout << "\n\t\t Enter - поставить число" << std::endl;
			} while (inputKey != 13);
			gameField.Map[gameField.X][gameField.Y] = rightValue_string;
			previous_rightValue = rightValue_string;
			rightValue++;
			std::cout << gameField.Map[gameField.X][gameField.Y] << std::endl;
		}
	}
}

void Move(GameField& gameField, int const& inputKey)
{
	switch (inputKey)
	{
	case 72:
		if (gameField.X - 1 >= 0)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X--][gameField.Y]);
		}
		break;
	case 80:
		if (gameField.X + 1 < gameField.size)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X++][gameField.Y]);
		}
		break;
	case 75:
		if (gameField.Y - 1 >= 0)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X][gameField.Y--]);
		}
		break;
	case 77:
		if (gameField.Y + 1 < gameField.size)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X][gameField.Y++]);
		}
		break;
	default:
		break;
	}
	system("cls");
	PrintMap(gameField);
	std::cout << "\n\n" << gameField.Map[gameField.X][gameField.Y] << " " << gameField.X << " " << gameField.Y << std::endl;
}
