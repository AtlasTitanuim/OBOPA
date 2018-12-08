// OBOPA_HW3_ClassSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

#include "NPC_Creator.h"


int main()
{
	NPC_Creator creator;
	creator.addNPC("Timmy", creator.Orc, true, false, false);
	creator.addNPC("Bobby", creator.Elve, true, true, false);
	creator.addNPC("Graknok the Destroyer", creator.Orc, false, true, true);

	creator.drawList();
	return 0;
}