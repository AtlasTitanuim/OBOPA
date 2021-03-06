// OBOPA_HW4_Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

template<typename U>
void print(U arr, size_t size);

template<typename T>
bool sort(T* ar, size_t size);

//Template Class met Queue-semantiek
template<class T>
class Arras {
private:
	size_t length;
	T* arras;
public:
	Arras() {
		length = 0;
		arras = new T[length];
	}

	bool put(T input) {
		T* newArray = new T[length + 1];
		for (size_t l = 0; l < length; l++) {
			newArray[l] = arras[l];
		}
		newArray[length] = input;
		arras = newArray;
		length++;
		return true;
	}

	T get(size_t index) {
		return T(arras[index]);
	}

	size_t size() {
		return length;
	}
};


int main()
{
	float arrey[3] = { 2.3f, 1.3f, 5.4f };	
	print(arrey, 3);
	sort(arrey, 3);
	print(arrey, 3);

	std::string arroy[3] = { "ooferpoofer", "oof", "ooferthepooferbro" };
	print(arroy, 3);
	sort(arroy, 3);
	print(arroy, 3);

	//get - put - size
	Arras<int> integers;
	integers.put(10);
	integers.put(30);
	integers.put(20);

	for (size_t i = 0; i < integers.size(); i++) {
		std::cout << integers.get(i) << std::endl;
	}
	return 0;
}

template<typename U>
void print(U arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
bool sort(T* ar, size_t size)
{
	for (size_t j = 1; j < size; j++) {
		if (ar[j] < ar[j - 1]) {
			T temp = ar[j - 1];
			ar[j - 1] = ar[j];
			ar[j] = temp;
			if ((j - 1) > 0) {
				j = j - 2;
			}
		}

	}

	return true;
}


