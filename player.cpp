#include "player.h"

#include <cstdlib>

#include <ctime>

#include "enemy.h"

#include "MouseLeft.h"

#include "DxLib.h"


//�@player.h�Ő錾����static HP�ϐ������̉�
//int Player::player_hp = 50;






int Player::GetAttackPlayerPower() {


	//�@�����̏�����������
	srand((unsigned int)time(nullptr));

	//�@1�`10�̃����_���Ȓl��Ԃ�

	int player_power = rand() % 10 + 1;


	return player_power;

}