#include "stdafx.h"
#include <iostream>
#include "hero.h"
#include "monster.h"
#include "functionloader.h"

int endCondition(hero& player1, mob& currentMob)
{
	
	using namespace std;
	if (currentMob.mobHealth > 0 && player1.playerHealth < 1)
	{
		cout << player1.heroName << " has failed....\n";
		cout <<  "Returning to menu.\n";
		player1.playerHealth = player1.maxHealth;
		player1.playerMana = player1.maxMana;
	}

	else if (currentMob.mobHealth <= 0 && player1.playerHealth >= 1)
	{
		cout << "The " << currentMob.mobName << " has been defeated!\n";
		cout << "Health and Mana restored! \n";
		player1.playerHealth = player1.maxHealth;
		player1.playerMana = player1.maxMana;
		if (currentMob.mobID == 1)
		{
			player1.expPoints++;
		}
		else if (currentMob.mobID == 2)
		{
			player1.expPoints = player1.expPoints + 2;
		}
		else if (currentMob.mobID == 3)
		{
			player1.expPoints = player1.expPoints + 3;
		}
		player1.checkLevelUp();
	}
	else if (currentMob.mobHealth < 1 && player1.playerHealth < 1)
	{
		cout << player1.heroName << " and " << currentMob.mobName << " have been defeated!\n";
		player1.playerHealth = player1.maxHealth;
		player1.playerMana = player1.maxMana;

	}
	return 0;
}