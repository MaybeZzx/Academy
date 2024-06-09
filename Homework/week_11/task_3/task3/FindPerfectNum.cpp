#include <iostream>

void FindPerfectNum(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int res = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				res += j;
			}
		}
		if (res == i && res)
		{
			std::cout << res << " ";
		}

	}
}