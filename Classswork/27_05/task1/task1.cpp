#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <map>


void ReplaceWord(std::string &str, std::string lastWord, std::string newWord)
{
    while (str.find(lastWord) != -1)
    {
        str.insert(str.find(lastWord), newWord); // Вставляем новое слово перед старым
        str.erase(str.find(lastWord), lastWord.length()); // Находим и удаляем старое слово
    }
}
void TextToUpper(std::string &str)
{
    bool mark = false;
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
void CountLetters(std::string& str)
{
    std::map<char, int> letters;
    transform(str.begin(), str.end(), str.begin(), tolower);
    std::cout << str << std::endl;
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
            continue;

    }
    for (auto [letter, num] : letters)
    {
        std::cout << letter << ": " << num << std::endl;
    }
}
void CountDigits(std::string& str)
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
    if (digits.empty())
    {
        std::cout << "В строке нет цифр" << std::endl;
        return;
    }
    for (auto [digit, num] : digits)
    {
        std::cout << digit << ": " << num << std::endl;
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    std::string str1 = "Hello hello. world.";
    ReplaceWord(str1, "hello", "world");
    TextToUpper(str1);
    std::cout << str1 << std::endl;
    CountDigits(str1);
}