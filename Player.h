#pragma once


//　ダメージ処理で出てくるプレイヤーの前方宣言
class Enemey;

class Player {


public:


	//　今回はプレイヤーは一人だからstaticで作る
	static int player_hp;



	//　攻撃力をランダムに決める関数の宣言
	int GetAttackPlayerPower();


	void PlayerDamageUpdate(Player& player);



};


