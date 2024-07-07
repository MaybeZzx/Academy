#pragma once
#include <iostream>
#include <vector>
#include <set>

void FillMatrix(std::vector<std::vector<int>>& matrix);

void PrintMatrix(std::vector<std::vector<int>> const& matrix);
void PrintArr(std::vector<int> const& arr);

std::vector<int> FindCommonElements(std::vector<std::vector<int>> const& A, std::vector<std::vector<int>>  const& B, std::vector<std::vector<int>> const& C);
std::vector<int> FindCommonElements(std::vector<std::vector<int>> const& A, std::vector<std::vector<int>>  const& B);

std::vector<int> FindUniqueValues(std::vector<std::vector<int>> const& A, std::vector<std::vector<int>> const& B, std::vector<std::vector<int>> const& C);

void InsertUniqueValues(std::vector<std::vector<int>> const& matrix, std::set<int>& uniqueSet);

void AddNegativeValues(std::vector<std::vector<int>> const& matrix, std::set<int>& negativeSet);