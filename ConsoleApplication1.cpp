
#include <iostream>
#include "conio.h"
#include <cstdlib> 

enum
{
    SCENE_OP,       //  タイトル
    SCENE_GAME,     //  ゲーム中身
    SCENE_RESULT,   //  結果
};

//  ゲーム管理クラス
class GameManager
{
private:
    int scene = SCENE_OP;   //  タイトル画面から開始
    int random = 0;
    //  コンストラクタ
    GameManager(){}
public:
    //  コピーの禁止　コピーコンストラクタ
    //  constで値を変えない
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    //  スタティック（値を保持する役割）
    //  インスタンス１つだけで
    static GameManager& Instance()
    {
        static GameManager instance;    //  C++11以降のスレッドセーフなローカル
        return instance;

    }
    //  ゲーム処理
    void StartGame()
    {
        while (1)
        {
            //  切り替えるときに画面をクリーンにする
            system("cls");

            switch (scene)
            {
            case SCENE_OP:
                std::cout << "タイトル画面" << std::endl;
                std::cout << "何かキーを押したらゲーム画面に" << std::endl;
                scene = SCENE_GAME;
                break;

            case SCENE_GAME:
                std::cout << "ゲーム画面" << std::endl;
                std::cout << "何かキーを押したら結果画面へ" << std::endl;
                scene = SCENE_RESULT;
                break;

            case SCENE_RESULT:
                std::cout << "結果画面（ランダム）" << std::endl;
                std::cout << "何かキーを押してもう１度タイトル画面に" << std::endl;

                //  ゲームオーバーかゲームクリアかランダム
                random = rand() % 2;    

                if (random == 0)
                {
                    std::cout << "\nゲームクリア" << std::endl;
                }
                else if (random == 1)
                {
                    std::cout << "\nゲームオーバー" << std::endl;
                }
                scene= SCENE_OP;
                break;

            }

            // キー入力　別々だとちかちかするのでwhileでまとめる
            while (_kbhit()) {}  
            _getch();    

        }
        
    }
};

int main()
{
    GameManager::Instance().StartGame();
}
