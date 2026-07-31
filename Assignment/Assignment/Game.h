#pragma once

#include "Team.h"

class Game
{
public:
	void Run();

private:
	Team playerTeam;
	Team enemyTeam;

	void setting();
	void playTurn();
	void enemyTurn(int& enemy, int& enemyaction);
};
