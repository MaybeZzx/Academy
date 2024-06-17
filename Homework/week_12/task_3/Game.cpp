#include <iostream>
#include <cstring>

int q[4]; // Цифры загаданного числа
int a[4]; // Цифры введенного числа

void RunGame();
bool Check(int num);

void Init()
{
    //std::cout << "\t\t";
    for (int i = 0; i < 4; ++i)
    {
        q[i] = rand() % 10;
        //std::cout << q[i];
    }
    //std::cout << "\n" << std::endl;
}

void GameProcess(int n)
{
    ++n;
    int num; 
    std::cout << "\nВведите число: ";
    std::cin >> num;


    if (Check(num))
    {
        std::cout << "\n======================\n" << std::endl;
        std::cout << "Число отгадано! Попыток: " << n << std::endl;

        char x;
        do
        {
            std::cout << "\n\nПродолжим? (y / n) ";
            std::cin >> x;
        } while (x != 'y' && x != 'n');

        if (x == 'y') RunGame();


    }
    else {
        GameProcess(n);
    }
}

bool Check(int num)
{

    int temp[4];
    memcpy(temp, q, 4 * sizeof(int)); // Создаем копию загаданного числа

    for (int i = 3; i >= 0; --i)
    {
        a[i] = num % 10;
        num /= 10;
    }

    int bull = 0;
    int cow = 0;
    
    for (int i = 0; i < 4; ++i)
    {
        if (a[i] == temp[i])
        {
            ++bull;
            temp[i] = -1;
            a[i] = -2;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (j != i && a[i] == temp[j])
            {
                ++cow;
                temp[j] = -1;
                break;
            }
        }
    }

    if (bull == 4) return true;

    std::cout << "\n Быки = " << bull << " Коровы = " << cow << std::endl;
    std::cout << "------------------------";

    return false;
}

void RunGame()
{
    Init();
    GameProcess(0);
}

