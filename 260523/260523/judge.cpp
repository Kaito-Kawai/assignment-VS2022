#include "judge.h"
#include<iostream>

using namespace std;

bool judge(int input, int num)
{
	return input == num;
}

void print(int input, int num)
{
	if (input > num)
	{
		cout << "‘å‚«‚¢\n";
	}
	else
		cout << "¬‚³‚¢\n";
}