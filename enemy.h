#pragma once






//　ダメージ処理で出てくるPlayerの前方宣言
class Player;


class Enemy {



public:

	//　EnemyのHP
	static int enemy_hp;



	

	int GetAttackEnemyPower();

	void EnemyDamageUpdate(Player& player);


};