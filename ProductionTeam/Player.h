#pragma once
#include <Novice.h>
#include "Vector2.h"
#include "Map.h"

class Player
{
public:
	void Initialize();

	void Updata();

	void Draw();

	void Move();

	void SetPlayer();
	void FixPlayer();

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Map* m = new Map;

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//ボール = 1

	Vector2 pos{1,10};
	Vector2 kPos{};

	int moveCount = 0;
	int moveMax = 2;

	bool isSet = false;
	//ブロックサイズの設定
	const int kBlocksize = 64;

	int SelectTimer = 0;//セット時長押し用タイマー

	enum movePattern {
		NORMAL,
		SETMODE,
	};
	movePattern mp = NORMAL;
};

