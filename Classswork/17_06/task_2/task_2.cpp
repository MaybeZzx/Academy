#include <iostream>

struct Iron {
	Iron(std::string brand, std::string model, int minTemp, int maxTemp, bool isSteam, int power)
	{
		this->brand = brand;
		this->model = model;
		this->minTemp = minTemp;
		this->maxTemp = maxTemp;
		this->isSteam = isSteam;
		this->power = power;
		CheckInfo();
	}
private:
	std::string brand, model;
	int minTemp, maxTemp, power;
	bool isSteam;
	
	void CheckInfo()
	{
		if (minTemp < 0) minTemp = 0;
		if (maxTemp < 0) maxTemp = 0;
		if (power < 0) power = 0;
	}
public:
	void Show()
	{
		std::cout << "======================================" << std::endl;
		std::cout << "\tФирма: " << brand << std::endl;
		std::cout << "\tМодель: " << model<< std::endl;
		std::cout << "\tМин. температура: " << minTemp<< std::endl;
		std::cout << "\tМакс. температура: " << maxTemp<< std::endl;
		if (isSteam)
			std::cout << "\tПодача пара: Да" << std::endl;
		else
			std::cout << "\tПодача пара: Нет" << std::endl;
		std::cout << "\tМощность: " << power << std::endl;
		std::cout << "======================================" << std::endl;
	}
	void Start()
	{
		std::cout << "Утюг начал нагрев..." << std::endl;
	}
	void Finish()
	{
		std::cout << "Утюг выключен..." << std::endl;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	Iron iron("test", "test", 1, 1, true, 1);
	iron.Show();
}