#include "Judge.h"

#include "Game.h"

#include <iostream>


void Judge::judge(int select, int action, int enemy, int enemyaction)
{
	if (select == 1)
	{
		if (enemy == 1)
		{
			std::cout << "ドロー！" << std::endl;
		}
		else if (enemy == 2)
		{

		}
		else
		{

		}
	}
	else if (select == 2)
	{
		if (enemy == 1)
		{

		}
		else if (enemy == 2)
		{
			std::cout << "ドロー！" << std::endl;
		}
		else
		{

		}
	}
	else
	{
		if (enemy == 1)
		{

		}
		else if (enemy == 2)
		{

		}
		else
		{
			std::cout << "ドロー！" << std::endl;
		}
	}

	return;
}