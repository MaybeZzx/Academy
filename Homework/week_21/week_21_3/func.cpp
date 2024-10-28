#include "func.h"

void GetEncryptText(std::string fileName, int key)
{
	
	std::fstream first{ fileName };
	std::fstream second{ "encrypt_" + fileName };
	std::string line;
	if (first.is_open())
	{
		while (first >> line)
		{
			
		}
	}
}

char DoEncrypt(std::string line, const int key)
{
	std::cout << "line: " << line << " . " << std::endl;
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (isalpha(line[i]))
		{
			return MoveLetter(line[i], key);
		}
		else
		{
			return line[i];
		}
	}
}

char MoveLetter(char letter, const int& key)
{
	const std::string alphabet_low = "abcdefghijklmnopqrstyvwxyz";
	const std::string alphabet_high = "ABCDEFGHIJKLMNOPQRSTYVWXYZ";

	

	if (isupper(letter))
	{
		return FindLetter(alphabet_high, letter);
	}
	

}

int FindDelta(const int arrSize, const int& currentPosition, const int key)
{
	return currentPosition + key >= arrSize
		? currentPosition - arrSize + key - 1
		: currentPosition + key - 1;
}

int FindLetter(const std::string& alphabet, char letter)
{
	int letterPos;
	int newLetterPos;

	if (isupper(letter))
	{
		letterPos = std::distance(alphabet.begin(), std::find(alphabet.begin(), alphabet.end(), letter));
		newLetterPos = FindDelta(alphabet.size(), letterPos, key);
		return alphabet[newLetterPos];
	}
	else
	{

	}
}