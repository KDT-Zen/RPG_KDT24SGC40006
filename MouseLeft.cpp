#include "MouseLeft.h"

/*
　前フレームの状態prevMouseに一つ前のcurrMouseを退避させる
  今フレームの状態currMouseを取得
  差分から押された瞬間を判定できるようにする

*/




//　インスタンス取得関数を作る

MouseLeft& MouseLeft::Instance()
{

	static MouseLeft instance;//　初回の呼び出しの時だけ生成

	return instance;




}






void MouseLeft::Update()
{


	//　前フレームを記録（前フレームの「現在値」を「過去の値」として保存する）
	prevLeft = currLeft;

	//　現在の状態を取得
	currLeft = GetMouseInput();

}



	

	bool MouseLeft::IsLeftPressed() const
	{
		
		//　(currMouse & MOUSE_INPUT_LEFT) != 0 今フレームで左が押されている
		//　(prevMouse & MOUSE_INPUT_LEFT) == 0 前フレームでは押されていない
		//　この両方の条件を満たした時だけ押された瞬間になる

		const bool now  =  ((currLeft & MOUSE_INPUT_LEFT) != 0);
		const bool prev =  ((prevLeft & MOUSE_INPUT_LEFT) != 0);
	



		return now && !prev;
	}


	void MouseLeft::ResetEdge() {


		int now = GetMouseInput();

		prevLeft = now;

		currLeft = now;








	}

