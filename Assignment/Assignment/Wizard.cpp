#include "Wizard.h"

Wizard::Wizard(int attack)
	: Character(attack)
{
}

const char* Wizard::getJob()
{
	return "Wizard";
}

int Wizard::getJobNum()
{
	return 2;
}

int Wizard::judgeJob(int guardJob)
{
	if (guardJob == 1)
	{
		return 2;
	}
	else if (guardJob == 2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
