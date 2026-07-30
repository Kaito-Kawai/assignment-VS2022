#include "NumRandom.h"
#include <random>

int NumRandom::getNum()
{
	return createRandomNum();
}

int NumRandom::createRandomNum()
{
	static std::mt19937 engine{ std::random_device{}() };
	static std::uniform_int_distribution<int> distribution(1, 3);

	return distribution(engine);
}