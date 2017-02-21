#include "stdafx.h"
#include "functionloader.h"
#include "hero.h"
#include <iostream>

void roomOne(hero& player1, abilities& ability1, mob& currentMob)
{
	using namespace std;
	int roomID = 1;
	string room1String;
	int room1Int;
	cout << endl;
	cout << "[Room 1]" << endl;
	cout << "Would you like to...?" << endl;
	cout << "1. Fight" << endl;
	cout << "2. Return to Lobby" << endl;
	cout << endl;

	getline(cin, room1String);
	stringstream room1Stream(room1String);
	if (room1Stream >> room1Int)
	{
		if (room1Int == 1)
		{
			currentMob = makeOurMob(roomID);
			cout << endl;
			cout << "A " << currentMob.mobName << " appears!" << endl;
			fightengine(player1, ability1, currentMob);
			endCondition(player1, currentMob);
			roomOne(player1, ability1, currentMob);
		}
		else if (room1Int == 2)
		{

		}
		else if (room1Int != 1 && room1Int != 2)
		{
			cout << "*Invalid option*" << endl;
			roomOne(player1, ability1, currentMob);
		}
	}
	else
	{
		cout << "*Invalid option*" << endl;
		roomOne(player1, ability1, currentMob);
	}

	
}