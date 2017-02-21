#ifndef FUNCTIONLOADER
#define FUNCTIONLOADER


#include <string>
#include "monster.h"
#include "hero.h"
#include "abilities.h"
#include <sstream>
#include <iostream>


using std::string;
void mMenu();
string intro();
abilities makeAbility(hero&);
void roomOne(hero&, abilities&, mob&);
void roomTwo(hero&, abilities&, mob&);
int fightmenu();
int endCondition(hero&,mob&);
void fightengine(hero&, abilities&, mob&);
mob makeOurMob(int);
hero chooseHero();
void lobby(hero&, mob&);
void lobbyMenu(hero&, abilities&, mob&);
int chooseWeapon();
#endif