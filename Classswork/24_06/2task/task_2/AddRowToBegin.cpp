#include <vector>
#include <string>

void AddRowToBegin(std::vector<std::vector<std::string>>& matrix, std::vector<std::string> newString)
{
	matrix.insert(matrix.begin() , newString);
}