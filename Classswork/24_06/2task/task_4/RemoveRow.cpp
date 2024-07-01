#include <vector>
#include <string>

int RemoveRow(std::vector<std::vector<std::string>>& matrix, int pos)
{
	if (pos > 0 && pos < matrix.size())
	{
		matrix.erase(matrix.begin() + pos);
	}
	else
	{
		return -1;
	}
	return 0;

}