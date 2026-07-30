#include "Judge.h"

#include <iostream>



void Judge::judge(
	int select, int actionselect,
	int enemy, int enemyaction,

	int playerAttack, int enemyAttack,
	int& playerTeam, int&enemyTeam
	)
{
	if (actionselect == 1 && enemyaction == 2)
	{
		//	Player ‚ªUŒ‚A“G‚ª–hŒä
		judgeJob(select, enemy, playerAttack, playerTeam, enemyTeam);
	}
	else if (actionselect == 2 && enemyaction == 1)
	{
		//	“G‚ªUŒ‚APlayer ‚ª–hŒä
		judgeJob(enemy, select, enemyAttack, enemyTeam, playerTeam);
	}

	else if (actionselect == 1 && enemyaction == 1)

		if (playerAttack > enemyAttack)
		{
			std::cout << "[BATTLE] Player attack is stronger.\n" << std::endl;

			enemyTeam -= playerAttack;
			std::cout << "[BATTLE] Damage: \n" << playerAttack << std::endl;
		}
		else if (enemyAttack>playerAttack)
		{
			std::cout << "[BATTLE] Enemy attack is stronger.\n" << playerAttack << std::endl;

			playerTeam -= enemyAttack;
			std::cout << "[BATTLE] Damage: \n" << enemyAttack << std::endl;
		}
		else
		{
			std::cout << "[BATTLE] Draw. No damage.\n" << std::endl;
		}

	else
	{
		// ƒhƒ[
		std::cout << "[BATTLE] No attack is resolved. No damage." << std::endl;
	}
}


void Judge::judgeJob(
						int attackJob, int guardJob,
						int attackPower,
						int& attackTeam, int& guardTeam)
{
	if (attackJob == guardJob)
	{
		std::cout << "[BATTLE] Draw. No damage." << std::endl;
	}
	else if
		(
			//	ƒJƒEƒ“ƒ^[
			(attackJob == 1 && guardJob == 2) ||
			(attackJob == 2 && guardJob == 3) ||
			(attackJob == 3 && guardJob == 1)
		)
	{
		std::cout << "[BATTLE] Counter!" << std::endl;
		attackTeam -= attackPower * 2;
		std::cout << "[BATTLE] Damage: " << attackPower * 2 << std::endl;
	}
	else
	{
		//	ƒNƒŠƒeƒBƒJƒ‹
		std::cout << "[BATTLE] Critical!" << std::endl;
		guardTeam -= attackPower * 2;
		std::cout << "[BATTLE] Damage: " << attackPower * 2 << std::endl;
	}
}