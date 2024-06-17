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
		std::cout << "\t�����: " << brand << std::endl;
		std::cout << "\t������: " << model<< std::endl;
		std::cout << "\t���. �����������: " << minTemp<< std::endl;
		std::cout << "\t����. �����������: " << maxTemp<< std::endl;
		if (isSteam)
			std::cout << "\t������ ����: ��" << std::endl;
		else
			std::cout << "\t������ ����: ���" << std::endl;
		std::cout << "\t��������: " << power << std::endl;
		std::cout << "======================================" << std::endl;
	}
	void Start()
	{
		std::cout << "���� ����� ������..." << std::endl;
	}
	void Finish()
	{
		std::cout << "���� ��������..." << std::endl;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	Iron iron("test", "test", 1, 1, true, 1);
	iron.Show();
}