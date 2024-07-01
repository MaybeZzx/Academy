#include <vector>

template <typename T>
void AddRow(std::vector<std::vector<T>>& matrix, std::vector<T> newString)
{
	matrix.push_back(newString);
}