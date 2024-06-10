#include <iostream>

struct Rectangle {
private:
	std::string SpaceUp ="", SpaceLeft ="";
public:
	int x, y;
	Rectangle(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void MoveRectangle(int direction)
	{
		switch (direction)
		{
		case 1: // ����
			SpaceUp += "\n";
			PrintRectangle();
			break;
		case 2: // ������
			SpaceLeft += " ";
			PrintRectangle();
			break;
		default:
			break;
		}
	}
	void PrintRectangle()
	{
		system("cls");
		std::cout << SpaceUp;
		std::cout << SpaceLeft;
		for (int i = 0; i <= x; i++)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
		for (int i = 2; i < y; i++)
		{
			std::cout << SpaceLeft;
			std::cout << "|";
			for (int i = 1; i < x; i++)
			{
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
		std::cout << SpaceLeft;
		for (int i = 0; i <= x; i++)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
	}
	void ChangeX(int num)
	{
		x = num;
	}
	void ChangeY(int num)
	{
		y = num;
	}
};

int main()
{
	std::cout << "������� ����� � ������ �������������� ����� ������ (X Y): ";
	int x, y;
	std::cin >> x >> y;
	Rectangle rectangle(x, y);
	bool programmContinue = true;
	while (programmContinue)
	{
		std::cout << "1. �������� ������ �� 1 ������ ������" << std::endl;
		std::cout << "2. �������� ������ �� 1 ������ ����" << std::endl;
		std::cout << "3. �������� ����� ��������������" << std::endl;
		std::cout << "4. �������� ������ ��������������" << std::endl;
		std::cout << "5. �����" << std::endl << ": ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			rectangle.MoveRectangle(2);
			break;
		case 2:
			rectangle.MoveRectangle(1);
			break;
		case 3:
			std::cout << "������� ����� �����: ";
			int newLength;
			std::cin >> newLength;
			rectangle.ChangeX(newLength);
			break;
		case 4:
			std::cout << "������� ����� ������: ";
			int newWidth;
			std::cin >> newWidth;
			rectangle.ChangeX(newWidth);
			break;
		case 5:
			programmContinue = false;
			break;
		default:
			break;
		}
	}
}