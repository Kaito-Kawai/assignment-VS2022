#include "NumRandom.h"
#include <random>
#include <ctime>

int NumRandom::getNum()
{
	return createRandomNum();
}

int NumRandom::createRandomNum()
{
	int num;
	srand((int)time(nullptr));
	num = rand() % 3;
	
	return num;
}