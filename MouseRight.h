#pragma once

#include <DxLib.h>





/*
Mouse クラス：

「左クリックが押された瞬間」を判定するためのクラス
　毎フレームUpdate()を一回だけよんで状態を更新する
  IsLeftPressed()で”このフレームに押された瞬間”を取得する
  座標関係なし



*/
class MouseRight {

public:

	static MouseRight& Instance();


	//　毎フレーム最初に呼び出して、マウスの状態を更新する
	void Update();




	//　左クリックが押された瞬間を取る
	bool IsRightPressed() const;



	
private:

	//　コンストラクタをprivateにして外部で作れないようにする

//　コンストラクタをprivateにして外部で作れないようにする
	MouseRight() = default;

	~MouseRight() = default;

	



	//コピーと代入も禁止にする
	MouseRight(const MouseRight&) = delete;

	MouseRight& operator= (const MouseRight&) = delete;




	//　１フレーム前のボタンの状態を保持する変数
	int prevRight;


	//　今フレームのボタン状態を保持する変数
	int currRight;




};