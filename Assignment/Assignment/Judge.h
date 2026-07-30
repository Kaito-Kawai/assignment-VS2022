#pragma once

class Judge
{

public:
	void judge
	(
		int select, int actionselect,
		int enemy, int enemyaction,

		int playerAttack, int enemyAttack,
		int& playerTeam, int&enemyTeam
	);
	
private:
	void judgeJob(
		int attakcJob, int guardJob,
		int attackPower,
		int& attackTeam, int& guardTeam);
};

