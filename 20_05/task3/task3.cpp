#include <iostream>
#include <string>
#include <vector>

int main()
{
	setlocale(LC_ALL, "RUS");
	std::vector <std::string> vec;
	std::string str;
	std::getline(std::cin, str);
	int count = 0;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == ' ' || str[i + 1] == '\0')
		{
			count++;
		}
	}
	std::cout << "Кол-во слов в строке: " << count << std::endl;
}