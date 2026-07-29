#include "Game.h"

#include "Character.h"
#include "NumRandom.h"
#include "Judge.h"

#include <iostream>



void Game::Run()
{
	std::cout << "===陣営ゲーム===\n" << std::endl;
	std::cout << "- ルール- \n" << std::endl;
	std::cout << "1. 味方陣営から一人選び、行動を選んでください。\n" << std::endl;
	std::cout << "2. 敵陣営から一人、ランダムに選ばれ、行動します。\n" << std::endl;
	std::cout << "3. これを`1ターン`とし、先に相手陣営の戦力をゼロにすると勝利します。\n\n" << std::endl;
	std::cout << "このゲームは半角数字の1,2,3のみを使用します。選択肢以外の値を入力するとError終了します。\n\n" << std::endl;
	std::cout << "それでは、ゲームスタートです。\n\n・\n・\n・\n\n" << std::endl;

	


}


void Game::setting()
{
	character sword = { "sword",35 };
	character wizard = { "wizard",40 };
	character summoner = { "summoner",25 };
}


void Game::playTurn()
{
	int select = 0;
	int actionSelect = 0;

	int enemy = 0;
	int enemyaction = 0;

	std::cout << "味方陣営から一人選びましょう。\n" << std::endl;
	std::cout << "1: 剣士 / 2 : 魔法使い / 3 : 召喚師" << std::endl;

	std::cin >> select;

	std::cout << "\n＞" << select << " : 次に行動を選びましょう。\n" << std::endl;
	std::cout << "1: 攻撃 / 2: 防御" << std::endl;

	std::cin >> actionSelect;

	std::cout << "\n行け！" << "。 " << "だ！\n" << std::endl;

	enemyTurn(enemy, enemyaction);

	Judge gameJudge;
	gameJudge.judge(select, actionSelect, enemy, enemyaction);


}

int Game::enemyTurn(int enemy, int enemyaction)
{
	NumRandom randomNum;	//	インスタンス化

	enemy = randomNum.getNum();
	enemyaction = randomNum.getNum();
}