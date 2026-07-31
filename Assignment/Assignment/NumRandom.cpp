#include "NumRandom.h"

#include <random>

int NumRandom::getJobNum()
{
	return createRandomNum(1, 3);
}

int NumRandom::getActionNum()
{
	return createRandomNum(1, 2);
}

int NumRandom::createRandomNum(int min, int max)
{
	static std::mt19937 engine{ std::random_device{}() };
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(engine);
}
