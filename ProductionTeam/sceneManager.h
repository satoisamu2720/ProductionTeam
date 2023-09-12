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
	//�Q�[���V�[���p
	void Initialize();

	void Update();

	void Draw();

	//��������^�C�g���錾
	void TitleUpdate();

	//�V�[���؂�ւ��p
	GAMESCENE GetScene() { return gameScene; }

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Player* player = new Player;
	
	Map* map = new Map;

	Title* title = new Title;

	GAMESCENE gameScene = TITLE;
};

