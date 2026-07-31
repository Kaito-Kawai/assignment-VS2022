#pragma once

#include "Character.h"

class Summoner : public Character
{
public:
	Summoner(int attack);

	const char* getJob() override;
	int getJobNum() override;
	int judgeJob(int guardJob) override;
};
