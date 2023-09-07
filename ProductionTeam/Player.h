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

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//�{�[�� = 1

	Vector2 pos{1,9};

	int kCount = 0;

	int moveCount = 0;
	int moveMax = 2;

	bool isSet = false;
	//�u���b�N�T�C�Y�̐ݒ�
	const int kBlocksize = 64;

	int SelectTimer = 0;//�Z�b�g���������p�^�C�}�[

	enum movePattern {
		NORMAL,
		SETMODE,
	};

	enum BallState {
		STABLE,//����
		UNSTABLE,//�s����
		DANGER,//�댯
	};

	enum BallKind {
		a,//yowai
		b,//normal
		c,//tuyoi
	};

	struct Ball {
		Vector2 position{};
		BallState ballState = STABLE;//���
		BallKind ballKind = a;//���
		int costs = 1;
		UINT32 color = WHITE;
		bool isActive = false;
	};
	Ball ball[100] = {};

	movePattern mp = NORMAL;
};