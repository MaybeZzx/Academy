#include <iostream>

void FindPerfectNum(int num)
{
	int res = 0;
	for (int i = 0; i < num; i++)
	{
		if (num % i == 0)
		{
			res += num;
		}
	}
}