#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> LoadFromFile(std::string fileName);
void CompareFiles(std::string first, std::string second);
void Display(std::string fileName);