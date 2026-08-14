#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 正解の数字を入れる変数。最初は-1を設定する
    int answer = -1;

    // コンピュータがランダムに決める正解の数字を入れる変数
    int question;

    // プレイヤーが何回数字を入力したかを数える変数
    int count = 0;

    // 現在の時刻を使って乱数のパターンを毎回変える
    srand((unsigned int)time(nullptr));

    // 0～100の中からランダムに正解の数字を決める
    question = rand() % 101;

    // ゲームのタイトルとルールを表示する
    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;

    // 正解するまでゲームを繰り返す
    while (question != answer)
    {
        // 数字を入力するたびに挑戦回数を1増やす
        count++;

        // 正しい範囲の数字が入力されるまで繰り返す
        while (true)
        {
            // プレイヤーに0～100の数字を入力してもらう
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;

            // 0～100以外の数字が入力された場合は再入力させる
            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                // 正しい範囲の数字なら入力処理を終了する
                break;
            }
        }

        // 入力した数字が正解より小さい場合、大きい数字を入力する
        if (question > answer)
        {
            cout << "もっと大きい数字です。" << endl;
        }

        // 入力した数字が正解より大きい場合、小さい数字を入力する
        else if (question < answer)
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }

    // 正解したことと、正解の数字、挑戦回数を表示する
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    // プログラムを終了する
    return 0;
}