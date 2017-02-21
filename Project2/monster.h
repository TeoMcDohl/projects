#ifndef MONSTER
#define MONSTER
#include "stdafx.h"
#include <string>
#include <time.h>
#include <iostream>
using std::string;

class mob
{
public:
	string mobName;
	int mobHealth;
	int mobMana;
	int mobDamage;
	int strength;
	int mobID;
	void monsterDamage()
	{
		if (mobID == 1) 
		{
			mobDamage = rand() % strength + 1;
		}
		else if (mobID == 2)
		{
			mobDamage = rand() % strength + 4;
		}
		else if (mobID == 3)
		{
			mobDamage = rand() % strength + 6;
		}
	}
	int chanceToHit()
	{
		int calcChance;
		signed srand (time(0));
		calcChance = rand() % 100 + 1;

		if (calcChance > 30)
		{
			return 1;
		}
		else if (calcChance <= 30)
		{
			return 2;
		}
	}
	void displayStats()
	{
		using namespace std;
		cout << mobName << "'s health is " << mobHealth << "\n";
		cout << mobName << "'s mana is " << mobMana << "\n";
	}
};
#endif