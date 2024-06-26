#include <string>
#include <sstream>
#include <iostream>

int FindWord(std::string text, std::string wordToFind)
{
	
	int i = 0;
	while (text[i])
	{
		text[i] = tolower(text[i]);
		if (ispunct(text[i]))
		{
			text[i] = ' ';
		}
		i++;
	}
	std::stringstream words(text);
	int count = 0;
	std::string word;
	while (words >> word)
	{
		if (word == wordToFind)
		{
			count++;
		}
	}
	return count;
}

int CountPoint(const std::string& text)
{
	int count = 0;
	for (size_t i = 0; i < text.length(); ++i)
	{
		if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			if (text[i + 1] == '.' && text[i + 2] == '.' && i+2 < text.length())
			{
				count++;
				i += 2;
			}
			else
			{
				count++;
			}
		}
	}
	return count;
}

int* CountPunct(std::string& const text)
{
	int* count = new int[2]{0, 0};
	for (size_t i = 0; i < text.length(); ++i)
	{
		if (text[i] == '.')
		{
			count[0]++;
		}
		else if (text[i] == ',')
		{
			count[1]++;
		}
	}
	return count;
}
void SwapText(std::string& text)
{
	for (size_t i = 0; i < text.length() / 2; ++i)
	{
		std::swap(text[i], text[text.length() - i - 1]);
	}
}
void SwapBySentence(std::string& text, size_t start, size_t end)
{
	for (size_t i = start, k = 0; k <= (end-start)/2; ++i, ++k)
	{
		std::swap(text[i], text[end - k - 1]);
	}
}
void SwapSentences(std::string& text)
{
	size_t j = 0, i = 0;
	while (j < text.length())
	{
		if (text[j] == '.' || text[j] == '!' || text[j] == '?' )
		{
			if (text[j + 1] == '.' && text[j + 2] == '.' && j + 2 <= text.length())
			{
				SwapBySentence(text, i, j);
				j += 3;
				i = j+1;
				continue;
			}
			else
			{
				SwapBySentence(text, i, j);
				std::cout << i << " " << j << std::endl;
			}
		}
		j++;
	}
}