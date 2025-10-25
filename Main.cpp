#include "DxLib.h"
#include "GameManager.h"
#include "MouseLeft.h"
#include <memory>
#include "player.h"
#include "enemy.h"
#include "MouseRight.h"




int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	ChangeWindowMode(TRUE);

	if(DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	SetWindowSize(SCREEN_W, SCREEN_H);



	//　インスタンス

	GameMode currentGameMode = GameMode::TITLE;


	GameMode prevMode = currentGameMode;




	//　Enemey型のユニークポインターを作る
	std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();

	Player player;


	


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//メインループ
		

		//　マウスクリック(左)のシングルトンの呼び出し
		MouseLeft::Instance().Update();

		//　マウスクリック（右）のシングルトンの呼び出し
		MouseRight::Instance().Update();


		







		SetFontSize(80);
		
		//　GameModeがTITLEの時

		//　TITLEの文字を画面に描画
		if ( currentGameMode==GameMode::TITLE) {

			//　１周してタイトルに戻ってきた際のHPの回復
			Enemy::enemy_hp = 100;

			Player::player_hp = 100;


			DrawString(200,SCREEN_H/2, "簡易RPG", GetColor(255, 0, 0), TRUE);


			//　GameModeがTITLEの時マウスがクリックされたら
			if (MouseLeft::Instance().IsLeftPressed()) {

				//　GameModeをINGAMEにする
				currentGameMode = GameMode::INGAME;

				if (currentGameMode != prevMode)
				{
					// この中は「切り替わった1フレームだけ」実行される
					if (currentGameMode == GameMode::INGAME)
					{
						// ここで切り替えの瞬間で呼ぶ
						MouseLeft::Instance().ResetEdge(); // ← クリック状態を初期化
					}

					// 今のシーンを次の比較用に記録
					prevMode =currentGameMode;
				}


			

			}

		




		}
	
	
	//　GameModeがINGAMEの時
		if (currentGameMode == GameMode::INGAME) {
			
		



			if (MouseLeft::Instance().IsLeftPressed()) {

				//　プレイヤーのダメージ処理・参照で渡す

				enemy->EnemyDamageUpdate(player);
			}


			SetFontSize(40);
			//　プレイヤーのHPの表示
			DrawFormatString(0, 0, GetColor(255, 255, 255), "player | HP:%d ", Player::player_hp);


			//　敵のHPの表示
			DrawFormatString(0, 300, GetColor(255, 255, 255), "enemy | HP:%d ", Enemy::enemy_hp);



			//　VSの表示
			DrawString(100, 200, "VS", GetColor(255, 255, 255));




			SetFontSize(20);

			//　g画面右下に表示
			DrawString(400, 400, "左クリックで攻撃", GetColor(255, 255, 255));



			//　敵のHPが０になったら
			if (Enemy::enemy_hp == 0 ) {

				//　ゲームモードをPLAYER勝利時リザルトに
				currentGameMode = GameMode::RESULT_PLAYER_WIN;

				if (currentGameMode != prevMode)
				{
					// この中は「切り替わった1フレームだけ」実行される
					if (currentGameMode == GameMode::INGAME)
					{
						// ここで切り替えの瞬間で呼ぶ
						MouseLeft::Instance().ResetEdge(); // ← クリック状態を初期化
					}

					// 今のシーンを次の比較用に記録
					prevMode = currentGameMode;
				}

			}

			//　プレイヤーのHPが０になったら
			if (Player::player_hp == 0) {

				//　エネミー勝利時リザルトに
				currentGameMode = GameMode::RESULT_ENEMY_WIN;

				if (currentGameMode != prevMode)
				{
					// この中は「切り替わった1フレームだけ」実行される
					if (currentGameMode == GameMode::INGAME)
					{
						// ここで切り替えの瞬間で呼ぶ
						MouseLeft::Instance().ResetEdge(); // ← クリック状態を初期化
					}

					// 今のシーンを次の比較用に記録
					prevMode = currentGameMode;
				}

			}




		}

		//　プレイヤー勝利時リザルト画面の時
		if (currentGameMode == GameMode::RESULT_PLAYER_WIN) {
			SetFontSize(80);

			//　文字の描画
			DrawString(150, SCREEN_H / 2, "PLAYER_WIN", GetColor(255, 0, 0), TRUE);

			//　右クリックされたら
			if (MouseRight::Instance().IsRightPressed()) {

				//　タイトル画面に戻る
				currentGameMode = GameMode::TITLE;

				if (currentGameMode != prevMode)
				{
					// この中は「切り替わった1フレームだけ」実行される
					if (currentGameMode == GameMode::INGAME)
					{
						// ここで切り替えの瞬間で呼ぶ
						MouseLeft::Instance().ResetEdge(); // ← クリック状態を初期化
					}

					// 今のシーンを次の比較用に記録
					prevMode = currentGameMode;
				}

			}
		}

		//　エネミー勝利時リザルト画面の時
		if (currentGameMode == GameMode::RESULT_ENEMY_WIN) {
			SetFontSize(80);

			//　文字の表示
			DrawString(150, SCREEN_H / 2, "ENEMY_WIN", GetColor(255, 0, 0), TRUE);

			//　右クリックされたら
			if (MouseRight::Instance().IsRightPressed()) {

				//　タイトルに戻る
				currentGameMode = GameMode::TITLE;

				if (currentGameMode != prevMode)
				{
					// この中は「切り替わった1フレームだけ」実行される
					if (currentGameMode == GameMode::INGAME)
					{
						// ここで切り替えの瞬間で呼ぶ
						MouseLeft::Instance().ResetEdge(); // ← クリック状態を初期化
					}

					// 今のシーンを次の比較用に記録
					prevMode = currentGameMode;
				}

			}
		}
	}

	DxLib_End();

	return 0;

}