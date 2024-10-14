#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int CharCount(std::string fileName);
int RowsCount(std::string fileName);
int VowelsCount(std::string fileName);
int ConsonantsCount(std::string fileName);
int DigitsCount(std::string fileName);
void LoadFromTo(std::string first, std::string second);
void PrintStatisticFrom(std::string fileName);
std::vector<int> GetStatistic(std::string fileName);
