#pragma once

#include <DxLib.h>





/*
Mouse �N���X�F

�u���N���b�N�������ꂽ�u�ԁv�𔻒肷�邽�߂̃N���X
�@���t���[��Update()����񂾂����ŏ�Ԃ��X�V����
  IsLeftPressed()�Łh���̃t���[���ɉ����ꂽ�u�ԁh���擾����
  ���W�֌W�Ȃ�



*/
class MouseRight {

public:

	static MouseRight& Instance();


	//�@���t���[���ŏ��ɌĂяo���āA�}�E�X�̏�Ԃ��X�V����
	void Update();




	//�@���N���b�N�������ꂽ�u�Ԃ����
	bool IsRightPressed() const;



	
private:

	//�@�R���X�g���N�^��private�ɂ��ĊO���ō��Ȃ��悤�ɂ���

//�@�R���X�g���N�^��private�ɂ��ĊO���ō��Ȃ��悤�ɂ���
	MouseRight() = default;

	~MouseRight() = default;

	



	//�R�s�[�Ƒ�����֎~�ɂ���
	MouseRight(const MouseRight&) = delete;

	MouseRight& operator= (const MouseRight&) = delete;




	//�@�P�t���[���O�̃{�^���̏�Ԃ�ێ�����ϐ�
	int prevRight;


	//�@���t���[���̃{�^����Ԃ�ێ�����ϐ�
	int currRight;




};