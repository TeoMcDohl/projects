#include "stdafx.h"
#include <iostream>
#include "hero.h"
#include "monster.h"
#include "functionloader.h"

void fightengine(hero& player1, abilities& ability1, mob& currentMob)

{
	using namespace std;
	cout << endl;
	while (currentMob.mobHealth >= 1 && player1.playerHealth >= 1)
	{
		
		int choice = player1.heroMenu(player1.heroID);
		cout << endl;
		if (choice == 1 && player1.playerHealth >= 1)
		{
			int heroChanceToHit;
			heroChanceToHit = player1.chanceToHit();
			if (heroChanceToHit == 1)
			{
				player1.pDamage();
				currentMob.mobHealth = currentMob.mobHealth - player1.playerDamage;
				cout << "You hit the " << currentMob.mobName << " for " << player1.playerDamage << " damage!" << endl;
				cout << endl;
			}
			else if (heroChanceToHit == 2)
			{
				cout << player1.heroName << " Misses!\n\n";
			}
			int mobChanceToHit;
			mobChanceToHit = currentMob.chanceToHit();
			if (mobChanceToHit == 1)
			{
				currentMob.monsterDamage();
				player1.playerHealth = player1.playerHealth - currentMob.mobDamage;
				cout << currentMob.mobName << " hits you for " << currentMob.mobDamage << " damage!" << "\n";
				cout << "\n";
			}
			else if (mobChanceToHit == 2)
			{
				cout << currentMob.mobName << " Misses!\n\n";
			}

		}
		else if (choice == 2 && player1.playerHealth >= 1 && player1.playerMana >= 3)
		{
			int modifierDmg = ability1.damageMod;
			int modifierStat;
			if (player1.heroID == 1)
			{
				modifierStat = player1.strength;
			}
			else if (player1.heroID == 2)
			{
				modifierStat = player1.intellect;
			}
			player1.mDamage(modifierDmg, modifierStat);
			currentMob.mobHealth = currentMob.mobHealth - player1.playerDamage;
			cout << "You use " << ability1.name << " for " << player1.playerDamage << " damage!" << "\n";
			cout << "\n";
			player1.playerMana = player1.playerMana - 3;
			currentMob.monsterDamage();
			player1.playerHealth = player1.playerHealth - currentMob.mobDamage;
			cout << currentMob.mobName << " slaps you for " << currentMob.mobDamage << " damage!" << "\n";
			cout << "\n";
		}

		else if (choice == 2 && player1.playerHealth >= 1 && player1.playerMana < 3)
		{
			cout << "Insufficient mana!\n" << "\n";
		}
		else
		{
			cout << "*Invalid option*" << "\n" << "\n";
		}

		player1.displayStats();
		currentMob.displayStats();
		cout << "\n";
	}
	
	
}