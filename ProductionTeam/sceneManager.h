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

	/// <summary>
	/// ここから説明画面用
	/// </summary>

	void ExplanationUpdate();

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

public:

	GAMESCENE GetScene() { return gameScene; }

	bool GetGameEnd() { return gameEnd; }

private:
	char keys[356] = {};
	char preKeys[356] = {};

	//ゲームパッドのスティック用
	int leftX = 0;
	int leftY = 0;

	//エスケープをオスとゲーム終了できるようにするためのフラグ
	bool gameEnd = false;

	//スティック選択時に過度に動きすぎないようにする
	int count1 = 0;

	/// <summary>
	/// ここから音楽と画像
	/// </summary>

	int arrowImage = Novice::LoadTexture("./NoviceResources/arrow.png");
	int EXImage = Novice::LoadTexture("./NoviceResources/EXban.png");
	int EXstateImage = Novice::LoadTexture("./NoviceResources/exState.png");
	int gameStartImage = Novice::LoadTexture("./NoviceResources/gameStart.png");
	int titleSelect = Novice::LoadTexture("./NoviceResources/titleSelect.png");

	int titleMusic = Novice::LoadAudio("./NoviceResources/Jungle_Walk.mp3");
	int titleVoice = -1;
	int gameMusic = Novice::LoadAudio("./NoviceResources/Attack.mp3");
	int gameVoice = -1;
	int clearMusic = Novice::LoadAudio("./NoviceResources/fanfare.wav");
	int clearVoice = -1;

	/// <summary>
	/// ここまで
	/// </summary>

	Player* player = new Player;
	Map* m = new Map;
	Title* title = new Title;
	Clear* clear = new Clear;

	GAMESCENE gameScene = TITLE;

	TITLESTATE titleState = GAMESTATE;

};

