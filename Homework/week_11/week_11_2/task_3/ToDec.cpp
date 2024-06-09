#include <math.h>
#include <iostream>
int ToDec(int num)
{
	int res = 0;
	int index = 0;
	while (num != 0)
	{
		
		res += (num % 10) * pow(2, index++);
		num /= 10;
	}
	return res;
}