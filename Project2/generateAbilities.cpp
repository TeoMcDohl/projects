#include "stdafx.h"
#include <string>
#include "hero.h"
#include "abilities.h"
#include <iostream>
#include <sstream>
//Not a fan of this method right now.
abilities makeAbility(hero& player1)
{
	using namespace std;
	if (player1.heroID == 1)
	{
		abilities overpower{ "Overpower",7 };
		return overpower;
	}
	else if (player1.heroID == 2)
	{
		abilities magicMissile{ "Magic Missile",8 };
		return magicMissile;
	}
}