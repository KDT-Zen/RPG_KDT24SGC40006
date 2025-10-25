#pragma once
#include <DxLib.h>





/*
Mouse クラス：

「左クリックが押された瞬間」を判定するためのクラス
　毎フレームUpdate()を一回だけよんで状態を更新する
  IsLeftPressed()で”このフレームに押された瞬間”を取得する
  座標関係なし



*/
class MouseLeft {

public:

	static MouseLeft& Instance();


	//　毎フレーム最初に呼び出して、マウスの状態を更新する
	void Update();




	//　左クリックが押された瞬間を取る
	bool IsLeftPressed() const;

	//　シーンを切り替えるクリックが次のシーンのクリックの判定も持ってしまうのを防ぐ
	void ResetEdge();


private:

	//　コンストラクタをprivateにして外部で作れないようにする
	 MouseLeft() = default;

	~MouseLeft() = default;



	//コピーと代入も禁止にする
	MouseLeft(const MouseLeft&) = delete;

	MouseLeft& operator= (const MouseLeft&) = delete;




	//　１フレーム前のボタンの状態を保持する変数
	int prevLeft;


	//　今フレームのボタン状態を保持する変数
	int currLeft;




};