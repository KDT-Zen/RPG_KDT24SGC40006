#include "MouseRight.h"

/*
�@�O�t���[���̏��prevMouse�Ɉ�O��currMouse��ޔ�������
  ���t���[���̏��currMouse���擾
  �������牟���ꂽ�u�Ԃ𔻒�ł���悤�ɂ���

*/




//�@�C���X�^���X�擾�֐������

MouseRight& MouseRight::Instance()
{

	static MouseRight instance;//�@����̌Ăяo���̎���������

	return instance;

}






void MouseRight::Update()
{


	//�@�O�t���[�����L�^�i�O�t���[���́u���ݒl�v���u�ߋ��̒l�v�Ƃ��ĕۑ�����j
	prevRight = currRight;

	//�@���݂̏�Ԃ��擾
	currRight = GetMouseInput();

}





bool MouseRight::IsRightPressed() const
{

	
	const bool now =  ((currRight & MOUSE_INPUT_RIGHT) != 0);
	const bool prev = ((prevRight % MOUSE_INPUT_RIGHT) != 0);




	return now && !prev;
}
