#include <iostream>
#include <math.h>

struct Field {
	char fieldArr[10][10];

	int x_first, y_first;
	int x_sec, y_sec;
	void Init()
	{

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				fieldArr[i][j] = '*';
			}
		}
		PrintField();
		SetPoints();
	}
	void PrintField()
	{
		std::cout << "    0 1 2 3 4 5 6 7 8 9" << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			std::cout << i << " | ";
			for (int j = 0; j < 10; ++j)
			{
				std::cout << fieldArr[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	void SetPoints()
	{
		std::cout << "Введите координаты первой точки через пробел(X Y): ";
		
		std::cin >> x_first >> y_first;
		CheckCoord(x_first, y_first);
		fieldArr[x_first][y_first] = 'A';
		std::cout << "Введите координаты второй точки через пробел(X Y): ";
		
		std::cin >> x_sec >> y_sec;
		CheckCoord(x_sec, y_sec);
		while (x_first == x_sec && y_first == y_sec)
		{
			std::cout << "У двух разных точек не могут быть!" << std::endl;
			std::cout << "Введите новые координаты для второй точки (X Y): ";
			std::cin >> x_sec >> y_sec;
		}
		fieldArr[x_sec][y_sec] = 'B';

		system("cls");
		std::cout << "Координаты первой точки: " << x_first << " " << y_first << std::endl;
		std::cout << "Координаты второй точки: " << x_sec << " " << y_sec << std::endl;
		std::cout << "==========================" << std::endl;
		PrintField();
	}
	void CheckCoord(int& x, int& y)
	{
		if (x < 0 || x > 10 || y < 0 || y > 10)
		{
			y = 0;
			x = 0;
		}
	}
	double FindDistance()
	{
		double distance;

		//Катеты п/у треугольника
		int a = y_first - y_sec; 
		int b = x_first- x_sec;

		if (y_first == y_sec)
		{
			distance = x_first - x_sec;
			return distance < 0 ? -distance : distance;
		}
		else if (x_first== x_sec)
		{
			distance = y_first- y_sec;
			return distance < 0 ? -distance : distance;
		}

		if (a < 0) a *= -1;
		if (b < 0) b *= -1;
		a++; b++;
		distance = sqrt(pow(a, 2) + pow(b, 2));
		return distance;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Field field;
	field.Init();
	std::cout << "\nРасстояние между двумя точками: " << field.FindDistance() << std::endl;
	
}