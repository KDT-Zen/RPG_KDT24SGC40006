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



	//�@�C���X�^���X

	GameMode currentGameMode = GameMode::TITLE;


	GameMode prevMode = currentGameMode;




	//�@Enemey�^�̃��j�[�N�|�C���^�[�����
	std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();

	Player player;


	


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//���C�����[�v
		

		//�@�}�E�X�N���b�N(��)�̃V���O���g���̌Ăяo��
		MouseLeft::Instance().Update();

		//�@�}�E�X�N���b�N�i�E�j�̃V���O���g���̌Ăяo��
		MouseRight::Instance().Update();


		







		SetFontSize(80);
		
		//�@GameMode��TITLE�̎�

		//�@TITLE�̕�������ʂɕ`��
		if ( currentGameMode==GameMode::TITLE) {

			//�@�P�����ă^�C�g���ɖ߂��Ă����ۂ�HP�̉�
			Enemy::enemy_hp = 100;

			Player::player_hp = 100;


			DrawString(200,SCREEN_H/2, "�Ȉ�RPG", GetColor(255, 0, 0), TRUE);


			//�@GameMode��TITLE�̎��}�E�X���N���b�N���ꂽ��
			if (MouseLeft::Instance().IsLeftPressed()) {

				//�@GameMode��INGAME�ɂ���
				currentGameMode = GameMode::INGAME;

				if (currentGameMode != prevMode)
				{
					// ���̒��́u�؂�ւ����1�t���[�������v���s�����
					if (currentGameMode == GameMode::INGAME)
					{
						// �����Ő؂�ւ��̏u�ԂŌĂ�
						MouseLeft::Instance().ResetEdge(); // �� �N���b�N��Ԃ�������
					}

					// ���̃V�[�������̔�r�p�ɋL�^
					prevMode =currentGameMode;
				}


			

			}

		




		}
	
	
	//�@GameMode��INGAME�̎�
		if (currentGameMode == GameMode::INGAME) {
			
		



			if (MouseLeft::Instance().IsLeftPressed()) {

				//�@�v���C���[�̃_���[�W�����E�Q�Ƃœn��

				enemy->EnemyDamageUpdate(player);
			}


			SetFontSize(40);
			//�@�v���C���[��HP�̕\��
			DrawFormatString(0, 0, GetColor(255, 255, 255), "player | HP:%d ", Player::player_hp);


			//�@�G��HP�̕\��
			DrawFormatString(0, 300, GetColor(255, 255, 255), "enemy | HP:%d ", Enemy::enemy_hp);



			//�@VS�̕\��
			DrawString(100, 200, "VS", GetColor(255, 255, 255));




			SetFontSize(20);

			//�@g��ʉE���ɕ\��
			DrawString(400, 400, "���N���b�N�ōU��", GetColor(255, 255, 255));



			//�@�G��HP���O�ɂȂ�����
			if (Enemy::enemy_hp == 0 ) {

				//�@�Q�[�����[�h��PLAYER���������U���g��
				currentGameMode = GameMode::RESULT_PLAYER_WIN;

				if (currentGameMode != prevMode)
				{
					// ���̒��́u�؂�ւ����1�t���[�������v���s�����
					if (currentGameMode == GameMode::INGAME)
					{
						// �����Ő؂�ւ��̏u�ԂŌĂ�
						MouseLeft::Instance().ResetEdge(); // �� �N���b�N��Ԃ�������
					}

					// ���̃V�[�������̔�r�p�ɋL�^
					prevMode = currentGameMode;
				}

			}

			//�@�v���C���[��HP���O�ɂȂ�����
			if (Player::player_hp == 0) {

				//�@�G�l�~�[���������U���g��
				currentGameMode = GameMode::RESULT_ENEMY_WIN;

				if (currentGameMode != prevMode)
				{
					// ���̒��́u�؂�ւ����1�t���[�������v���s�����
					if (currentGameMode == GameMode::INGAME)
					{
						// �����Ő؂�ւ��̏u�ԂŌĂ�
						MouseLeft::Instance().ResetEdge(); // �� �N���b�N��Ԃ�������
					}

					// ���̃V�[�������̔�r�p�ɋL�^
					prevMode = currentGameMode;
				}

			}




		}

		//�@�v���C���[���������U���g��ʂ̎�
		if (currentGameMode == GameMode::RESULT_PLAYER_WIN) {
			SetFontSize(80);

			//�@�����̕`��
			DrawString(150, SCREEN_H / 2, "PLAYER_WIN", GetColor(255, 0, 0), TRUE);

			//�@�E�N���b�N���ꂽ��
			if (MouseRight::Instance().IsRightPressed()) {

				//�@�^�C�g����ʂɖ߂�
				currentGameMode = GameMode::TITLE;

				if (currentGameMode != prevMode)
				{
					// ���̒��́u�؂�ւ����1�t���[�������v���s�����
					if (currentGameMode == GameMode::INGAME)
					{
						// �����Ő؂�ւ��̏u�ԂŌĂ�
						MouseLeft::Instance().ResetEdge(); // �� �N���b�N��Ԃ�������
					}

					// ���̃V�[�������̔�r�p�ɋL�^
					prevMode = currentGameMode;
				}

			}
		}

		//�@�G�l�~�[���������U���g��ʂ̎�
		if (currentGameMode == GameMode::RESULT_ENEMY_WIN) {
			SetFontSize(80);

			//�@�����̕\��
			DrawString(150, SCREEN_H / 2, "ENEMY_WIN", GetColor(255, 0, 0), TRUE);

			//�@�E�N���b�N���ꂽ��
			if (MouseRight::Instance().IsRightPressed()) {

				//�@�^�C�g���ɖ߂�
				currentGameMode = GameMode::TITLE;

				if (currentGameMode != prevMode)
				{
					// ���̒��́u�؂�ւ����1�t���[�������v���s�����
					if (currentGameMode == GameMode::INGAME)
					{
						// �����Ő؂�ւ��̏u�ԂŌĂ�
						MouseLeft::Instance().ResetEdge(); // �� �N���b�N��Ԃ�������
					}

					// ���̃V�[�������̔�r�p�ɋL�^
					prevMode = currentGameMode;
				}

			}
		}
	}

	DxLib_End();

	return 0;

}