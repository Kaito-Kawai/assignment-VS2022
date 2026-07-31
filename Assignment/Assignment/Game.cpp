#include "Game.h"

#include "NumRandom.h"
#include "Judge.h"

#include <iostream>

#include <string>

void Game::Run()
{
	std::cout << "[INIT] Initializing game state.\n" << std::endl;

	setting();

	if (
		playerTeam.getPower() != 300 ||
		enemyTeam.getPower() != 300 ||
		playerTeam.getTotalAttack() != 100 ||
		enemyTeam.getTotalAttack() != 100
		)
	{
		std::cout << "[ERROR] Initialization failed." << std::endl;
		return;
	}

	std::cout << "[INIT] Initialization complete.\n" << std::endl;
	std::cout << "=== Battle Game ===\n" << std::endl;

	while (!playerTeam.isDefeated() && !enemyTeam.isDefeated())
	{
		playTurn();
	}

	if (playerTeam.isDefeated())
	{
		std::cout << "[RESULT] Enemy team wins." << std::endl;
	}
	else
	{
		std::cout << "[RESULT] Player team wins." << std::endl;
	}
}

void Game::setting()
{
	playerTeam.setName("Player");
	enemyTeam.setName("Enemy");
}

void Game::playTurn()
{
	std::string inputselect = "0";
	std::string inputaction = "0";

	int select = 0;
	int actionSelect = 0;
	int enemy = 0;
	int enemyaction = 0;

	std::cout << "Select your character." << std::endl;
	std::cout << "1: Swordsman / 2: Wizard / 3: Summoner" << std::endl;

	std::cin >> select;
	select = std::stoi(inputaction);

	if (select < 1 || select > 3)
	{
		std::cout << "[ERROR] Invalid character selection." << std::endl;
		return;
	}

	std::cout << "Select your action." << std::endl;
	std::cout << "1: Attack / 2: Guard" << std::endl;

	std::cin >> actionSelect;
	actionSelect = std::stoi(inputaction);

	if (actionSelect < 1 || actionSelect > 2)
	{
		std::cout << "[ERROR] Invalid action selection." << std::endl;
		return;
	}

	enemyTurn(enemy, enemyaction);

	Character* playerCharacter = playerTeam.getCharacter(select);
	Character* enemyCharacter = enemyTeam.getCharacter(enemy);

	std::cout << "[TURN] Player job: "
		<< playerCharacter->getJob() << std::endl;

	if (actionSelect == 1)
	{
		std::cout << "[TURN] Player action: Attack" << std::endl;
	}
	else
	{
		std::cout << "[TURN] Player action: Guard" << std::endl;
	}

	std::cout << "[TURN] Enemy job: "
		<< enemyCharacter->getJob() << std::endl;

	if (enemyaction == 1)
	{
		std::cout << "[TURN] Enemy action: Attack" << std::endl;
	}
	else
	{
		std::cout << "[TURN] Enemy action: Guard" << std::endl;
	}

	Judge gameJudge;
	gameJudge.judge(
		playerCharacter, actionSelect,
		enemyCharacter, enemyaction,
		playerTeam, enemyTeam
	);

	std::cout << "[STATUS] Player team power: "
		<< playerTeam.getPower() << std::endl;
	std::cout << "[STATUS] Enemy team power: "
		<< enemyTeam.getPower() << std::endl;
}

void Game::enemyTurn(int& enemy, int& enemyaction)
{
	NumRandom randomNum;

	enemy = randomNum.getJobNum();
	enemyaction = randomNum.getActionNum();
}
