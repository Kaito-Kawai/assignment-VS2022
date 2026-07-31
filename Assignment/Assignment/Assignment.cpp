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
//	//	string型 と int型 の相互変換
//	https://qiita.com/seal_qiita/items/d62192f8d0b1e4ca8de2	
//	他に何個かあったけど Chrome の履歴が全期間分どっか行って最悪。
//	 ↑次の日見たらまた消えてて何なん？1日分しか残せんの？？？
//	出てきた
//	std::unique_ptr
//	https://qiita.com/sinndasakana/items/44610e54b168519d0915
//	


//	その他
// 
//	翻訳
//	gemini-3.1-pro
//	何か英語の方がかっこいい。読めないけど
// 
// 相談役
//	gpt-5.6-Terra effort: medium/ultra
//	エラーの原因が分からないときと、やり方が分からず詰まったときに相談したモデル
// 
//	相談役2 / 課題条件を満たしているかの確認役
//	gpt-5.6-Sol effortt: medium
//	Terraが指示を無視してデータ消したりしてきた。gpt-5.5と同等性能なんて嘘だ
//	sol優秀マジ大好き。でも token 喰い過ぎ。太るぞ