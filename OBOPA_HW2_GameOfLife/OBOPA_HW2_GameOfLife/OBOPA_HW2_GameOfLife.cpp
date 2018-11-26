// OBOPA_HW2_GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <thread>

#include "MatrixDrawer.h"
#include "Rules.h"
#include "Block.h"

int main()
{
	MatrixDrawer *matrix = new MatrixDrawer();

	GameRules *rules = new Rules();

	//Creating 2D Array
	int** point = new int*[25]; //Make new pointer to pointer
	for (int a = 0; a < 25; ++a) { //Make new pointer for pointer array
		point[a] = new int[25]; //
	}

	//Making sure the 2D array is initialised with only 0's
	for (int it = 0; it < 25; it++) {
		for (int ite = 0; ite < 25; ite++) {
			point[ite][it] = 0;
		}
	}

	//Instantiate some lifeforms
	Block block1(point, 5, 5);

	//Our infinite loop to draw the matrix
	while (true) {
		system("CLS"); //clear console
		point = matrix->drawMatrix(rules, point);

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

	std::cout << "Done" << std::endl;

	return 0;
}
