#pragma once
#include "Player.h"
#include "Map.h"

class sceneManager
{
public:
	void Initialize();

	void Update();

	void Draw();

private:
	Player* player = new Player;
	Map* map = new Map;
};

