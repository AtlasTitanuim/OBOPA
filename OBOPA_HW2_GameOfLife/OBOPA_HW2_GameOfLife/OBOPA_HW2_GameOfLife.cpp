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

	int** point = new int*[25];
	for (int a = 0; a < 25; ++a) {
		point[a] = new int[25]; 
	}

	for (int it = 0; it < 25; it++) {
		for (int ite = 0; ite < 25; ite++) {
			point[ite][it] = 0;
		}
	}

	Block block1(point, 5, 5);

	while (true) {
		system("CLS");
		point = matrix->drawMatrix(rules, point);

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

	//i made a thing... i don't know what's happening now... gotta ask for help
	return 0;
}
