#include <vector>
#include <string>

void AddRow(std::vector<std::vector<std::string>>& matrix, std::vector<std::string> newString)
{
	matrix.push_back(newString);
}