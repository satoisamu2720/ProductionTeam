#pragma once
#include <Novice.h>
#include "Vector2.h"

class Player
{
public:
	void Initialize();

	void Updata(char keys[],char preKeys[]);

	void Draw();

	void Move(char keys[], char preKeys[]);

	void SetPlayer(char keys[], char preKeys[]);

	Vector2 GetPosition();
private:
	//char keys[356] = {};
	//char preKeys[356] = {};

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//ボール = 1

	Vector2 pos{};
	bool isSet = false;
	//ブロックサイズの設定
	const int kBlocksize = 64;
	int RedBallX = 1; //赤ボールのX座標
	int RedBallY = 10; //赤ボールのY座標
	int SelectTimer = 1;//セット時長押し用タイマー
	//int BallSetTimer = 30;//赤ボールをセットした時に動かす(連打防止);

	int BallPointer[12][13] = { //ボール設置可能地点
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	//ボールの位置
	int BallPoint[12][13] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	enum MapPinterInfo {
		NONEPOINTER,//0
		SETPOINTER,//1設置可能地点
	};

	enum BallInfo {
		NONEBALL,//0
		REDBALL,//1赤ボール
	};
};

