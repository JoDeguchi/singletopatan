// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

class GameManager
{
private:
	//	コンストラクタ
	//	オブジェクトを外部から生成するのを防ぐためprivateコンストラクタ
	GameManager(){}
public:

	//	コピー代入の禁止
	//	ゲームマネージャを値を変えないようにして参照。deleteでコピーしないように削除
	//	コピーコンストラクタ
	//	別のオブジェクトのコピーを禁止するため
	GameManager(const GameManager&) = delete;
	//	別のオブジェクトのコピーを禁止するためのコピーコンストラクタ
	GameManager& operator=(const GameManager&) = delete;

	//	スタティック領域（void と違って関数内でかいたint型変数などを保持できる）
	//	スレッドセーフなGameManager唯一のオブジェクトをかえすことができる
	static GameManager& Instance()
	{
		static GameManager instance;	//	C++11以降のスレッドセーフなローカル
		return instance;
	}

	void StartGame()
	{
		//	ゲーム開始処理
	}

};

//GameManager obj;

int main()
{
	//	使用例
	GameManager::Instance().StartGame();

	//GameManager* instance = new GameManager();
}


