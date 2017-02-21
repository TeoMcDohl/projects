#include "stdafx.h"
#include <iostream>
#include "hero.h"
#include "monster.h"
#include "functionloader.h"

int chooseWeapon()
{
	using namespace std;
	cout << "Choose your weapon: \n";
	cout << "1: Broad Sword: More misses, more damage. \n";
	cout << "2: Long Sword: Standard weapon. \n";
	cout << "3: Rapier: Less damage, high accuracy rate. \n";
	cout << endl;
	string weaponCmd;
	int weaponCmdint;
	getline(cin, weaponCmd);
	stringstream weaponStream(weaponCmd);
	if (weaponStream >> weaponCmdint)
	{
		if (weaponCmdint == 1)
		{
			return 1;
		}
		if (weaponCmdint == 2)
		{
			return 2;
		}
		if (weaponCmdint == 3)
		{
			return 3;
		}
		else
		{
			cout << "Invalid option. \n";
			chooseWeapon();
		}
	}
	else
	{
		cout << "Invalid option. \n";
		chooseWeapon();
	}
	return 1;
}