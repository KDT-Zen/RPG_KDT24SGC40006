#pragma once

#include "DxLib.h"

#define SCREEN_W 800

#define SCREEN_H 400


//enum class GameMode {
//
//	TITLE,
//	INGAME,
//	RESULT
//
//};

enum GameMode {
	TITLE,
	INGAME,
	RESULT
};

class GameManager {

	int gamemode;

	void Init();

	void Update();

	void Render();

	void Exit();
};









