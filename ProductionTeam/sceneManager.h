#pragma once
#include "Player.h"
#include "Map.h"
#include "Title.h"
#include "Clear.h"
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

	/// <summary>
	/// ここからタイトル
	/// </summary>

	void TitleUpdate();

	void TitleDraw();

	/// <summary>
	/// ここからゲームクリア
	/// </summary>

	void GameClearUpdate();

	/// <summary>
	/// ここからクリア画面
	/// </summary>

	void ClearDraw();

	void ClearUpdate();

	GAMESCENE GetScene() { return gameScene; }

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Player* player = new Player;
	Map* m = new Map;
	Title* title = new Title;
	Clear* clear = new Clear;

	GAMESCENE gameScene = TITLE;

};

