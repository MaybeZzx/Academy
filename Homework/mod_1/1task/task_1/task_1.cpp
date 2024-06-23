#include <iostream>
#include <string>

void RemoveSymbolByIndex(std::string& str)
{
    int index;
    std::cout << "Введите индекс: ";
    std::cin >> index;
    str.erase(str.begin() + index);
    std::cout << "\n" << str << std::endl;

}
void RemoveChar(std::string& str)
{
    char symb;
    std::cout << "Введите символ: ";
    std::cin >> symb;
    std::cout << str << std::endl;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == symb)
        {
            str.erase(i, 1);
            if (str.find(symb))
                i -= 1;
        }
        
    }
    std::cout << "\n" << str << std::endl;

}
void InsertSymb(std::string& str)
{
    char symb;
    std::cout << "Введите символ: ";
    std::cin >> symb;
    int index;
    std::cout << "Введите индекс: ";
    std::cin >> index;
    str.insert(index, 1, symb);
    std::cout << "\n" << str << std::endl;

}
void ReplacePoint(std::string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '.')
        {
            str[i] = '!';
        }
    }
    std::cout << "\n" << str << std::endl;
}
int CountSymb(std::string& str)
{
    char symb;
    std::cout << "Введите символ: ";
    std::cin >> symb;
    int count = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == symb)
        {
            count++;
        }
    }
    return count;
}
void NumCharacters(std::string& str)
{
    int countNum = 0, temp, countLetter = 0, countSymbol = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        temp = (char)(str[i]);
        if (temp >= 48 && temp < 58)
            countNum++;
        if (temp >= 65 && temp < 91)
            countLetter++;
        if (temp >= 97 && temp < 123)
            countLetter++;
        if (temp >= 32 && temp < 48)
            countSymbol++;
        if (temp >= 58 && temp < 65)
            countSymbol++;
        if (temp >= 91 && temp < 97)
            countSymbol++;
        if (temp >= 123 && temp <= 126)
            countSymbol++;
    }
    std::cout << "Количество цифр в строке: " << countNum << std::endl;
    std::cout << "Количество букв в строке: " << countLetter << std::endl;
    std::cout << "Количество символов в строке: " << countSymbol << std::endl;
}
int main()
{
    setlocale(LC_ALL, "rus");
    std::string str;

    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    std::cout << "Выберите действие: " << std::endl;
    std::cout << "1. Удаление символа по индексу" << std::endl;
    std::cout << "2. Удаление символа в строке" << std::endl;
    std::cout << "3. Вставка символа по индексу" << std::endl;
    std::cout << "4. Замена \".\" на  \"!\"" << std::endl;
    std::cout << "5. Подсчет вхождений символа" << std::endl;
    std::cout << "6. Подсчет символов в строке" << "\n: ";
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        RemoveSymbolByIndex(str);
        break;
    case 2:
        RemoveChar(str);
        break;
    case 3:
        InsertSymb(str);
        break;
    case 4:
        ReplacePoint(str);
        break;
    case 5:
        std::cout << CountSymb(str);
        break;
    case 6:
        NumCharacters(str);
        break;
    default:
        break;
    }
    
}