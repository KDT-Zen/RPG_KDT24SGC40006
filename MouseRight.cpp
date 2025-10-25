#include "MouseRight.h"

/*
　前フレームの状態prevMouseに一つ前のcurrMouseを退避させる
  今フレームの状態currMouseを取得
  差分から押された瞬間を判定できるようにする

*/




//　インスタンス取得関数を作る

MouseRight& MouseRight::Instance()
{

	static MouseRight instance;//　初回の呼び出しの時だけ生成

	return instance;

}






void MouseRight::Update()
{


	//　前フレームを記録（前フレームの「現在値」を「過去の値」として保存する）
	prevRight = currRight;

	//　現在の状態を取得
	currRight = GetMouseInput();

}





bool MouseRight::IsRightPressed() const
{

	
	const bool now =  ((currRight & MOUSE_INPUT_RIGHT) != 0);
	const bool prev = ((prevRight % MOUSE_INPUT_RIGHT) != 0);




	return now && !prev;
}
