#include "stdafx.h"
#include <iostream>
#include "functionloader.h"
#include <string>
using std::string;

string intro()
{
	string heroname = "Hero";
	using namespace std;
	cout << endl;
	cout << "NAME YOUR HERO:  ";
	getline(cin, heroname);
	if (heroname.empty())
	{
		heroname = "Hero";
		return heroname;
	}
	cout << std::endl;
	return heroname;
}
