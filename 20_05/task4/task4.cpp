#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    setlocale(LC_ALL, "RUS");

    std::string st, str;
    std::cout << "¬ведите строку: ";
    std::getline(std::cin, st);
    for (int i = 0; i < st.length() - 1; i++)
    {
        if ((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z'))
        {
            str += st[i];
        }
    }
    bool check = true;
    for (int i = 0, k = str.length() - 1; i < str.length() / 2; i++, k--)
    {
        if (str[i] != str[k])
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        std::cout << "явл€етс€ палиндромом " << std::endl;
    }
    else
    {
        std::cout << "Ќе €вл€етс€ палиндромом " << std::endl;
    }
}