#include "Swordsman.h"

Swordsman::Swordsman(int attack)
	: Character(attack)
{
}

const char* Swordsman::getJob()
{
	return "Swordsman";
}

int Swordsman::getJobNum()
{
	return 1;
}

int Swordsman::judgeJob(int guardJob)
{
	if (guardJob == 1)
	{
		return 0;
	}
	else if (guardJob == 2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
