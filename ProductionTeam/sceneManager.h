#pragma once
#include "Player.h"
#include "Map.h"
#include "Title.h"
#include "Clear.h"
#include <Novice.h>

enum GAMESCENE {
	TITLE,
	EXPLANATION,
	PLAY,
	CLEAR
};

enum TITLESTATE {
	GAMESTATE,
	EXSCENE,
	END,
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

	void ExplanationDraw();
	
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

	int leftX = 0;
	int leftY = 0;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	int arrowImage = Novice::LoadTexture("./NoviceResources/arrow.png");
	int EXImage = Novice::LoadTexture("./NoviceResources/EXban.png");

	Player* player = new Player;
	Map* m = new Map;
	Title* title = new Title;
	Clear* clear = new Clear;

	GAMESCENE gameScene = TITLE;

	TITLESTATE titleState = GAMESTATE;

};

