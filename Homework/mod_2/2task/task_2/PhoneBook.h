#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

void AddContact(std::vector<std::vector<std::string>>& phoneBook, const std::string& name, const int& phone);
void SearchByName(std::vector<std::vector<std::string>>& phoneBook, const std::string& name);
void SearchByPhone(std::vector<std::vector<std::string>>& phoneBook, const std::string& phone);
void EditContact(std::vector<std::vector<std::string>>& phoneBook);
void Menu();