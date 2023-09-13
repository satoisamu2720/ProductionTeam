#include "sceneManager.h"

void sceneManager::Initialize() {
	player->Initialize();
}
void sceneManager::Update() {
	player->Updata();
}
void sceneManager::Draw() {
	player->Draw();
	m->Draw();
}

void sceneManager::TitleUpdate() {
	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		gameScene = PLAY;
	}

}

void sceneManager::GameClearUpdate() {

	if ((m->map[int(player->GetPos().y / m->GetBlockSize())][int((player->GetPos().x + m->GetBlockSize() - 1) / m->GetBlockSize())] == m->GOAL) || (m->map[int(player->GetPos().y / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL)) {
		gameScene = CLEAR;
	}

	if ((m->map[int((player->GetPos().y / m->GetBlockSize() + 1))][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL || (m->map[int((player->GetPos().y / m->GetBlockSize()) + 1)][int((player->GetPos().x + m->GetBlockSize() - 1) / m->GetBlockSize())] == m->GOAL))) {
		gameScene = CLEAR;
	}

	if ((m->map[int(player->GetPos().y / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize()) + 1] == m->GOAL || (m->map[int((player->GetPos().y + m->GetBlockSize() - 1) / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize()) + 1] == m->GOAL))) {
		gameScene = CLEAR;
	}

	if (m->map[int(player->GetPos().y / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL || m->map[int((player->GetPos().y + m->GetBlockSize() - 1) / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL) {
		gameScene = CLEAR;
	}

}

void sceneManager::ClearUpdate() {

	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		gameScene = TITLE;
	}

}