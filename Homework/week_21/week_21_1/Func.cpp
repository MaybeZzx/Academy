#include "Func.h"

std::vector<std::string> LoadFromFile(std::string fileName)
{
	std::vector<std::string> fromFile;
	std::string tmp;
	std::ifstream file = std::ifstream(fileName);
	if (file.is_open())
	{
		while (file >> tmp)
		{
			fromFile.push_back(tmp);
		}
	}
	return fromFile;
}

void CompareFiles(std::string first,
	std::string second)
{
	std::vector<std::string> firstBuff = LoadFromFile(first);
	std::vector<std::string> secondBuff = LoadFromFile(second);

	int countOfDifference = 0;
	if (firstBuff.size() > secondBuff.size())
	{
		int i = 0;
		for (i; i < secondBuff.size(); ++i)
		{
			if (firstBuff[i] != secondBuff[i])
			{
				std::cout << ++countOfDifference << ". " << firstBuff[i] << " != " << secondBuff[i] << std::endl;
			}
		}
		for (i; i < firstBuff.size(); ++i)
		{
			std::cout << ++countOfDifference << ". " << firstBuff[i] << std::endl;
		}
	}
	else
	{
		int i = 0;
		for (i; i < firstBuff.size(); ++i)
		{
			if (firstBuff[i] != secondBuff[i])
			{
				std::cout << ++countOfDifference << ". " << firstBuff[i] << " != " << secondBuff[i] << std::endl;
			}
		}
		for (i; i < firstBuff.size(); ++i)
		{
			std::cout << ++countOfDifference << ". " << firstBuff[i] << std::endl;
		}
	}
}

void Display(std::string fileName)
{
	std::ifstream file(fileName);
	std::string line;
	if (file.is_open())
	{
		while (file >> line)
		{
			std::cout << line << std::endl;
		}
	}
}