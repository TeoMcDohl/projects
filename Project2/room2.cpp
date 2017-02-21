#include "stdafx.h"
#include "functionloader.h"
#include "hero.h"
#include <iostream>

void roomTwo(hero& player1, abilities& ability1, mob& currentMob)
{
	using namespace std;
	int roomID = 2;
	string room2String;
	int room2Int;
	cout << endl;
	cout << "[Room 2]" << endl;
	cout << "Would you like to...?" << endl;
	cout << "1. Fight" << endl;
	cout << "2. Return to Lobby" << endl;
	cout << endl;

	getline(cin, room2String);
	stringstream room2Stream(room2String);
	if (room2Stream >> room2Int)
	{
		if (room2Int == 1)
		{
			currentMob = makeOurMob(roomID);
			cout << endl;
			cout << "A " << currentMob.mobName << " appears!" << endl;
			fightengine(player1, ability1, currentMob);
			endCondition(player1, currentMob);
			roomTwo(player1, ability1, currentMob);
		}
		else if (room2Int == 2)
		{

		}
		else
		{
			cout << "*Invalid option*" << endl;
			roomTwo(player1, ability1, currentMob);
		}
	}
	else
	{
		cout << "*Invalid option*" << endl;
		roomTwo(player1, ability1, currentMob);
	}


}