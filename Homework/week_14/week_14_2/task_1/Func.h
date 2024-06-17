#pragma once
int* AllocateMemory(int size);
void InitArray(int* arr, int size);
void PrintArray(int* arr, int size);
void DeleteArray(int* arr);
void AddElement(int*& arr, int& size, int element);
void InsertElement(int*& arr, int& size, int element, int index);
void DeleteElement(int*& arr, int& size, int index);
