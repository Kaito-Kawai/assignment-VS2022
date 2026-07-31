#pragma once

#include "Character.h"

class Swordsman : public Character
{
public:
	Swordsman(int attack);

	const char* getJob() override;
	int getJobNum() override;
	int judgeJob(int guardJob) override;
};
