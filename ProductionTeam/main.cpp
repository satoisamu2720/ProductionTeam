#include <Novice.h>
#include "sceneManager.h"

const char kWindowTitle[] = "2026_サルノ橋";

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
		sceneM->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sceneM->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
