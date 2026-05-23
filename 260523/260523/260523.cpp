#include <iostream>
#include <random>

using namespace std;

int main()
{
	int input;

	//	0から9の範囲でランダムな整数を1つ生成
	random_device rd;
	uniform_int_distribution<int>dist(0, 9);
	int num = dist(rd);

	//数値入力
	cout << "数値を1つ入力\n";
	cin >> input;

	//	もし input が dist(rd) と値が```等しい```ならば
	if (input == num)
	{
		cout << "ゲームクリア";
	}
	//	もし input が dist(rd) よりも値が```大きい```ならば
	else if (input > num)
	{
		cout << "大きい";
	}
	
	//	もし input が dist(rd) よりも値が```小さい```ならば
	else if (input < num)
	{
		cout << "小さい";
	}
}

//	参考サイト
//  https://dexall.co.jp/articles/?p=1902#i-7
//	https://aeroastro.sd.tmu.ac.jp/hydrodynamics/main/colums/CPP/std_cin.html