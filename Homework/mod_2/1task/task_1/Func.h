#pragma once
#include <iostream>
#include <vector>
enum direction {
	Up,
	Right,
	Down,
	Left
};
void PrintMatrix(std::vector<std::vector<int>>& matrix, const int& row, const int& col);
void FillMatrix(std::vector<std::vector<int>>& matrix, const int& row, const int& col);
void AddColumnAt(std::vector<std::vector<int>>& matrix, int pos, int value = 0);
void RemoveColumn(std::vector<std::vector<int>>& matrix, int pos);
void MoveElement(std::vector<std::vector<int>>& matrix, direction direction, int countShift);