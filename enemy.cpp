#include "enemy.h"

#include <cstdlib>

#include <ctime>

#include "DxLib.h"

#include "MouseRight.h"

#include "Player.h"

#include "MouseLeft.h"

int Enemy::enemy_hp = 100;

int Player::player_hp = 100;

//�@�v���C���[����NPC�ւ̃_���[�W����
void Enemy::EnemyDamageUpdate(Player& player) {

	
	//�@�}�E�X���N���b�N���ꂽ�Ƃ�
	if (MouseLeft::Instance().IsLeftPressed()) {

		//�@�v���C���[�̗^����_���[�W�֐�
		int damage = player.GetAttackPlayerPower();


	


		srand((unsigned int)time(nullptr));

		Player::player_hp -= damage;

		int enemy_damage_adjustment = rand() % 4 + 1;


		int total_enemy_damage = damage + enemy_damage_adjustment;

		Player::player_hp -= total_enemy_damage;

		int player_damage_adjustment = rand() % 4 + 1;

		int total_player_damage = damage + player_damage_adjustment;

		//�@�G�l�~�[��HP����v���C���[�̃_���[�W������
		enemy_hp -= damage + player_damage_adjustment;

		//�@HP���O�������Ȃ��悤�ɂ���
		if (enemy_hp < 0) enemy_hp = 0;

		if (Player::player_hp < 0) Player::player_hp = 0;

	}


}


int Enemy::GetAttackEnemyPower() {


	//�@�����̏�����������
	srand((unsigned int)time(nullptr));

	//�@1�`10�̃����_���Ȓl��Ԃ�

	int enemy_power = rand() % 10 + 1;


	return enemy_power;

}



