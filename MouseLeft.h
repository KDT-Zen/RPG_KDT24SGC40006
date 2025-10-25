#pragma once
#include <DxLib.h>





/*
Mouse �N���X�F

�u���N���b�N�������ꂽ�u�ԁv�𔻒肷�邽�߂̃N���X
�@���t���[��Update()����񂾂����ŏ�Ԃ��X�V����
  IsLeftPressed()�Łh���̃t���[���ɉ����ꂽ�u�ԁh���擾����
  ���W�֌W�Ȃ�



*/
class MouseLeft {

public:

	static MouseLeft& Instance();


	//�@���t���[���ŏ��ɌĂяo���āA�}�E�X�̏�Ԃ��X�V����
	void Update();




	//�@���N���b�N�������ꂽ�u�Ԃ����
	bool IsLeftPressed() const;

	//�@�V�[����؂�ւ���N���b�N�����̃V�[���̃N���b�N�̔���������Ă��܂��̂�h��
	void ResetEdge();


private:

	//�@�R���X�g���N�^��private�ɂ��ĊO���ō��Ȃ��悤�ɂ���
	 MouseLeft() = default;

	~MouseLeft() = default;



	//�R�s�[�Ƒ�����֎~�ɂ���
	MouseLeft(const MouseLeft&) = delete;

	MouseLeft& operator= (const MouseLeft&) = delete;




	//�@�P�t���[���O�̃{�^���̏�Ԃ�ێ�����ϐ�
	int prevLeft;


	//�@���t���[���̃{�^����Ԃ�ێ�����ϐ�
	int currLeft;




};