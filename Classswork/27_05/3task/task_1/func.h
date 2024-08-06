#pragma once
#include <iostream>
#include <vector>

void InitMatrix(std::vector<std::vector<int>>& arr, const int& rows, const int& columns);
void FillMatrix(std::vector<std::vector<int>>& arr, const int& range);
void PrintMatrix(const std::vector<std::vector<int>>& matrix);
void RemoveNullRows(std::vector<std::vector<int>>& matrix);