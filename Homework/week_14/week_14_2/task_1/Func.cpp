#include <iostream>

int* AllocateMemory(int size) {
	int* arr = new int[size];
	return arr;
}

void InitArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}
}

void PrintArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void DeleteArray(int* arr) {
	delete[] arr;
}

void AddElement(int*& arr, int& size, int element) {
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; ++i) {
		newArr[i] = arr[i];
	}
	newArr[size] = element;

	delete[] arr;
	arr = newArr;
	++size;
}

void InsertElement(int*& arr, int& size, int element, int index) {
	int* newArr = new int[size + 1];
	int j = 0;
	for (int i = 0; i < size + 1; ++i) {
		if (i == index) {
			newArr[i] = element;
		}
		else {
			newArr[i] = arr[j];
			++j;
		}
	}

	delete[] arr;
	arr = newArr;
	++size;
}

void DeleteElement(int*& arr, int& size, int index) {
	int* newArr = new int[size - 1];
	int j = 0;
	for (int i = 0; i < size; ++i) {
		if (i != index) {
			newArr[j] = arr[i];
			++j;
		}
	}

	delete[] arr;
	arr = newArr;
	--size;
}