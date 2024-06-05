#include <iostream>
#include <iomanip>
#include <cmath>

int mystrcmp(const char* str1, const char* str2)
{
	if (*str1 == *str2)
	{
		return 0;

	}
	else if (strlen(str1) > strlen(str2))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int StringToNumber(const char* str) {
	int res = 0, znak = 1;
	char symb;
	while (symb = *str++)
	{
		if (symb == '-')
		{
			znak = -1;
			continue;
		}
		if (symb >= '0' || symb <= '9')
		{
			res *= 10;
			res += symb - '0';
		}
	}
	return znak * res;
}

char* NumberToString(int number)
{
	char* pstr = nullptr;
	if (!number)
	{
		pstr = new char[2];
		pstr[0] = '0';
		pstr[1] = '\0';
		return pstr;
	}
	int size = 1;
	int temp = number;

	while (temp /= 10)
	{
		++size;
	}

	bool negative = number < 0;
	if (negative)
	{
		++size;
	}

	pstr = new char[size + 1];
	pstr[size] = '\0';
	if (negative) pstr[0] = '-';

	while (number)
	{
		pstr[--size] = abs(number % 10) + '0';
		number /= 10;
	}
	return pstr;

}
char* Uppercase(const char* str1)
{
	int size = strlen(str1);
	char* res = new char[size + 1];
	char symb;
	int i = 0;
	while (symb = *str1++)
	{
		if (isalpha(symb))
		{
			res[i++] = symb - 32;
		}
		else if (isspace(symb))
		{
			res[i++] = ' ';
		}
	}
	res[size] = '\0';
	return res;
}
char* Lowercase(const char* str1)
{
	int size = strlen(str1);
	char* res = new char[size + 1];
	char symb;
	int i = 0;
	while (symb = *str1++)
	{
		if (symb >= 'A' && symb <= 'Z')
		{
			res[i++] = symb + 32;
		}
		else if (symb >= 'a' && symb <= 'z')
		{
			res[i++] = symb;
		}
		else
		{
			if (isspace(symb))
				res[i++] = ' ';
			else
				res[i++] = symb;
		}
	}
	res[size] = '\0';
	return res;
}
char* mystrrev(const char* str) {
	int size = strlen(str);
	char* str1 = new char[size + 1];
	int k = 0, i = size - 1;
	while (i >= 0 && k <= size)
	{
		str1[k++] = str[i--];
	}
	str1[size] = '\0';
	char* pstr = str1;
	return pstr;
}

int main()
{
	const char str[] = { "Hello World" };
	const char strToNum[] = { "-12" };
	const char strToUppercase[] = { "hello world" };
	const char strToLowercase[] = { "HELLO WORLD" };
	int numToString = -550;
	std::cout << mystrrev(str);

}