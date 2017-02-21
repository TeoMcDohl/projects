#include "stdafx.h"
#include "functionloader.h"

int fightmenu()
{
	
	using namespace std;
	
	cout << "1: Fight\n";
	cout << "2: Magic (3 MP)\n";
	cout << endl;
	cout << "Command? ";
	string menuCmd;
	int menuCmdint;
	getline(cin, menuCmd);
	stringstream fightStream(menuCmd);
	if (fightStream >> menuCmdint)
	{
		return menuCmdint;
	}
	else
	{
		return -1;
	}
}