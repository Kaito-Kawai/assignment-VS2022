#pragma once
class Judge
{

public:
	void judge
	(
		int select, int actionselect,
		int enemy, int enemyaction
	);
	
private:
	void judgeJob(int attakcJob, int guardJob);
};

