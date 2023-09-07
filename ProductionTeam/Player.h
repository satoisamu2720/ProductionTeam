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

private:
	void Move();

	void SetPlayer();
	void FixPlayer();
	void RollBack();

	void CheckSafety();

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Map* m = new Map;

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//ボール = 1

	Vector2 pos{1,9};

	int kCount = 0;

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

	enum BallState {
		STABLE,//安定
		UNSTABLE,//不安定
		DANGER,//危険
	};

	enum BallKind {
		a,//yowai
		b,//normal
		c,//tuyoi
	};

	struct Ball {
		Vector2 position{};
		BallState ballState = STABLE;//状態
		BallKind ballKind = a;//種類
		int costs = 1;
		UINT32 color = WHITE;
		bool isActive = false;
	};
	Ball ball[100] = {};

	movePattern mp = NORMAL;
};