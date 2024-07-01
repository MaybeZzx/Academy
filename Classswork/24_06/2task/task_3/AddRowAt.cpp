#include <vector>
#include <string>

void AddRowAt(std::vector<std::vector<std::string>>& matrix, std::vector<std::string> newString, int pos)
{
	matrix.insert(matrix.begin() + pos, newString);
}