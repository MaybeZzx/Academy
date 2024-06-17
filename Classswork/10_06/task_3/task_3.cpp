#include <iostream>

struct Drob {
	int a, b;
	int total = 0;
	Drob(int a, int b) // Конструктор
	{
		this->a = a;
		this->b = b;
	}
	void ConverToNormal()
	{
		while (a >= b)
		{
			a -= b;
			total++;
		}
	}
	void Show()
	{
		if (total && a != 0)
			std::cout << total << " " << a << "/" << b << std::endl;
		else if (total && a == 0)
			std::cout << total << std::endl;
		else 
			std::cout << a << "/" << b << std::endl;
	}
};
Drob operator+(Drob obj1, Drob obj2)
{
	Drob temp(0, 0);
	if (obj1.b != obj2.b)
	{
		temp.b = obj1.b * obj2.b;
		temp.a = obj1.a * obj2.b + obj2.a * obj1.b;
	}
	else
	{
		temp.a = obj1.a + obj2.a;
		temp.b = obj1.b;
	}
	return temp;
}
Drob operator-(Drob obj1, Drob obj2)
{
	Drob temp(0, 0);
	if (obj1.b != obj2.b)
	{
		temp.b = obj1.b * obj2.b;
		temp.a = obj1.a * obj2.b - obj2.a * obj1.b;
	}
	else
	{
		temp.a = obj1.a - obj2.a;
		temp.b = obj1.b;
	}
	return temp;
}
Drob operator*(Drob obj1, Drob obj2)
{
	Drob temp(0, 0);
	temp.a = obj1.a * obj2.a;
	temp.b = obj2.b * obj2.b;
	return temp;
}
Drob operator/(Drob obj1, Drob obj2)
{
	Drob temp(0, 0);
	temp.a = obj1.a * obj2.b;
	temp.b = obj1.b * obj2.a;
	return temp;
}
Drob operator/(Drob obj1, int del)
{
	Drob temp(0, 0);
	temp.a = obj1.a;
	temp.b = obj1.b * del;
	return temp;
}
std::ostream& operator<<(std::ostream& os,Drob obj1)
{
	return os << obj1.a << "/" << obj1.b;
}
int main()
{
	setlocale(LC_ALL, "rus");
	Drob drob1(5, 5);
	Drob drob2(1, 6);
	Drob res(0, 0);
	std::cout << "Дробь 1: ";
	drob1.Show();
	std::cout << "Дробь 2: ";
	drob2.Show();
	res = drob1 + drob2;
	std::cout << "Сложение: " << res << std::endl;
	res = drob1 - drob2;
	std::cout << "Вычитание: " << res << std::endl;

	res.ConverToNormal();
	std::cout << "Перевод в правильную дробь: ";
	res.Show();
	
	/*res = drob1 * drob2;  // Умножение
	res.Show();
	res = drob1 / drob2; // Деление
	res.Show();
	*/
}