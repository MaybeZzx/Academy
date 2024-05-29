#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string ReplaceWord(string str, string lastWord, string newWord)
{
    while (str.find(lastWord) != -1)
    {
        str.insert(str.find(lastWord), newWord); // Вставляем новое слово перед старым
        str.erase(str.find(lastWord), lastWord.length()); // Находим и удаляем старое слово
    }

    return str;
}

int main()
{
    string str1 = "hello world hello hello";
    cout << ReplaceWord(str1, "hello", "world");
}