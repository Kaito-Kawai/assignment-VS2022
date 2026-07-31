#include "Judge.h"

#include <iostream>

void Judge::judge
(
	Character* playerCharacter, int actionSelect,
	Character* enemyCharacter, int enemyaction,
	Team& playerTeam, Team& enemyTeam
)
{
	if (actionSelect == 1 && enemyaction == 2)
	{
		judgeJob(playerCharacter, enemyCharacter, playerTeam, enemyTeam);
	}
	else if (actionSelect == 2 && enemyaction == 1)
	{
		judgeJob(enemyCharacter, playerCharacter, enemyTeam, playerTeam);
	}
	else if (actionSelect == 1 && enemyaction == 1)
	{
		if (playerCharacter->getAttack() > enemyCharacter->getAttack())
		{
			std::cout << "[BATTLE] Player attack is stronger." << std::endl;
			enemyTeam.takeDamage(playerCharacter->getAttack());
			std::cout << "[BATTLE] Damage: "
				<< playerCharacter->getAttack() << std::endl;
		}
		else if (enemyCharacter->getAttack() > playerCharacter->getAttack())
		{
			std::cout << "[BATTLE] Enemy attack is stronger." << std::endl;
			playerTeam.takeDamage(enemyCharacter->getAttack());
			std::cout << "[BATTLE] Damage: "
				<< enemyCharacter->getAttack() << std::endl;
		}
		else
		{
			std::cout << "[BATTLE] Draw. No damage." << std::endl;
		}
	}
	else
	{
		std::cout << "[BATTLE] Both sides guard. No damage." << std::endl;
	}
}

void Judge::judgeJob
(
	Character* attackCharacter,
	Character* guardCharacter,
	Team& attackTeam,
	Team& guardTeam
)
{
	int result = attackCharacter->judgeJob(guardCharacter->getJobNum());

	if (result == 0)
	{
		std::cout << "[BATTLE] Draw. No damage." << std::endl;
	}
	else if (result == 1)
	{
		std::cout << "[BATTLE] Counter!" << std::endl;
		attackTeam.takeDamage(attackCharacter->getAttack() * 2);
		std::cout << "[BATTLE] Damage: "
			<< attackCharacter->getAttack() * 2 << std::endl;
	}
	else
	{
		std::cout << "[BATTLE] Critical!" << std::endl;
		guardTeam.takeDamage(attackCharacter->getAttack() * 2);
		std::cout << "[BATTLE] Damage: "
			<< attackCharacter->getAttack() * 2 << std::endl;
	}
}
