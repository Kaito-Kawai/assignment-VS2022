#include "Judge.h"

#include "Game.h"

#include <iostream>


void Judge::judge(int select, int actionselect, int enemy, int enemyaction)
{
	if (actionselect == 1 && enemyaction == 2)
	{
		//	Player ‚ªUŒ‚A“G‚ª–hŒä
		judgeJob(select, enemy);
	}
	else if (actionselect == 2 && enemyaction == 1)
	{
		//	“G‚ªUŒ‚APlayer ‚ª–hŒä
		judgeJob(enemy, select);
	}
	else
	{
		//	ƒhƒ[
	}
}


void Judge::judgeJob(int attackJob, int guardJob)
{
	if (attackJob == guardJob)
	{
		std::cout << "ƒhƒ[I" << std::endl;
	}
	else if
		(
			(attackJob==1&&guardJob==2)
		)
}