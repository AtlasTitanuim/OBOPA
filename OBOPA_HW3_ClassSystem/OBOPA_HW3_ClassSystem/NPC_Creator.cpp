#include "pch.h"
#include "NPC_Creator.h"

#include "Race.h"
#include "Class.h"
#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"
#include "Elves.h"
#include "Orcs.h"


NPC_Creator::NPC_Creator()
{
}

void NPC_Creator::addNPC(std::string name, std::string race, bool farmer, bool soldier, bool shaman) {
	Race* theNPC;

	if (race == "Orc" || race == "orc" || race == "Orcs" || race == "orcs") {
		theNPC = new Orcs(name);
		if (farmer) {
			theNPC = new Farmer(theNPC);
		}
		if (soldier) {
			theNPC = new Soldier(theNPC);
		}
		if (shaman) {
			theNPC = new Shaman(theNPC);
		}
	}
	else if (race == "Elf" || race == "elf" || race == "Elve" || race == "elve" || race == "Elves" || race == "elves") {
		theNPC = new Elves(name);
		if (farmer) {
			theNPC = new Farmer(theNPC);
		}
		if (soldier) {
			theNPC = new Soldier(theNPC);
		}
		if (shaman) {
			theNPC = new Shaman(theNPC);
		}
	}

	

	npcs.push_back(theNPC);
}
void NPC_Creator::drawList() {
	for (auto& npc : npcs) {
		std::cout << "---" << std::endl;
		npc->render();
	}
	std::cout << "---" << std::endl;
}


NPC_Creator::~NPC_Creator()
{
}