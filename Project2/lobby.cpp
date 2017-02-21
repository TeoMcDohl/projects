#include "stdafx.h"
#include "functionloader.h"
#include "hero.h"
#include <iostream>

void lobby(hero& player1, mob& currentMob)
{
	using namespace std;
	cout << endl;
	cout << "Welcome to the lobby! \n";
	cout << "What would you like to do?\n";
	cout << endl;
	
}

void lobbyMenu(hero& player1, abilities& ability1, mob& currentMob)
{
	using namespace std;
	cout << "1. Check your stats\n";
	cout << "2. Enter Room 1" << endl;
	cout << "3. Enter Room 2" << endl;
	cout << "4. Choose a new weapon" << endl;
	cout << "5. Save" << endl;
	cout << "6. Quit to Main Menu" << endl;
	cout << endl;

	string lobbyChoice;
	int lobbyChoiceInt;
	getline(cin, lobbyChoice);
	stringstream lobbyStream(lobbyChoice);
	if (lobbyStream >> lobbyChoiceInt)
	{
		if (lobbyChoiceInt == 1)
		{
			player1.lobbyDisplayStats();
			cout << endl;
			lobbyMenu(player1, ability1, currentMob);
		}
		else if (lobbyChoiceInt == 2)
		{
			roomOne(player1, ability1, currentMob);
			lobbyMenu(player1, ability1, currentMob);
		}

		else if (lobbyChoiceInt == 3)
		{
			roomTwo(player1, ability1, currentMob);
			lobbyMenu(player1, ability1, currentMob);
		}

		else if (lobbyChoiceInt == 4)
		{

			player1.playerWeapon = chooseWeapon();
			player1.weaponModifier();
			cout << endl;
			lobbyMenu(player1, ability1, currentMob);

		}
		else if (lobbyChoiceInt == 5)
		{
			player1.saveHero();
			lobbyMenu(player1, ability1, currentMob);

		}
		else if (lobbyChoiceInt == 6)
		{
			mMenu();
		}

		else
		{
			cout << "*Invalid option*" << endl;
			lobbyMenu(player1, ability1, currentMob);
		}
	}
	
	else
	{
		cout << "*Invalid option*" << endl;
		lobbyMenu(player1, ability1, currentMob);
	}

}