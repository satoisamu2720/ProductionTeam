#include <Novice.h>
#include "sceneManager.h"

const char kWindowTitle[] = "サルノ橋";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1380, 768);

	//
	sceneManager* sceneM = new sceneManager;

	// キー入力結果を受け取る箱
	char keys[356] = {0};
	char preKeys[356] = {0};

	sceneM->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		//memcpy(preKeys, keys, 356);
		//Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (sceneM->GetScene())
		{
		case TITLE:

			sceneM->Initialize();
			sceneM->TitleUpdate();

			break;

		case EXPLANATION:
			
			sceneM->ExplanationUpdate();

			break;

		case PLAY:

			sceneM->Update();
			sceneM->GameClearUpdate();

			break;

		case CLEAR:

			sceneM->ClearUpdate();

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		switch (sceneM->GetScene())
		{
		case TITLE:

			sceneM->TitleDraw();

			break;

		case EXPLANATION:

			sceneM->ExplanationDraw();

			break;

		case PLAY:

			sceneM->Draw();

			break;

		case CLEAR:

			sceneM->ClearDraw();

			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (sceneM->GetGameEnd() == true) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
