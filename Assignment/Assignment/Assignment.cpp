#include <iostream>

#include "NumRandom.h"
#include "Character.h"





//	エントリー関数
int main()
{


	NumRandom num;	// インスタンス化

	character swordMan = { "sword", 100 };

	std::cout << num.getNum() << std::endl;
	std::cout << swordMan.attack << std::endl;

	return 0;
}



//	参考資料

// じゃんけんゲーム
//	https://note.com/brain_up0505/n/n56215218bbb6

// C++基礎
//	https://qiita.com/Yuya-Shimizu/items/45d42fe2942a684fa96a
//	https://qiita.com/pink_bangbi/items/e25302df7f4ba7fa0db4
//	https://aeroastro.sd.tmu.ac.jp/hydrodynamics/main/colums/CPP/std_cin.html
//	https://qiita.com/rapirapi/items/0b4af3fd65c169826ddd

//	その他
//	gpt-5.6-Terra effort: medium
//	書き込み禁止の相談役。
//	エラーの原因が分からないときとやり方が分からず詰まったときに相談に乗ってもらいました。