#include <iostream>

#include "Game.h"




//	エントリー関数
int main()
{
	std::cout << "[BOOT] Starting application.\n" << std::endl;

	Game game;
	game.Run();

	return 0;
}



//	参考資料
// Assignment
//	https://yamato-t.github.io/education/1.C%2B%2B%E8%B3%87%E6%96%99/09.%E8%A8%AD%E8%A8%88/7.%E8%AA%B2%E9%A1%8C/

// じゃんけんゲーム
//	https://note.com/brain_up0505/n/n56215218bbb6

// C++基礎
// //	class
//	https://qiita.com/Yuya-Shimizu/items/45d42fe2942a684fa96a
// //	struct
//	https://qiita.com/pink_bangbi/items/e25302df7f4ba7fa0db4
//	//	cin
//	https://aeroastro.sd.tmu.ac.jp/hydrodynamics/main/colums/CPP/std_cin.html
// //	if
//	https://qiita.com/rapirapi/items/0b4af3fd65c169826ddd
//	// ランダム
//	https://qiita.com/tsukino_/items/01acf1c16f4a3d753094

//	その他
//	gpt-5.6-Terra effort: medium
//	書き込み禁止の相談役。
//	エラーの原因が分からないときとやり方が分からず詰まったときに相談に乗ってもらいました。