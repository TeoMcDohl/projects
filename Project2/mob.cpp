#include "stdafx.h"
#include <string>
#include "monster.h"
using std::string;

mob makeOurMob(int roomID)
{
	srand(time(0));
	int mobChoice = rand() % 100 + 1;
	if (mobChoice > 50 && roomID == 1)
	{
		mob imp = { "Imp", 100, 6, 1,10,1 };
		return imp;
	}
	else if (mobChoice <=50 && roomID == 1)
	{
		mob goblin = { "Goblin", 120, 11, 1,10,2 };
		return goblin;
	}
	else if (roomID == 2)
	{
		mob hobgoblin = { "HobGoblin", 152, 17, 1,12,3 };
		return hobgoblin;
	}
	
	mob imp = { "Imp", 100, 6, 1 };
	return imp;
}
