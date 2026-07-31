#pragma once

#include "Character.h"

class Wizard : public Character
{
public:
	Wizard(int attack);

	const char* getJob() override;
	int getJobNum() override;
	int judgeJob(int guardJob) override;
};
