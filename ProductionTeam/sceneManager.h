#pragma once
#include "Player.h"
#include "Map.h"
#include <Novice.h>

enum GAMESCENE {
	TITLE,
	PLAY,
	CLEAR
};

class sceneManager
{
public:
	void Initialize();

	void Update();

	void Draw();

	void TitleUpdate();

	void GameClearUpdate();

	void ClearUpdate();

	GAMESCENE GetScene() { return gameScene; }

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Player* player = new Player;
	Map* m = new Map;

	GAMESCENE gameScene = TITLE;

};

