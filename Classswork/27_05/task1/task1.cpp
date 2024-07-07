#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <map>


void ReplaceWord(std::string &str, std::string const& lastWord, std::string const& newWord)
{
    while (str.find(lastWord) != -1)
    {
        str.insert(str.find(lastWord), newWord); 
        str.erase(str.find(lastWord), lastWord.length()); 
    }
}

void SentenceToUpper(std::string &str)
{
    bool mark = false;
    if (std::isalpha(str[0]))
    {
        str[0] = toupper(str[0]);
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
            continue;

        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
            mark = true;
        else if (mark)
        {
            str[i] = toupper(str[i]);
            mark = false;
        }
    }
}

std::map<char, int> CountLetters(std::string str)
{
    std::map<char, int> letters;
    transform(str.begin(), str.end(), str.begin(), tolower);
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]) && letters.contains(str[i]))
        {
            letters[str[i]]++;
        }
        else if (isalpha(str[i]) && !letters.contains(str[i]))
        {
            letters[str[i]] = 1;
        }
        else
        {
            continue;
        }
    }
    return letters;
}

std::map<char, int> CountDigits(std::string const& str)
{
    std::map<char, int> digits;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) && digits.contains(str[i]))
        {
            digits[str[i]]++;
        }
        else if (isdigit(str[i]) && !digits.contains(str[i]))
        {
            digits[str[i]] = 1;
        }
        else
        {
            continue;
        }
    }
    return digits;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    std::string str1 = "hello hello. world. 123";
    std::cout << "Изначальная строка: " << str1 << std::endl;

    ReplaceWord(str1, "hello", "world");
    std::cout << "Строка после замены слова: " << str1 << std::endl;

    SentenceToUpper(str1);
    std::cout << "Первая буква предложения в верхнем регистре: " << str1 << std::endl;

    std::cout << "\nЦифры в предложении: " << std::endl;
    std::map<char, int> digits = CountDigits(str1);
    if (!digits.empty())
    {
        for (auto [digit, num] : digits)
        {
            std::cout << digit << ": " << num << std::endl;
        }
    }

    std::cout << "\nБуквы в предложении: " << std::endl;
    std::map<char, int> letters = CountLetters(str1);
    if (!letters.empty())
    {
        for (auto [letter, num] : letters)
        {
            std::cout << letter << ": " << num << std::endl;
        }
    }
}