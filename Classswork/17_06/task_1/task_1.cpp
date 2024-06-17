#include <iostream>
#include <string>

struct WashingMachine {
	
	
	WashingMachine(std::string brand, std::string color, int width, int length, int height, int power, int spinSpeed, int temperature)
	{
		this->brand = brand;
		this->color = color;
		this->width = width;
		this->length = length;
		this->height = height;
		this->power = power;
		this->spinSpeed = spinSpeed;
		this->temperature = temperature;
		CheckInfo();
	}

private:
	std::string brand, color;
	int width, length, height, power, spinSpeed, temperature;
	void CheckInfo() {
		if (width < 0) width = 0;
		if (length < 0) length = 0;
		if (height < 0) height = 0;
		if (power < 0) power = 0;
		if (spinSpeed < 0) spinSpeed = 0;
		if (temperature < 0) temperature = 0;
	}

public:
	void Show()
	{
		std::cout << "======================================" << std::endl;
		std::cout << "\t�����: " << brand << std::endl;
		std::cout << "\t����: " << color << std::endl;
		std::cout << "\t������: " << width << std::endl;
		std::cout << "\t������: " << height << std::endl;
		std::cout << "\t�����: " << length<< std::endl;
		std::cout << "\t��������: " << power<< std::endl;
		std::cout << "\t�������� ������: " << spinSpeed<< std::endl;
		std::cout << "\t����������� �������: " << temperature<< std::endl;
		std::cout << "======================================" << std::endl;

	}
	void Start()
	{
		std::cout << "���������� ������ ��������..." << std::endl;
	}
	void Finish()
	{
		std::cout << "���������� ������ ��������� ������..." << std::endl;
	}
	void ChangeColor(std::string newColor)
	{
		color = newColor;
		std::cout << "����� ����: " << newColor << std::endl;
	}
};


int main()
{
	setlocale(LC_ALL, "RUS");
	WashingMachine machine("test", "test", 1, 1, 1, 1, 1, 1);
	machine.Show();
	machine.Start();
	machine.Finish();
	machine.ChangeColor("�����");
	machine.Show();

}