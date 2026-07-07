// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <conio.h> 

enum
{
	SCENE_OP,
	SCENE_GAME,
	SCENE_RESULT,
};
class GameManager
{
private:
	//	コンストラクタ
	//	オブジェクトを外部から生成するのを防ぐためprivateコンストラクタ
	GameManager(){}
	
public:

	int scene = 0;
	char key = 0;

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

	

	
	//	ゲーム画面
	void StartGame()
	{
		scene = SCENE_OP;

		switch (scene)
		{
		case SCENE_OP:
			
			std::cout << "タイトル画面" << std::endl;
			std::cout << "なにかキーをおすとゲーム開始" << std::endl;
			
			key = _getch();
			if (key==32)
			{
				scene = SCENE_GAME;
				key = 0;
			}
			
			system("cls");

				break;
		case SCENE_GAME:
			if (key == _getch())
			{
				scene = SCENE_RESULT;
				key = 0;
			}

			std::cout << "ゲーム画面" << std::endl;
			

				break;
		case SCENE_RESULT:
			std::cout << "結果画面" << std::endl;
			
				break;


		}

		//	ゲーム開始処理
		
	}

};

//GameManager obj;

int main()
{
	//	使用例
	GameManager::Instance().StartGame();
}


