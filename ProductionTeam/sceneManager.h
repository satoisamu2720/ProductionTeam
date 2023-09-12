#pragma once
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
	void Initialize();

	void Update();

	void Draw();

	void TitleUpdate(int scene);

private:
	Player* player = new Player;
	Map* map = new Map;
	Title* title = new Title;
};

