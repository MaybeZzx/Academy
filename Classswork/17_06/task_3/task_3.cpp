#include <iostream>

struct Boiler {
	Boiler(std::string brand, std::string color, int volume, int temperature, int power)
	{
		this->brand = brand;
		this->color = color;
		this->volume = volume;
		this->temperature = temperature;
		this->power = power;
		CheckInfo();
	}
private:
	std::string brand, color;
	int volume, temperature, power;
	bool isSteam;

	void CheckInfo()
	{
		if (volume < 0) volume = 0;
		if (temperature < 0) temperature = 0;
		if (power < 0) power = 0;
	}
public:
	void Show()
	{
		std::cout << "======================================" << std::endl;
		std::cout << "\t�����: " << brand << std::endl;
		std::cout << "\t����: " << color << std::endl;
		std::cout << "\t�����: " << volume << std::endl;
		std::cout << "\t����������� �������: " << temperature << std::endl;
		std::cout << "\t��������: " << power << std::endl;
		std::cout << "======================================" << std::endl;
	}
	void Start()
	{
		std::cout << "������ ����� ������..." << std::endl;
	}
	void Finish()
	{
		std::cout << "������ ��������..." << std::endl;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	Boiler boiler("test", "test", 1,1, 1);
	boiler.Show();
}