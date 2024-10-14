#include "func.h"

int CharCount(std::string fileName)
{
	std::ifstream file{ fileName };
	int countOfChar = 0;
	std::string line;
	if (file.is_open())
	{
		while (file >> line)
		{
			std::cout << line << std::endl;
			countOfChar += line.size();
		}
	}
	return countOfChar;
}

int RowsCount(std::string fileName)
{
	std::ifstream file{ fileName };
	int countOfRows = 0;
	std::string line;
	if (file.is_open())
	{
		while (file >> line)
		{
			std::cout << "rows " << line << std::endl;
			countOfRows ++;
		}
	}
	file.close();
	return countOfRows;
}

int VowelsCount(std::string fileName)
{
	std::ifstream file{ fileName };
	int countOfVowels = 0;
	std::string line;
	const std::string vowels = "àÀåÅóÓèÈþÞÿßýÝûÛîÎ_AaEeYyUuIiOo";
	if (file.is_open())
	{
		while (file >> line)
		{
			for (int i = 0; i < line.size(); ++i)
			{
				if (std::find(vowels.begin(), vowels.end(), line[i]) != vowels.end())
				{
					std::cout << "vowel " << line[i] << std::endl;
					countOfVowels++;
				}
			}
		}
	}
	file.close();
	return countOfVowels;
}

int ConsonantsCount(std::string fileName)
{
	std::ifstream file{ fileName };
	int countOfConsonants = 0;
	std::string line;
	const std::string consonants = "ÁáÂâÃãÄäÆæÇçÉéÊêËëÌìÍíÏïÐðÑñÒòÔôÕõÖö×÷ØøÙù_QqWwRrTtPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
	if (file.is_open())
	{
		while (file >> line)
		{
			for (int i = 0; i < line.size(); ++i)
			{
				if (std::find(consonants.begin(), consonants.end(), line[i]) != consonants.end())
				{
					std::cout << "consonants " << line[i] << std::endl;

					countOfConsonants++;
				}
			}
		}
	}
	file.close();
	return countOfConsonants;
}

int DigitsCount(std::string fileName)
{
	std::ifstream file{ fileName };
	int countOfDigits = 0;
	std::string line;
	const std::string consonants = "ÁáÂâÃãÄäÆæÇçÉéÊêËëÌìÍíÏïÐðÑñÒòÔôÕõÖö×÷ØøÙù";
	if (file.is_open())
	{
		while (file >> line)
		{
			for (int i = 0; i < line.size(); ++i)
			{
				if (isdigit(line[i]))
				{
					std::cout << "digit " << line[i] << std::endl;
					countOfDigits++;
				}
			}
		}
	}
	file.close();
	return countOfDigits;
}

void LoadFromTo(std::string first, std::string second)
{
	std::ofstream file{ second };
	std::vector<int> statistic = GetStatistic(first);
	for (int i = 0; i < statistic.size(); ++i)
	{
		file << statistic[i] << std::endl;
		std::cout << statistic[i] << std::endl;
	}
}

std::vector<int> GetStatistic(std::string fileName)
{
	std::vector<int> tmp;
	tmp.push_back(CharCount(fileName));
	tmp.push_back(RowsCount(fileName));
	tmp.push_back(VowelsCount(fileName));
	tmp.push_back(ConsonantsCount(fileName));
	tmp.push_back(DigitsCount(fileName));
	return tmp;
}

void PrintStatisticFrom(std::string fileName)
{
	LoadFromTo(fileName, "statistic_" + fileName);
}
