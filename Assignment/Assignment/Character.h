#pragma once

class Character
{
public:
	virtual ~Character();

	int getAttack();
	virtual const char* getJob() = 0;
	virtual int getJobNum() = 0;
	virtual int judgeJob(int guardJob) = 0;

protected:
	Character(int attack);

private:
	int attack;
};
