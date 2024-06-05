#include <iostream>
int MyPow(int num, int pow)
{
	if (pow == 0)
		return 1;
	else
	{
		return num * MyPow(num, pow - 1);
	}
}