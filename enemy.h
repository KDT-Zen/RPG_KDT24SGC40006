#pragma once






//�@�_���[�W�����ŏo�Ă���Player�̑O���錾
class Player;


class Enemy {



public:

	//�@Enemy��HP
	static int enemy_hp;



	

	int GetAttackEnemyPower();

	void EnemyDamageUpdate(Player& player);


};