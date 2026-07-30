#pragma once

#include "Character.h"

class Game
{
public:
	void Run();

private:
	character sword;
	character wizard;
	character summoner;
	
	void setting();
	void playTurn();
	void enemyTurn(int& enemy,int& enemyaction);
};