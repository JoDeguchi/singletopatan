
#include <iostream>

class GameManager
{
private:
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
    void StartGame()
    {
       
        //  ゲーム開始処理
    }
};

int main()
{
    GameManager::Instance().StartGame();
}
