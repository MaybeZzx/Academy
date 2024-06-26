#include <iostream>
#include <string>
#include <sstream> 
#include "Func.h"
int main()
{
	setlocale(LC_ALL, "rus");
	int res;
	int* resArr;
	std::string wordToFind;
	std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit... Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	
	std::cout << "Текст: " << std::endl;
	std::cout << text << std::endl;
	std::cout << "\n1. Поиск вхождений слова" << std::endl;
	std::cout << "2. Подсчет кол-ва предложений" << std::endl;
	std::cout << "3. Подсчет кол-ва точек и запятых" << std::endl;
	std::cout << "4. Переворот текста целиком" << std::endl;
	std::cout << "5. Переворот каждого предложения по отдельности" << std::endl;
	std::cout << ": ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "\nВведите слово для поиска: ";
		std::cin >> wordToFind;
		res = FindWord(text, wordToFind);
		std::cout << "Слово \'" << wordToFind << "\' встречается в тексте " << res << " раз" << std::endl;
		break;
	case 2:
		res = CountPoint(text);
		std::cout << "Предложений: " << res << std::endl;
		break;
	case 3:
		resArr = CountPunct(text);
		std::cout << "Кол-во точек: " << resArr[0] << std::endl;
		std::cout << "Кол-во запятых: " << resArr[1] << std::endl;
		delete[] resArr;
		break;
	case 4:
		SwapText(text);
		std::cout << text << std::endl;
		break;
	case 5:
		SwapSentences(text);
		std::cout << text << std::endl;
		break;
	default:
		break;
	}
	

	

}