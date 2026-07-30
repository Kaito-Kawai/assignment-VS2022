#include "Game.h"

#include "Character.h"
#include "NumRandom.h"
#include "Judge.h"

#include <iostream>

//	戦力
int playerTeam = 300;
int enemyTeam = 300;

int playerAttack = 0;
int enemyAttack = 0;

//	攻撃力
int swordPower = 35;
int wizardPower = 40;
int summonerPower = 25;

void Game::Run()
{
	std::cout << "[INIT] Initializing game state.\n" << std::endl;

	setting();

	if (playerTeam == 300 && enemyTeam == 300 && playerAttack == 0 && enemyAttack == 0)
	{
		if (sword.attack == 35 && wizard.attack == 40 && summoner.attack == 25)
		{
			//	成功
			std::cout << "[INIT] Initialization complete.\n" << std::endl;
		}
		else
		{
			//	失敗。終了します。
			std::cout << "[ERROR] Initialization failed.\n" << std::endl;
			return;
		}
	}
	else
	{
		//	失敗。終了します。
		std::cout << "[ERROR] Initialization failed.\n" << std::endl;
		return;
	}


	//	ゲーム開始
	std::cout << "===陣営ゲーム===\n" << std::endl;
	std::cout << "- ルール- \n" << std::endl;
	std::cout << "1. 味方陣営から一人選び、行動を選んでください。\n" << std::endl;
	std::cout << "2. 敵陣営から一人、ランダムに選ばれ、行動します。\n" << std::endl;
	std::cout << "3. これを`1ターン`とし、先に相手陣営の戦力をゼロにすると勝利します。\n\n" << std::endl;
	std::cout << "このゲームは半角数字の1,2,3のみを使用します。選択肢以外の値を入力するとError終了します。\n\n" << std::endl;
	std::cout << "それでは、ゲームスタートです。\n\n・\n・\n・\n\n" << std::endl;

	while (playerTeam > 0 && enemyTeam > 0)
	{
		playTurn();
	}
	
	if (playerTeam <= 0)
	{
		std::cout << "[RESULT] Enemy team wins." << std::endl;
	}
	else
	{
		std::cout << "[RESULT] Player team wins." << std::endl;
	}


}


void Game::setting()
{
	sword = { "sword",swordPower };
	wizard = { "wizard",wizardPower };
	summoner = { "summoner",summonerPower };
}


void Game::playTurn()
{
	int select = 0;
	int actionSelect = 0;

	int enemy = 0;
	int enemyaction = 0;

	std::cout << "味方陣営から一人選びましょう。\n" << std::endl;
	std::cout << "1: 剣士 / 2 : 魔法使い / 3 : 召喚士\n" << std::endl;

	std::cin >> select;

	if (select == 1)
	{
		std::cout << "剣士を選択しました。\n"<<std::endl;
	}
	else if (select == 2)
	{
		std::cout << "魔法使いを選択しました。\n" << std::endl;
	}
	else if (select == 3)
	{
		std::cout << "召喚士を選択しました。\n" << std::endl;
	}
	else
	{
		return;
	}

	std::cout << "次に行動を選びましょう。\n" << std::endl;
	std::cout << "1: 攻撃 / 2: 防御" << std::endl;

	std::cin >> actionSelect;

	if (actionSelect == 1)
	{
		std::cout << "\n\n「行け！。 攻撃だ！」\n" << std::endl;
	}
	else if (actionSelect == 2)
	{
		std::cout << "\n\n行け！。 防御だ！\n" << std::endl;
	}
	else
	{
		return;
	}
	
	enemyTurn(enemy, enemyaction);

	if (enemy == 1)
	{
		std::cout << "[TURN] Enemy job: 剣士" << std::endl;
		if (enemyaction == 1)
		{
			std::cout << "[TURN] Enemy action: 攻撃" << std::endl;
		}
		else
		{
			std::cout << "[TURN] Enemy action: 防御" << std::endl;
		}
	}
	else if (enemy == 2)
	{
		std::cout << "[TURN] Enemy job: 魔法使い" << std::endl;
		if (enemyaction == 1)
		{
			std::cout << "[TURN] Enemy action: 攻撃" << std::endl;
		}
		else
		{
			std::cout << "[TURN] Enemy action: 防御" << std::endl;
		}
	}
	else
	{
		std::cout << "[TURN] Enemy job: 召喚士" << std::endl;
		if (enemyaction == 1)
		{
			std::cout << "[TURN] Enemy action: 攻撃" << std::endl;
		}
		else
		{
			std::cout << "[TURN] Enemy action: 防御" << std::endl;
		}
	}


	if (select == 1) {playerAttack = sword.attack;}
	else if (select == 2) { playerAttack = wizard.attack; }
	else if (select == 3) { playerAttack = summoner.attack; }

	if (enemy == 1) { enemyAttack = sword.attack; }
	else if (enemy == 2) {enemyAttack = wizard.attack; }
	else if (enemy == 3) {enemyAttack = summoner.attack; }


	Judge gameJudge;


	gameJudge.judge(
		select, actionSelect,
		enemy, enemyaction,
		
		playerAttack, enemyAttack,
		playerTeam, enemyTeam
	);

	std::cout << "[STATUS] Player team power: " << playerTeam << std::endl;
	std::cout << "[STATUS] Enemy team power: " << enemyTeam << std::endl;

}

void Game::enemyTurn(int& enemy, int& enemyaction)
{
	NumRandom randomNum;	//	インスタンス化

	enemy = randomNum.getNum();
	enemyaction = randomNum.getNum();
}