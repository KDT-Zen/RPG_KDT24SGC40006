#include "enemy.h"

#include <cstdlib>

#include <ctime>

#include "DxLib.h"

#include "MouseRight.h"

#include "Player.h"

#include "MouseLeft.h"

int Enemy::enemy_hp = 100;

int Player::player_hp = 100;

//　プレイヤーからNPCへのダメージ処理
void Enemy::EnemyDamageUpdate(Player& player) {

	
	//　マウスがクリックされたとき
	if (MouseLeft::Instance().IsLeftPressed()) {

		//　プレイヤーの与えるダメージ関数
		int damage = player.GetAttackPlayerPower();


	


		srand((unsigned int)time(nullptr));

		Player::player_hp -= damage;

		int enemy_damage_adjustment = rand() % 4 + 1;


		int total_enemy_damage = damage + enemy_damage_adjustment;

		Player::player_hp -= total_enemy_damage;

		int player_damage_adjustment = rand() % 4 + 1;

		int total_player_damage = damage + player_damage_adjustment;

		//　エネミーのHPからプレイヤーのダメージを引く
		enemy_hp -= damage + player_damage_adjustment;

		//　HPが０を下回らないようにする
		if (enemy_hp < 0) enemy_hp = 0;

		if (Player::player_hp < 0) Player::player_hp = 0;

	}


}


int Enemy::GetAttackEnemyPower() {


	//　乱数の初期化をする
	srand((unsigned int)time(nullptr));

	//　1～10のランダムな値を返す

	int enemy_power = rand() % 10 + 1;


	return enemy_power;

}



