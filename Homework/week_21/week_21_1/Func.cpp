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

	for (size_t i = 0; i < firstBuff.size(); ++i)
	{
		if (i > secondBuff.size())
		{
			std::cout << firstBuff[i] << std::endl;
		}
		if (firstBuff[i] != secondBuff[i])
		{
			std::cout << "1. " << firstBuff[i] << std::endl;
			std::cout << "2. " << secondBuff[i] << std::endl;
		}
	}
}

void Display(std::string fileName)
{
	std::ifstream file("text1.txt");
	std::string line;
	if (file.is_open())
	{
		while (file >> line)
		{
			std::cout << line << std::endl;
		}
	}
}