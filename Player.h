#pragma once


//�@�_���[�W�����ŏo�Ă���v���C���[�̑O���錾
class Enemey;

class Player {


public:


	//�@����̓v���C���[�͈�l������static�ō��
	static int player_hp;



	//�@�U���͂������_���Ɍ��߂�֐��̐錾
	int GetAttackPlayerPower();


	void PlayerDamageUpdate(Player& player);



};


