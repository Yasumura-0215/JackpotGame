#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(void)
{
	// ゲームで使用する数字の数
	const int CARD = 3;

	// 0～9の10種類の数字を使用する
	const int CARD_NUMBER = 10;

	// 繰り返し処理などに使用する変数
	int i, hit = 0;

	// プレイヤーが最初に持つ3つの数字
	int playerCard[CARD];

	// CPUが最初に持つ3つの数字
	int enemyCard[CARD];

	// プレイヤーが予想する数字
	int plyChoice[CARD];

	// CPUが予想する数字
	int emyChoice[CARD];

	// プレイヤーとCPUのターンを切り替えるためのフラグ
	bool trunFlag = true;

	// プレイヤーが勝利したかを判断するためのフラグ
	bool judgementFlag = false;

	// 現在の時刻を利用して乱数のパターンを毎回変える
	srand((unsigned int)time(NULL));

	// プレイヤーとCPUに0～9の数字を3つずつランダムに配る
	for (i = 0; i < CARD; i++)
	{
		playerCard[i] = rand() % CARD_NUMBER;
		enemyCard[i] = rand() % CARD_NUMBER;
	}

	// ゲームのタイトルとルールを表示する
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";

	// プレイヤーに配られた数字を表示する
	cout << "あなたの配られてカードは," << "\n";

	for (i = 0; i < CARD; i++)
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";
	}

	cout << "===================   GAME STRAT   ============================" << "\n";

	// どちらかが3つすべて正解するまでゲームを繰り返す
	while (true)
	{
		// プレイヤーのターンの場合
		if (trunFlag)
		{
			// 前回の判定結果をリセットする
			hit = 0;

			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";

			// プレイヤーが予想する3つの数字を入力する
			for (i = 0; i < CARD; i++)
			{
				while (true)
				{
					cin >> plyChoice[i];

					// 0～9以外の数字が入力された場合は再入力する
					if (0 > plyChoice[i] || 9 < plyChoice[i])
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else
					{
						// 正しい数字が入力されたらループを終了する
						break;
					}
				}
			}

			// プレイヤーの予想とCPUの数字を1つずつ比較する
			for (i = 0; i < CARD; i++)
			{
				// 同じ位置の数字が一致している場合はHit
				if (plyChoice[i] == enemyCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				// 数字が一致していない場合はBlowとして表示する
				else
				{
					cout << "Blow,";
				}
			}

			cout << "\n";

			// 3つすべての数字が一致したらプレイヤーの勝利
			if (hit == 3)
			{
				cout << "3Hit!!\n";

				// プレイヤーが勝利したことを記録する
				judgementFlag = true;

				// ゲームを終了する
				break;
			}

			cout << "\n";

			// 次はCPUのターンに変更する
			trunFlag = false;
		}
		else
		{
			// 前回の判定結果をリセットする
			hit = 0;

			cout << "ENEMY TRUN \n";

			// CPUが0～9から3つの数字をランダムに選ぶ
			for (i = 0; i < CARD; i++)
			{
				emyChoice[i] = rand() % CARD_NUMBER;

				// CPUが選んだ数字を表示する
				cout << i + 1 << "番目" << emyChoice[i] << "\n";
			}

			// CPUの予想とプレイヤーの数字を1つずつ比較する
			for (i = 0; i < CARD; i++)
			{
				// 同じ位置の数字が一致している場合はHit
				if (emyChoice[i] == playerCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				// 数字が一致していない場合はBlowとして表示する
				else
				{
					cout << "Blow,";
				}
			}

			cout << "\n";

			// CPUが3つすべて正解したらCPUの勝利
			if (hit == 3)
			{
				cout << "3Hit!!\n";

				// ゲームを終了する
				break;
			}

			cout << "\n";

			// 次はプレイヤーのターンに変更する
			trunFlag = true;
		}
	}

	// 勝利した側を判定して結果を表示する
	if (judgementFlag)
	{
		cout << "PLAYER WINNER\n";
	}
	else
	{
		cout << "ENEMY WINNER\n";
	}

	// プログラムを終了する
	return 0;
}