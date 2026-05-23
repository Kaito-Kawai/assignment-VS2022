#include "input.h"
#include<iostream>
#include<random>

using namespace std;

int rnd()
{
	//	0‚©‚ç9‚Ì”ÍˆÍ‚Åƒ‰ƒ“ƒ_ƒ€‚È®”‚ğ1‚Â¶¬
	random_device rd;
	uniform_int_distribution<int>dist(0, 9);
	int num = dist(rd);

	return num;
}

int keyinput()
{
	int keyin;

	//”’l‚ğ“ü—Í
	cout << "”’l‚ğ1‚Â“ü—Í\n";
	cin >> keyin;

	return keyin;
}