#pragma once
class Game
{
public:
	void Run();

private:
	void setting();
	void playTurn();
	int enemyTurn(int enemy,int enemyaction);
};