#include <iostream>
#include <string>

void RemoveSymbolByIndex(std::string& str, int index)
{
    str.erase(str.begin() + index);
}

void RemoveChar(std::string& str, char symb)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == symb)
        {
            str.erase(i, 1);
            if (str.find(symb))
                i -= 1;
        }
    }
}

void InsertSymb(std::string& str, int index, char symb)
{
    str.insert(index, 1, symb);
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
}

int CountSymb(std::string const& str, char symb)
{

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

void NumCharacters(std::string const& str)
{
    int countNum = 0, temp, countLetter = 0, countSymbol = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        temp = (char)(str[i]);
        if (std::isdigit(temp))
            countNum++;
        else if (std::isalpha(temp))
            countLetter++;
        else
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
    char symb;
    int index;

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
        std::cout << "Введите индекс: ";
        std::cin >> index;

        RemoveSymbolByIndex(str, index);
        std::cout << "Результат: " << str << std::endl;
        break;
    case 2:
        std::cout << "Введите символ: ";
        std::cin >> symb;

        RemoveChar(str, symb);
        std::cout << "Результат: " << str << std::endl;
        break;
    case 3:
        std::cout << "Введите символ: ";
        std::cin >> symb;
        std::cout << "Введите индекс: ";
        std::cin >> index;

        InsertSymb(str, index, symb);
        std::cout << "Результат: " << str << std::endl;
        break;
    case 4:
        ReplacePoint(str);
        std::cout << "Результат: " << str << std::endl;
        break;
    case 5:
        std::cout << "Введите символ: ";
        std::cin >> symb;
        std::cout << "Символ <" << symb << "> встречается " << CountSymb(str, symb) << " раз" << std::endl;
        break;
    case 6:
        NumCharacters(str);
        break;
    default:
        break;
    }
    
}