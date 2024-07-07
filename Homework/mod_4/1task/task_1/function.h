#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <iostream>
#include <algorithm>

#ifdef INTEGER
#define FillArray FillArrayInt
#define PrintArray PrintArrayInt
#define FindMin FindMinInt
#define FindMax FindMaxInt
#define SortArray SortArrayInt
#define EditArray EditArrayInt
#elif defined(CHAR)
#define FillArray FillArrayChar
#define PrintArray PrintArrayChar
#define FindMin FindMinChar
#define FindMax FindMaxChar
#define SortArray SortArrayChar
#define EditArray EditArrayChar
#elif defined(DOUBLE)
#define FillArray FillArrayDouble
#define PrintArray PrintArrayDouble
#define FindMin FindMinDouble
#define FindMax FindMaxDouble
#define SortArray SortArrayDouble
#define EditArray EditArrayDouble
#endif

void FillArrayInt(std::vector<int>& arr);
void PrintArrayInt(const std::vector<int> const& arr);
int FindMinInt(const std::vector<int> const& arr);
int FindMaxInt(const std::vector<int> const& arr);
void SortArrayInt(std::vector<int>& arr);
void EditArrayInt(std::vector<int>& arr, int index, int const newValue);

void FillArrayChar(std::vector<char>& arr);
void PrintArrayChar(const std::vector<char> const& arr);
char FindMinChar(const std::vector<char> const& arr);
char FindMaxChar(const std::vector<char> const& arr);
void SortArrayChar(std::vector<char>& arr);
void EditArrayChar(std::vector<char>& arr, int index, char const newValue);

void FillArrayDouble(std::vector<double>& arr);
void PrintArrayDouble(const std::vector<double> const& arr);
double FindMinDouble(const std::vector<double> const& arr);
double FindMaxDouble(const std::vector<double> const& arr);
void SortArrayDouble(std::vector<double>& arr);
void EditArrayDouble(std::vector<double>& arr, int index, double const newValue);

#endif 