#include <vector>

void RemoveNull (std::vector<std::vector<int>>& matrix, int& row, const int& col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix.erase(matrix.begin() + i);
				row--;
				break;
			}
		}
	}
}
