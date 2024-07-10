#include "gameLogic.h"
int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	GameField game;
	InitField(1, game);
	FillMapManual(game);
	/*PrintMap(game);
	int moving;
	while (true)
	{
		moving = _getch();
		Move(game, moving);
	}*/
}