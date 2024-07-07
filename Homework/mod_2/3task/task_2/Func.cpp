#include "Func.h"

void PrintMatrix(std::vector<std::vector<int>> const& matrix)
{
    std::cout << std::endl;

    for (auto row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n=========================" << std::endl;
}

void FillMatrix(std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            matrix[i][j] = rand() % 40 - 20;
        }
    }
    PrintMatrix(matrix);
}

std::vector<int> FindCommonValues(std::vector<std::vector<int>> const& A, std::vector<std::vector<int>>  const& B, std::vector<std::vector<int>> const& C)
{
    std::vector<int> commonElements;
    std::set<int> elementB;
    std::set<int> elementC;

    for (const auto& row : B) {
        elementB.insert(row.begin(), row.end());
    }
    for (const auto& row : C) {
        elementC.insert(row.begin(), row.end());
    }

    for (const auto& row : A) {
        for (int val : row) {
            if (elementB.find(val) != elementB.end() && elementC.find(val) != elementC.end()) {
                if (std::find(commonElements.begin(), commonElements.end(), val) == commonElements.end()) {
                    commonElements.push_back(val);
                }
            }
        }
    }
    return commonElements;
}

std::vector<int> FindCommonValues(std::vector<std::vector<int>> const& A, std::vector<std::vector<int>>  const& B)
{
    std::vector<int> commonElements;
    std::set<int> elementB;

    for (const auto& row : B) {
        elementB.insert(row.begin(), row.end());
    }

    for (const auto& row : A) {
        for (int val : row) {
            if (elementB.find(val) != elementB.end()) {
                if (std::find(commonElements.begin(), commonElements.end(), val) == commonElements.end()) {
                    commonElements.push_back(val);
                }
            }
        }
    }
    return commonElements;
}

void InsertUniqueValues(std::vector<std::vector<int>> const& matrix, std::set<int>& uniqueSet)
{
    for (auto row : matrix)
    {
        for (int val : row)
        {
            uniqueSet.insert(val);
        }
    }
}

std::vector<int> FindUniqueValues(std::vector<std::vector<int>> const& A, std::vector<std::vector<int>> const& B, std::vector<std::vector<int>> const& C)
{
    std::set<int> uniqueSet;

    InsertUniqueValues(A, uniqueSet);
    InsertUniqueValues(B, uniqueSet);
    InsertUniqueValues(C, uniqueSet);

    std::vector<int> uniqueElements(uniqueSet.begin(), uniqueSet.end());

    return uniqueElements;
}

void PrintArr(std::vector<int> const& arr)
{
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void AddNegativeValues(std::vector<std::vector<int>> const& matrix, std::set<int>& negativeSet)
{
    for (auto row : matrix) {
        for (int val : row) {
            if (val < 0) {
                negativeSet.insert(val);
            }
        }
    }
}
