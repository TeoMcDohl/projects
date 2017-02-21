#ifndef HERO
#define HERO
#include "stdafx.h"
#include <string>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>

using std::string;

class hero
{
public:
	string heroName;
	int playerHealth;
	int maxHealth;
	int strength;
	int intellect;
	int playerMana;
	int maxMana;
	int playerDamage;
	int playerWeapon;
	int playerDmgMod;
	int hitRate;
	bool isGoodChoice;
	int expPoints;
	int playerLevel;
	int heroID;

	
	void pDamage()
	{
		playerDamage = rand() % strength + 1;
		playerDamage = playerDamage + playerDmgMod;
	}
	void mDamage(int modifierDmg, int modifierStat)
	{
		playerDamage = rand() % modifierStat + modifierDmg;
	}
	int chanceToHit()
	{
		int calcChance;
		signed srand(time(0));
		calcChance = rand() % 100 + 1;

		if (calcChance > hitRate)
		{
			return 1;
		}
		else if (calcChance <= hitRate)
		{
			return 2;
		}
	}
	void displayStats()
	{
		using namespace std;
		cout << heroName << "'s health is " << playerHealth << "\n";
		cout << heroName << "'s mana is " << playerMana << "\n";
		cout << endl;

	}
		
	void lobbyDisplayStats()
		{
		using namespace std;
		cout << heroName << "'s health is " << playerHealth << "\n";
		cout << heroName << "'s mana is " << playerMana << "\n";
		cout << "Level: " << playerLevel << endl;
		cout << "Experience: " << expPoints << endl;
		cout << "Strength: " << strength << "\n";
		displayWeapon();
		cout << endl;
		cout << "Hite Rate: " << 100 - hitRate << "% \n";
		cout << playerDmgMod << " Damage \n";
		}
	void displayWeapon()
	{
		using namespace std;
		string weaponName;
		if (playerWeapon == 1)
		{
			weaponName = "Broad Sword";
		}
		if (playerWeapon == 2)
		{
			weaponName = "Long Sword";
		}
		if (playerWeapon == 3)
		{
			weaponName = "Rapier";
		}
		
		cout << "Weapon: " << weaponName;
	}
	void weaponModifier()
	{
		if (playerWeapon == 1)
		{
			playerDmgMod = 4;
			hitRate = 40;
		}
		if (playerWeapon == 2)
		{
			playerDmgMod = 2;
			hitRate = 30;
		}
		if (playerWeapon == 3)
		{
			playerDmgMod = 1;
			hitRate = 15;
		}
	}
	void saveHero()
	{
		using namespace std;
		ofstream heroSave;
		heroSave.open("save.txt");
		heroSave << heroName << endl << playerHealth << endl << maxHealth << endl << strength << endl << intellect << endl << playerMana
			<< endl << maxMana << endl << playerDamage << endl << playerWeapon << endl << playerDmgMod << endl << hitRate << endl << isGoodChoice << endl << expPoints << endl << playerLevel << endl << heroID << endl;
		heroSave.close();
	}
	void loadHero()
	{
		using namespace std;
		ifstream heroLoad;
		heroLoad.open("save.txt");
		heroLoad >> heroName >> playerHealth >> maxHealth >> strength >> intellect >> playerMana >> maxMana >> playerDamage >> playerWeapon >> playerDmgMod >> hitRate >> isGoodChoice >> expPoints >> playerLevel >> heroID;
		heroLoad.close();
	}

	void levelUp()
	{
		playerHealth = playerHealth + 10;
		maxHealth = maxHealth + 10;
		maxMana = maxMana + 2;
		playerMana = playerMana + 2;
		strength = strength + 1;
		intellect = intellect + 1;
		playerLevel++;

	}
	void checkLevelUp()
	{
		using namespace std;
		if (expPoints >= 10)
		{
			levelUp();
			cout << endl;
			cout << "You gained a level!" << endl;
			cout << endl;
			expPoints = 0;
		}
		
	}

	int heroMenu(int heroID)
	{
		using namespace std;
		if (heroID == 1)
		{
			
			cout << "1: Fight\n";
			cout << "2: Overpower (3 MP)\n";
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
		else if (heroID == 2)
		{
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
	}
};

#endif 

