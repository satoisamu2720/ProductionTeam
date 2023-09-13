#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Map.h"

class Player
{
public:
	void Initialize();

	void Updata();

	void Draw();

	Vector2 GetPos() { return pos; }



private:
	void Move();
	void MoveLimit();

	void SetPlayer();
	void FixPlayer();
	void RollBack();

	void CheckSafety();
	void FallBlock();
	void ballUpdata();

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Map* m = new Map;

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//ボール = 1

	Vector2 pos{1.0f* kBlocksize,9.0f*kBlocksize};
	Vector2 delta{};

	int leftx = 0;
	int lefty = 0;
	int rightx = 0;
	int righty = 0;

	float length;

	float speed = 2;

	int kCount = 0;

	int goalConditions = true;

	int moveCount = 0;
	int moveMax = 100;

	int randx = 0;
	int randy = 0;

	bool isSet = false;
	//ブロックサイズの設定
	const int kBlocksize = 64;


	enum movePattern {
		NORMAL,
		SETMODE,
	};

	enum BallState {
		STABLE,//安定
		UNSTABLE,//不安定
		DANGER,//危険
		NEUTRAL
	};

	enum BallKind {
		a,//yowai
		b,//normal
		c,//tuyoi
	};

	struct Ball {
		Vector2 position{};
		BallState ballState = NEUTRAL;//状態
		BallKind ballKind = a;//種類
		int costs = 1;
		UINT32 color = WHITE;
		bool isActive = false;
		Vector2 center{};
		int radius = 16;
		int fallTimer = 300;
		int fallTimerMax = 240;
	};
	Ball ball[100] = {};
	Ball ballred[100] = {};
	movePattern mp = NORMAL;
};