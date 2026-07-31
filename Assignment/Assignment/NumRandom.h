#pragma once

class NumRandom
{
public:
	int getJobNum();
	int getActionNum();

private:
	int createRandomNum(int min, int max);
};
