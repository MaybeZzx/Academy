#include "func.h"

 int main()
{
	setlocale(LC_ALL, "rus");
    std::vector<Automobile> automobileList(5);
    SetValues(automobileList[0], 4500, 150, 2.0, 18, 150, "�������", "�������");
    SetValues(automobileList[1], 3700, 130, 1.6, 16, 120, "�����", "��������");
    SetValues(automobileList[2], 5000, 200, 3.0, 20, 200, "�������", "�������");
    SetValues(automobileList[3], 4200, 170, 2.2, 17, 140, "������", "��������");
    SetValues(automobileList[4], 3900, 160, 1.8, 17, 130, "�����", "�������");

    int lengthToFind = 4500;
    Automobile* car = SearchBy(automobileList, lengthToFind, &Automobile::length);
    ShowInfo(*car);
}