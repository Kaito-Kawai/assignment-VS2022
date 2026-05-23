#include <iostream>
#include "input.h"
#include "judge.h"

using namespace std;

int main()
{
	int num = rnd();

	while (true)
	{
		int key = keyinput();

		if (judge(key, num))
		{
			cout << "ゲームクリア";
			break;
		}
		print(key, num);
	}
}

//	参考サイト
//  https://dexall.co.jp/articles/?p=1902#i-7
//	https://aeroastro.sd.tmu.ac.jp/hydrodynamics/main/colums/CPP/std_cin.html