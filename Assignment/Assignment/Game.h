#pragma once
class Game
{
public:
	void Run();

private:
	void setting();
	void playTurn();
	void enemyTurn(int enemy,int enemyaction);
};