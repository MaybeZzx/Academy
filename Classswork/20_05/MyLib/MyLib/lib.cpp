#include <iostream>

int mystrlen(const char* str)
{
	int length = 0;
	while (*str++ != '\0')
	{
		length++;
	}
	return length;
}
char* mystrcpy(char* str1,const char* str2)
{
	char* ptr1 = str1;

	do
	{
		*str1++ = *str2;
	} while (str2++ && *str2 != '\0');
	*str1 = '\0';
	return ptr1;
}

char* mystrcat(char* str1, const char* str2)
{
	char* ptr = str1;
	do {
		str1++;
	} while (*str1 != '\0');
	mystrcpy(str1, str2);
	return ptr;
}
char* mystrchr(char* str, char s)
{
	do {
		if (*str == s)
		{
			return str;
		}
		str++;
	} while (*str != '\0' );
	return nullptr;
}
char* mystrstr(char* str1, char* str2)
{
	char* ptr = str1;
	while (*ptr != '\0')
	{
		char* ptr2 = str2;
		char* ptr_start = ptr;
		while (*ptr == *ptr2 && *ptr && *ptr2)
		{
			ptr++;
			ptr2++;
		}
		if (*ptr2 == '\0')
			return ptr_start;
		ptr = ++ptr_start;
	}
	return nullptr;
}