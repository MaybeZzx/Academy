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
    std::cout << "���������� ���� � ������: " << countNum << std::endl;
    std::cout << "���������� ���� � ������: " << countLetter << std::endl;
    std::cout << "���������� �������� � ������: " << countSymbol << std::endl;
}

int main()
{
    
    setlocale(LC_ALL, "rus");
    std::string str;
    char symb;
    int index;

    std::cout << "������� ������: ";
    std::getline(std::cin, str);
    std::cout << "�������� ��������: " << std::endl;
    std::cout << "1. �������� ������� �� �������" << std::endl;
    std::cout << "2. �������� ������� � ������" << std::endl;
    std::cout << "3. ������� ������� �� �������" << std::endl;
    std::cout << "4. ������ \".\" ��  \"!\"" << std::endl;
    std::cout << "5. ������� ��������� �������" << std::endl;
    std::cout << "6. ������� �������� � ������" << "\n: ";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        std::cout << "������� ������: ";
        std::cin >> index;

        RemoveSymbolByIndex(str, index);
        std::cout << "���������: " << str << std::endl;
        break;
    case 2:
        std::cout << "������� ������: ";
        std::cin >> symb;

        RemoveChar(str, symb);
        std::cout << "���������: " << str << std::endl;
        break;
    case 3:
        std::cout << "������� ������: ";
        std::cin >> symb;
        std::cout << "������� ������: ";
        std::cin >> index;

        InsertSymb(str, index, symb);
        std::cout << "���������: " << str << std::endl;
        break;
    case 4:
        ReplacePoint(str);
        std::cout << "���������: " << str << std::endl;
        break;
    case 5:
        std::cout << "������� ������: ";
        std::cin >> symb;
        std::cout << "������ <" << symb << "> ����������� " << CountSymb(str, symb) << " ���" << std::endl;
        break;
    case 6:
        NumCharacters(str);
        break;
    default:
        break;
    }
    
}