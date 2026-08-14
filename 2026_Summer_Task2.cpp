#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // プレイヤーが出す手を保存する変数
    int player;

    // CPUがランダムに出す手を保存する変数
    int cpu;

    // プレイヤーとCPUの手から勝敗を判定するための変数
    int result;

    // 何回戦目かを数える変数
    int i;

    // プレイヤーの勝利数を数える変数
    int win = 0;

    // プレイヤーの敗北数を数える変数
    int lose = 0;

    // あいこの回数を数える変数
    int draw = 0;

    // 現在の時刻を使って乱数のパターンを毎回変える
    srand((unsigned int)time(nullptr));

    // ゲーム開始のメッセージを表示する
    cout << "じゃんけんゲームを開始します。" << endl;

    // 5回戦するためにループを5回繰り返す
    for (i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "-------- " << i + 1 << "回戦 --------" << endl;

        // プレイヤーが正しい手を入力するまで繰り返す
        while (true)
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;

            // プレイヤーの手を入力する
            cin >> player;

            // 0～2の正しい数字が入力されたら入力処理を終了する
            if (player >= 0 && player <= 2)
            {
                break;
            }

            // 0～2以外が入力された場合は再入力を求める
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }

        // CPUの手を0～2の中からランダムに決める
        cpu = rand() % 3;

        // プレイヤーが選んだ数字に対応する手を表示する
        switch (player)
        {
        case 0:
            cout << "PLAYER：グー" << endl;
            break;

        case 1:
            cout << "PLAYER：チョキ" << endl;
            break;

        case 2:
            cout << "PLAYER：パー" << endl;
            break;
        }

        // CPUが選んだ数字に対応する手を表示する
        switch (cpu)
        {
        case 0:
            cout << "CPU：グー" << endl;
            break;

        case 1:
            cout << "CPU：チョキ" << endl;
            break;

        case 2:
            cout << "CPU：パー" << endl;
            break;
        }

        // プレイヤーとCPUの手の差を計算して勝敗判定に使用する
        result = player - cpu;

        // プレイヤーが勝つ組み合わせの場合
        if (result == -1 || result == 2)
        {
            cout << "PLAYER WIN!" << endl;

            // プレイヤーの勝利数を1増やす
            win++;
        }

        // プレイヤーとCPUの手が同じ場合
        else if (result == 0)
        {
            cout << "DRAW" << endl;

            // あいこの回数を1増やす
            draw++;
        }

        // 上記以外の場合はCPUの勝利
        else
        {
            cout << "CPU WIN!" << endl;

            // プレイヤーの敗北数を1増やす
            lose++;
        }
    }

    // 5回戦終了後に最終結果を表示する
    cout << endl;
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;

    // プレイヤーの勝ち・あいこ・負けの回数を表示する
    cout << win << "勝 "
        << draw << "分 "
        << lose << "敗" << endl;

    cout << "==============================" << endl;

    // プログラムを終了する
    return 0;
}