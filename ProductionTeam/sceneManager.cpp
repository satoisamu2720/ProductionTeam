#include "sceneManager.h"

/******************
　プレイ画面用の処理
*******************/

void sceneManager::Initialize() {
	player->Initialize();
}
void sceneManager::Update() {
	player->Updata();
}
void sceneManager::Draw() {
	player->Draw();
	map->Draw();
}

/*****************
　ここからタイトル用
******************/

void sceneManager::TitleUpdate() {
	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		gameScene = PLAY;
	}

}

/********************
　ここからゲームクリア用
*********************/



/*********************
　ここからゲームオーバー用
**********************/
