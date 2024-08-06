#pragma once
#include <iostream>
#include <vector>

void InitMatrix(std::vector<std::vector<int>>& arr, const int& rows, const int& columns);
void FillMatrix(std::vector<std::vector<int>>& arr);
void PrintMatrix(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> MultMatrices(const std::vector<std::vector<int>>& firstMatrix, const std::vector<std::vector<int>>& secondMatrix);