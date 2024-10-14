#include "func.h"

int main()
{
	setlocale(LC_ALL, "rus");
	std::string file = "text1.txt";

	PrintStatisticFrom(file);
}