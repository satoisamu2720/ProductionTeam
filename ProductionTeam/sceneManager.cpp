#include "sceneManager.h"

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

void sceneManager::TitleUpdate(int scene) {
	title->Updata(scene);
}