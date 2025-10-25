#include "player.h"

#include <cstdlib>

#include <ctime>

#include "enemy.h"

#include "MouseLeft.h"

#include "DxLib.h"


//　player.hで宣言したstatic HP変数を実体化
//int Player::player_hp = 50;






int Player::GetAttackPlayerPower() {


	//　乱数の初期化をする
	srand((unsigned int)time(nullptr));

	//　1～10のランダムな値を返す

	int player_power = rand() % 10 + 1;


	return player_power;

}