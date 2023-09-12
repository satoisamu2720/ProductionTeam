#pragma once
#include <Novice.h>
#include "Player.h"
#include "Map.h"
#include "Title.h"

enum GAMESCENE {
	TITLE,
	PLAY,
	CLEAR,
	OVER
};

class sceneManager
{
public:
	//ゲームシーン用
	void Initialize();

	void Update();

	void Draw();

	//ここからタイトル宣言
	void TitleUpdate();

	//シーン切り替え用
	GAMESCENE GetScene() { return gameScene; }

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Player* player = new Player;
	
	Map* map = new Map;

	Title* title = new Title;

	GAMESCENE gameScene = TITLE;
};

