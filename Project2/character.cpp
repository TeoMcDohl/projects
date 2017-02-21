#include "stdafx.h"
#include <string>
#include "hero.h"
#include <iostream>
#include <sstream>
using std::string;

hero chooseHero()
{
	using namespace std;
	cout << "Choose your class: \n";
	cout << "1: Warrior (more strength, no mana)\n";
	cout << "2: Wizard (more intellect and mana, less strength and health)\n";
	string heroChoice;
	getline(cin, heroChoice);
	int heroChoiceint;
	stringstream myStream(heroChoice);
	if (myStream >> heroChoiceint)
	{
		if (heroChoiceint == 1)
		{
			hero warrior = { "Warrior",150,150,15,1,3,3,1,2,2,30,true,1,1,1 };
			return warrior;
		}

		else if (heroChoiceint == 2)
		{
			hero wizard = { "Wizard",100,100,9,16,25,25,1,3,1,30,true,1,1,2 };
			return wizard;
		}
	}
	
	cout << "**Invalid option**\n\n";
	hero badChoice = { "Bad Choice",0,0,0,0,0,0,0,0,0,0,false,1,0,0 };
	return badChoice;
}

