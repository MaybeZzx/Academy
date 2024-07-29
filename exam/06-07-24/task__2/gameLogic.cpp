#include "gameLogic.h"

GameField gameField;

short const doubleDigit = 10;
short const numberStrLen = 2;


enum FillMap {
	FILL_MANUAL = 1,
	FILL_AUTO = 2
} fillSelect;

bool isRightMap(GameField& gameField)
{
	return (gameField.Map == gameField.rightMap);
}

bool isSet (GameField const& gameField, int const& x_, int const& y_)
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

int StartTimer()
{
	return clock();
}

int EndTimer(int const& timer)
{
	return (clock() - timer) / CLOCKS_PER_SEC;
}

void StartGame(unsigned short& choiceSize, unsigned short& choiceFill)
{
	InitField(choiceSize, gameField);
	fillSelect = static_cast<FillMap>(choiceFill);
	switch (fillSelect)
	{
	case FILL_MANUAL:
		FillMapManual(gameField);
		break;
	case FILL_AUTO:
		FillMapAuto(gameField);
		break;
	default:
		FillMapAuto(gameField);
		break;
	}
}

void SelectSize(unsigned short& choiceSize)
{
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
}

void SelectFill(unsigned short& choiceFill)
{
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
}

void ShowResults(int const& timer, int const& countOfMoving)
{
	int hour = timer / 3600;
	int minute = (timer % 3600) / 60;
	int secRemaining = timer % 60;

	std::cout << "Вы победили!" << std::endl;
	std::cout << "Потраченное время: " << hour << ":" << minute << ":" << secRemaining << std::endl;
	std::cout << "Количество перестановок: " << countOfMoving << std::endl;
}

void Menu()
{
	unsigned short choiceSize = 3;
	unsigned short choiceFill = 3;

	SelectSize(choiceSize);

	if (choiceSize == 0)
	{
		std::cout << "Выход" << std::endl;
		return;
	}

	SelectFill(choiceFill);

	if (choiceFill == 0)
	{
		std::cout << "Выход" << std::endl;
		return;
	}

	StartGame(choiceSize, choiceFill);

	int timer = StartTimer();
	int keyInput;
	int countOfMoving = 0;

	while (!isRightMap(gameField))
	{
		keyInput = _getch();
		DoMove(gameField, static_cast<Keys>(keyInput));
		if (keyInput == KEY_UP || keyInput == KEY_LEFT || keyInput == KEY_RIGHT || keyInput == KEY_DOWN)
		{
			countOfMoving++;
		}
	}

	timer = EndTimer(timer);
	ShowResults(timer, countOfMoving);
}

void CreateRightMap(GameField& const gameField)
{
	int rightValue = 1;
	std::string rightValue_string;
	for (int x = 0; x < gameField.size; ++x)
	{
		for (int y = 0; y < gameField.size; ++y)
		{
			if (rightValue < doubleDigit)
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
		gameField.size = gameField.smallSize;
	}
	else 
	{
		gameField.size = gameField.largeSize;
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

void PrintLine(unsigned short const& size)
{
	if (size == gameField.smallSize)
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

void SetCursor(GameField& gameField)
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

void SetNumber()
{
	int inputKey = 0;
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
				if (rightValue < doubleDigit)
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
				SetCursor(gameField);
			}
		}
		DoMove(gameField, static_cast<Keys>(inputKey));
		gameField.Map[gameField.X][gameField.Y] = "--";
		if (rightValue == gameField.size * gameField.size)
		{
			break;
		}
		std::cout << "\n\t\t Enter - поставить число" << std::endl;
		std::cout << inputKey << std::endl;

	} while (inputKey != ENTER);
	rightValue++;
	gameField.Map[gameField.X][gameField.Y] = rightValue_string;
}

void FillMapAuto(GameField& gameField)
{
	int xZero = 0, yZero = 0;
	int rightValue = 1;
	std::string rightValue_string;
	for (int x = 0; x < gameField.Map.size(); ++x)
	{
		for (int y = 0; y < gameField.Map[0].size(); ++y)
		{
			rightValue = rand() % (gameField.size * gameField.size);
			rightValue_string = std::to_string(rightValue);

			if (rightValue < doubleDigit)
			{
				rightValue_string = "0" + rightValue_string;
			}
			gameField.Map[x][y] = rightValue_string;

			if (isSet(gameField, x, y))
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

void FillMapManual(GameField& gameField)
{
	
	PrintMap(gameField);
	for (int x = 0; x < gameField.Map.size(); ++x)
	{
		for (int y = 0; y < gameField.Map.size(); ++y)
		{
			SetNumber();
		}
	}
	SetCursor(gameField);
}

void DoMove(GameField& gameField, Keys key)
{
	switch (key)
	{
	case KEY_UP:
		if (gameField.X - 1 >= 0)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X--][gameField.Y]);
		}
		break;
	case KEY_DOWN:
		if (gameField.X + 1 < gameField.size)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X++][gameField.Y]);
		}
		break;
	case KEY_LEFT:
		if (gameField.Y - 1 >= 0)
		{
			std::swap(gameField.Map[gameField.X][gameField.Y], gameField.Map[gameField.X][gameField.Y--]);
		}
		break;
	case KEY_RIGHT:
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

