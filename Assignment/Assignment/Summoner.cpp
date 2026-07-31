#include "Summoner.h"

Summoner::Summoner(int attack)
	: Character(attack)
{
}

const char* Summoner::getJob()
{
	return "Summoner";
}

int Summoner::getJobNum()
{
	return 3;
}

int Summoner::judgeJob(int guardJob)
{
	if (guardJob == 1)
	{
		return 1;
	}
	else if (guardJob == 2)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
