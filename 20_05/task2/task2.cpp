#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "RUS");
	std::string str;
	std::cout << "Введите строку: ";
	std::getline(std::cin, str);
	int countDigit = 0, countAlpha = 0, countSymb = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			countDigit++;
		}
		else
		{
			if (isalpha(str[i]))
			{
				countAlpha++;
			}
			else
			{
				countSymb++;
			}
		}
	}
	std::cout << "Кол-во цифр: " << countDigit << std::endl;
	std::cout << "Кол-во букв: " << countAlpha << std::endl;
	std::cout << "Кол-во символов: " << countSymb << std::endl;

}
