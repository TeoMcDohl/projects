#include "stdafx.h"
#include <iostream>
#include "hero.h"
#include "monster.h"
#include "functionloader.h"
#include <time.h>

void mMenu()
{
	using namespace std;
	hero player1;
	mob currentMob;
	cout << "----------------------" << endl;
	cout << "|       RPG++        |" << endl;
	cout << "----------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Quit" << endl;
	cout << endl;
	string input;
	int inputInt;
	int exitToMenu;
	getline(cin, input);
	stringstream inputStream(input);
	if (inputStream >> inputInt)
	{
		if (inputInt == 1)
		{
			string heroname = intro();
			hero player1 = chooseHero();
			while (player1.isGoodChoice == false)
			{
				player1 = chooseHero();
			}
			player1.heroName = heroname;
			abilities ability1 = makeAbility(player1);
			lobby(player1, currentMob);
			lobbyMenu(player1, ability1, currentMob);

		}
		else if (inputInt == 2)
		{
			ifstream heroLoad;
			heroLoad.open("save.txt");
			if (heroLoad.is_open())
			{
				heroLoad.close();
				player1.loadHero();
				abilities ability1 = makeAbility(player1);
				lobby(player1, currentMob);
				lobbyMenu(player1, ability1, currentMob);
			}
			else
			{
				cout << "No saved game found" << endl;
				cout << endl;
				mMenu();
			}
		}
		else if (inputInt == 3)
		{
			exit(0);
		}
		else if (inputInt != 1 && inputInt != 2 && inputInt != 3)
		{
			cout << "invalid option" << endl;
			mMenu();
		}
	}
	else
	{
		cout << "invalid option" << endl;
		mMenu();
	}
}