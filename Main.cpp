#include "DxLib.h"
#include "GameManager.h"





int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	ChangeWindowMode(TRUE);

	if(DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	SetWindowSize(SCREEN_W, SCREEN_H);

	GameMode currentGameMode = GameMode::TITLE;


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//ÉÅÉCÉìÉãÅ[Év
		



		SetFontSize(80);
		
		if ( currentGameMode==GameMode::TITLE) {
			DrawString(200,SCREEN_H/2, "title", GetColor(255, 0, 0), TRUE);
		}
	
			
		



	}

	DxLib_End();

	return 0;

}