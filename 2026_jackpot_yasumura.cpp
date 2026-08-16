#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int MASU = 9;

    // 1～9のマスの取得状況
    // 0 = 未取得、1 = プレイヤー、2 = CPU
    int board[MASU] = {};

    int dice1, dice2;
    int choice;
    int turn = 0;

    // 乱数を初期化
    srand((unsigned int)time(NULL));

    cout << "============================" << endl;
    cout << "       JACKPOT GAME" << endl;
    cout << "============================" << endl;

    // すべてのマスが取られるまでゲームを続ける
    while (true)
    {
        // プレイヤーのターン
        if (turn == 0)
        {
            cout << "\n--- PLAYER TURN ---" << endl;

            // サイコロを2個振る
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;

            cout << "サイコロ：" << dice1 << " と " << dice2 << endl;
            cout << "選べるマス：" << dice1 << "、"
                << dice2 << "、" << dice1 + dice2 << endl;

            // 取れるマスがあるか確認
            bool canTake = false;

            if (dice1 <= 9 && board[dice1 - 1] == 0)
                canTake = true;

            if (dice2 <= 9 && board[dice2 - 1] == 0)
                canTake = true;

            if (dice1 + dice2 <= 9 && board[dice1 + dice2 - 1] == 0)
                canTake = true;

            // 取れるマスがない場合はゲーム終了
            if (!canTake)
            {
                cout << "取れるマスがありません。" << endl;
                cout << "CPUの勝利！" << endl;
                break;
            }

            // プレイヤーが取るマスを入力
            while (true)
            {
                cout << "取るマスを選んでください：";
                cin >> choice;

                // サイコロの結果から選べるマスか確認
                if (choice != dice1 &&
                    choice != dice2 &&
                    choice != dice1 + dice2)
                {
                    cout << "選べないマスです。再入力してください。" << endl;
                    continue;
                }

                // 1～9の範囲か確認
                if (choice < 1 || choice > 9)
                {
                    cout << "そのマスは存在しません。" << endl;
                    continue;
                }

                // すでに取られているか確認
                if (board[choice - 1] != 0)
                {
                    cout << "そのマスはすでに取られています。" << endl;
                    continue;
                }

                break;
            }

            // プレイヤーがマスを取得
            board[choice - 1] = 1;

            cout << choice << "のマスをPLAYERが取りました。" << endl;

            // すべてのマスが取られたか確認
            bool allTaken = true;

            for (int i = 0; i < MASU; i++)
            {
                if (board[i] == 0)
                {
                    allTaken = false;
                    break;
                }
            }

            // 最後のマスを取ったプレイヤーが勝利
            if (allTaken)
            {
                cout << "\nすべてのマスが取られました！" << endl;
                cout << "PLAYER WIN!" << endl;
                break;
            }

            // CPUのターンへ
            turn = 1;
        }

        // CPUのターン
        else
        {
            cout << "\n--- CPU TURN ---" << endl;

            // サイコロを2個振る
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;

            cout << "サイコロ：" << dice1 << " と " << dice2 << endl;

            // CPUが取れるマスを調べる
            int choices[3];
            int count = 0;

            if (dice1 <= 9 && board[dice1 - 1] == 0)
            {
                choices[count] = dice1;
                count++;
            }

            if (dice2 <= 9 && board[dice2 - 1] == 0)
            {
                choices[count] = dice2;
                count++;
            }

            if (dice1 + dice2 <= 9 &&
                board[dice1 + dice2 - 1] == 0)
            {
                choices[count] = dice1 + dice2;
                count++;
            }

            // CPUが取れるマスがない場合はゲーム終了
            if (count == 0)
            {
                cout << "CPUは取れるマスがありません。" << endl;
                cout << "PLAYERの勝利！" << endl;
                break;
            }

            // CPUが取れるマスからランダムに1つ選ぶ
            choice = choices[rand() % count];

            // CPUがマスを取得
            board[choice - 1] = 2;

            cout << choice << "のマスをCPUが取りました。" << endl;

            // すべてのマスが取られたか確認
            bool allTaken = true;

            for (int i = 0; i < MASU; i++)
            {
                if (board[i] == 0)
                {
                    allTaken = false;
                    break;
                }
            }

            // 最後のマスを取ったCPUが勝利
            if (allTaken)
            {
                cout << "\nすべてのマスが取られました！" << endl;
                cout << "CPU WIN!" << endl;
                break;
            }

            // プレイヤーのターンへ
            turn = 0;
        }
    }

    return 0;
}