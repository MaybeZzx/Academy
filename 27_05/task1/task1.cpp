#include "../../lib.h"
#include <ctype.h>

using namespace std;

void ReplaceWord(string &str, string lastWord, string newWord)
{
    while (str.find(lastWord) != -1)
    {
        str.insert(str.find(lastWord), newWord); // Вставляем новое слово перед старым
        str.erase(str.find(lastWord), lastWord.length()); // Находим и удаляем старое слово
    }
}
void TextToUpper(string &str)
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
void CountLetters(string& str)
{
    map<char, int> letters;
    transform(str.begin(), str.end(), str.begin(), tolower);
    cout << str << endl;
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
        cout << letter << ": " << num << endl;
    }
}
void CountDigits(string& str)
{
    map<char, int> digits;
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
        cout << "В строке нет цифр" << endl;
        return;
    }
    for (auto [digit, num] : digits)
    {
        cout << digit << ": " << num << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    string str1 = "Hello hello. world.";
    /*ReplaceWord(str1, "hello", "world");
    cout << str1 << endl;
    TextToUpper(str1);*/
    CountDigits(str1);
}