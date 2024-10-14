#include "func.h"

void Encrypt(std::string fileName, int key)
{
	std::fstream first{ fileName };
	std::ofstream second{ "encrypt_" + fileName };
	std::string line;
	if (first.is_open())
	{
		while (first >> line)
		{
			for (size_t i = 0; i < line.size(); ++i)
			{
				std::cout << line[i];
				if (isalpha(line[i]))
				{
					second << char(line[i]) - key;
				}
				else
				{
					second << line[i];
				}
			}
		}
	}
}