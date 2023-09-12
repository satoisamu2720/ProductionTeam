#pragma once
#include <Novice.h>
#include "Vec2.h"
#include "Map.h"
#include <ImGuiManager.h>

class Player
{
public:
	void Initialize();

	void Updata();

	void Draw();

private:
	void Move();
	void MoveLimit();

	void SetPlayer();
	void FixPlayer();
	void RollBack();

	void CheckSafety();

	void ballUpdata();

private:
	char keys[356] = {};
	char preKeys[356] = {};

	Map* m = new Map;

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//ボール = 1

	Vector2 pos{1*64,9*64};
	Vector2 delta{};
	float lengthLimit = 100;

	int leftx = 0;
	int lefty = 0;
	int rightx = 0;
	int righty = 0;

	float length;

	float speed = 3;

	int kCount = 0;

	int moveCount = 0;
	int moveMax = 100;

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
		BallState ballState = STABLE;//状態
		BallKind ballKind = a;//種類
		int costs = 1;
		UINT32 color = WHITE;
		bool isActive = false;
		Vector2 center{};
		int radius = 16;
	};
	Ball ball[100] = {};

	movePattern mp = NORMAL;
};