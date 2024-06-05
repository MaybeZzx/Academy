#include <iostream>
int SumFromTo(int start, int end)
{
	return start + (start < end ? SumFromTo(start + 1, end) : 0);
}