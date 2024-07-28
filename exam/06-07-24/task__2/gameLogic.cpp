#include "gameLogic.h"

GameField gameField;


bool CheckMap(GameField& gameField)
{
	return (gameField.Map == gameField.rightMap);
}
Keys ConvertToKey(int const& inputKey)
{
	switch (inputKey)
	{
	case 72:
		return keyUp;
	case 80:
		return keyDown;
	case 75:
		return keyLeft;
	case 77:
		return keyRight;
	}
}
void Game()
{
	unsigned short choiceSize = 3;
	unsigned short choiceFill = 3;

	std::cout << "\n\t  Пятнашки" << std::endl;
	std::cout << "\n\tРазмер поля " << std::endl;
	std::cout << "\t1. 3x3" << std::endl;
	std::cout << "\t2. 4x4" << std::endl;
	std::cout << "\n\t0. Выход" << std::endl;

	while (choiceSize != 1 && choiceSize != 2 && choiceSize != 0)
	{
		std::cout << "\t: ";
		std::cin >> choiceSize;
	}
	system("cls");

	if (choiceSize == 0)
	{
		std::cout << "Выход" << std::endl;
		return;
	}

	std::cout << "\n\t  Пятнашки" << std::endl;
	std::cout << "\n\tРасстановка поля" << std::endl;
	std::cout << "\t1. Вручную" << std::endl;
	std::cout << "\t2. Автоматически" << std::endl;
	std::cout << "\n\t0. Выход" << std::endl;

	while (choiceFill != 1 && choiceFill != 2 && choiceFill != 0)
	{
		std::cout << "\t: ";
		std::cin >> choiceFill;
	}
	system("cls");

	if (choiceFill == 0)
	{
		std::cout << "Выход" << std::endl;
		return;
	}
	InitField(choiceSize, gameField);
	switch (choiceFill)
	{
	case 1:
		FillMapManual(gameField);
		break;
	case 2:
		FillMapAuto(gameField);
		break;
	default:
		FillMapAuto(gameField);
		break;
	}
	//PrintMap(gameField);
	int keyInput;
	int start = clock();
	int countOfMoving = 0;
	while (!CheckMap(gameField))
	{
		keyInput = _getch();
		DoMove(gameField, ConvertToKey(keyInput));
		if (keyInput == keyUp || keyInput == keyLeft || keyInput == keyRight || keyInput == keyDown)
		{
			countOfMoving++;
		}
	}
	int end = clock();
	int sec = double(end - start) / CLOCKS_PER_SEC;
	int hour = sec / 3600;
	int minute = (sec % 3600) / 60;
	int secRemaining = sec % 60;

	std::cout << "Вы победили!" << std::endl;
	std::cout << "Потраченное время: " << hour << ":" << minute << ":" << secRemaining << std::endl;
	std::cout << "Количество перестановок: " << countOfMoving << std::endl;
}

void CreateRightMap(GameField& const gameField)
{
	int rightValue = 1;
	std::string rightValue_string;
	for (int x = 0; x < gameField.size; ++x)
	{
		for (int y = 0; y < gameField.size; ++y)
		{
			if (rightValue < 10)
			{
				rightValue_string = "0" + std::to_string(rightValue);
			}
			else
			{
				rightValue_string = std::to_string(rightValue);
			}
			gameField.rightMap[x][y] = rightValue_string;
			rightValue++;
		}
	}
	gameField.rightMap[gameField.size - 1][gameField.size - 1] = "--";
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
	gameField.rightMap = std::vector<std::vector<std::string>>(gameField.size);
	for (auto& row : gameField.Map)
	{
		row = std::vector<std::string>(gameField.size, "--");
	}	
	for (auto& row : gameField.rightMap)
	{
		row = std::vector<std::string>(gameField.size, "--");
	}

	CreateRightMap(gameField);
}

bool SearchVal(GameField const& gameField, int const& x_, int const& y_)
{
	for (int x = 0; x < gameField.size; ++x)
	{
		for (int y = 0; y < gameField.size; ++y)
		{
			if (gameField.Map[x][y] == gameField.Map[x_][y_])
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

void PrintLine(unsigned short const& size)
{
	if (size == 3)
	{
		std::cout << "\t\t============" << std::endl;
	}
	else
	{
		std::cout << "\t\t===============" << std::endl;
	}
}

void PrintMap(GameField const& gameField)
{

	PrintLine(gameField.size);
	for (int i = 0; i < gameField.size; ++i)
	{
		std::cout << "\t\t| ";
		for (int j = 0; j < gameField.size; ++j)
		{

			std::cout << gameField.Map[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
	PrintLine(gameField.size);
}

void FillMapAuto(GameField& gameField)
{
	int xZero = 0, yZero = 0;

	for (int x = 0; x < gameField.Map.size(); ++x)
	{
		for (int y = 0; y < gameField.Map[0].size(); ++y)
		{
			gameField.Map[x][y] = std::to_string(rand() % (gameField.size* gameField.size));
			if (gameField.Map[x][y].length() < 2)
			{
				gameField.Map[x][y] = "0" + gameField.Map[x][y];
			}
			if (SearchVal(gameField, x, y))
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
	gameField.Map[xZero][yZero] = "--";
	gameField.X = xZero;
	gameField.Y = yZero;
}

void Move()
{
	int inputKey;
	int static rightValue = 1;
	int x_right = 0, y_right = 0;
	std::string static rightValue_string;
	do
	{
		if (rightValue < gameField.size * gameField.size)
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
						if (gameField.Map[x_][y_] == "--")
						{
							gameField.X = x_;
							gameField.Y = y_;
							x_ = gameField.size - 1;
							y_ = gameField.size - 1;
						}
					}
				}
			}
		}
		DoMove(gameField, ConvertToKey(inputKey));
		gameField.Map[gameField.X][gameField.Y] = "--";
		if (rightValue == gameField.size * gameField.size)
		{
			break;
		}
		std::cout << "\n\t\t Enter - поставить число" << std::endl;
		std::cout << inputKey << std::endl;

	} while (inputKey != 13);
	rightValue++;
	gameField.Map[gameField.X][gameField.Y] = rightValue_string;
}

void FillMapManual(GameField& gameField)
{
	
	PrintMap(gameField);
	for (int x = 0; x < gameField.Map.size(); ++x)
	{
		for (int y = 0; y < gameField.Map.size(); ++y)
		{
			Move();
		}
	}
	for (int x = 0; x < gameField.size; ++x)
	{
		for (int y = 0; y < gameField.size; ++y)
		{
			if (gameField.Map[x][y] == "--")
			{
				gameField.X = x;
				gameField.Y = y;
				x = gameField.size - 1;
				y = gameField.size - 1;
			}
		}
	}
}

void DoMove(GameField& gameField, Keys key)
{
	switch (key)
	{
	case keyUp:
		if (gameField.X - 1 >= 0)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X--][gameField.Y]);
		}
		break;
	case keyDown:
		if (gameField.X + 1 < gameField.size)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X++][gameField.Y]);
		}
		break;
	case keyLeft:
		if (gameField.Y - 1 >= 0)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X][gameField.Y--]);
		}
		break;
	case keyRight:
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
}

