// OBOPA_HW4_Algorithims.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void print(std::vector<std::string> words);

int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	std::vector<std::string> copy1(colours);
	sort(copy1.begin(), copy1.end());

	std::vector<std::string>::iterator i;
	i = find(copy1.begin(), copy1.end(), "purple");

	std::vector<std::string> beforePurple(colours.size());
	copy(copy1.begin(), i, beforePurple.begin());

	std::vector<std::string> afterPurple(colours.size());
	copy((i + 1), copy1.end(), afterPurple.begin());

	i = find(beforePurple.begin(), beforePurple.end(), "");
	beforePurple.resize(std::distance(beforePurple.begin(), i));

	i = find(afterPurple.begin(), afterPurple.end(), "");
	afterPurple.resize(std::distance(afterPurple.begin(), i));

	print(beforePurple);
	print(afterPurple);

	// 2) alle elementen UPPERCASE te maken.
	std::vector<std::string> copy2(colours);
	for (auto col : copy2) {
		std::transform(col.begin(), col.end(), col.begin(), ::toupper);
	}
	print(copy2);

	// 3) alle dubbele te verwijderen
	std::vector<std::string> copy3(colours);
	std::vector<std::string>::iterator it;
	it = unique_copy(colours.begin(), colours.end(), copy3.begin());

	copy3.resize(distance(copy3.begin(), it));
	sort(copy3.begin(), copy3.end());

	it = unique_copy(copy3.begin(), it, copy3.begin());
	copy3.resize(distance(copy3.begin(), it));

	print(copy3);

	//---------------------------------------------------------------------------------------
	
	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// 1) alle negatieve elementen te verwijderen
	std::vector<double> numbersCopy(numbers);
	std::vector<double>::iterator ite;
	ite = std::remove_if(numbersCopy.begin(), numbersCopy.end(), [](int i) { return i < 0 ? true : false; });
	numbersCopy.resize(std::distance(numbersCopy.begin(), ite));

	for (auto word : numbersCopy) {
		std::cout << word << std::endl;
	}
	std::cout << std::endl;
	
	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	for (auto word : numbers) {
		//[](int word) { return (std::modulus<int>(word, 2) == 0 ? "true" : "false"); }
		if ((int)word % 2 == 0) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
	}
	std::cout << std::endl;

	
	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	double sum = 0;
	for(int a = 0; a < numbers.size(); a++) {
		sum += numbers[a];
	}
	std::cout.precision(10);
	std::cout << "The sum:		" << sum << std::endl;

	double middle = sum / numbers.size();
	std::cout.precision(10);
	std::cout << "The middle:		" << middle << std::endl;

	double product = numbers[0];
	for (int a = 1; a < numbers.size(); a++) {
		product *= numbers[a];
	}
	std::cout.precision(25);
	std::cout << "The product:		" << product << std::endl;

	return 0;
}

void print(std::vector<std::string> words) {
	for (auto word : words) {
		std::cout << word << std::endl;
	}
	std::cout << std::endl;
}