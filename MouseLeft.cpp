#include "MouseLeft.h"

/*
�@�O�t���[���̏��prevMouse�Ɉ�O��currMouse��ޔ�������
  ���t���[���̏��currMouse���擾
  �������牟���ꂽ�u�Ԃ𔻒�ł���悤�ɂ���

*/




//�@�C���X�^���X�擾�֐������

MouseLeft& MouseLeft::Instance()
{

	static MouseLeft instance;//�@����̌Ăяo���̎���������

	return instance;




}






void MouseLeft::Update()
{


	//�@�O�t���[�����L�^�i�O�t���[���́u���ݒl�v���u�ߋ��̒l�v�Ƃ��ĕۑ�����j
	prevLeft = currLeft;

	//�@���݂̏�Ԃ��擾
	currLeft = GetMouseInput();

}



	

	bool MouseLeft::IsLeftPressed() const
	{
		
		//�@(currMouse & MOUSE_INPUT_LEFT) != 0 ���t���[���ō���������Ă���
		//�@(prevMouse & MOUSE_INPUT_LEFT) == 0 �O�t���[���ł͉�����Ă��Ȃ�
		//�@���̗����̏����𖞂����������������ꂽ�u�ԂɂȂ�

		const bool now  =  ((currLeft & MOUSE_INPUT_LEFT) != 0);
		const bool prev =  ((prevLeft & MOUSE_INPUT_LEFT) != 0);
	



		return now && !prev;
	}


	void MouseLeft::ResetEdge() {


		int now = GetMouseInput();

		prevLeft = now;

		currLeft = now;








	}

