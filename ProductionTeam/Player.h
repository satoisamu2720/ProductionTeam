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

	void ResetPlayer();

	void Select();


private:
	char keys[356] = {};
	char preKeys[356] = {};

	Map* m = new Map;
	Map* waku = new Map;
	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//�{�[�� = 1

	Vector2 pos{1,10};
	Vector2 kPos{};
	Vector2 sPos{};

	int moveCount = 0;
	int moveMax = 2;

	bool isSet = false;
	bool isSelectSet = false;
	//�u���b�N�T�C�Y�̐ݒ�
	const int kBlocksize = 64;

	int SelectTimer = 0;//�Z�b�g���������p�^�C�}�[

	enum movePattern {
		NORMAL,
		SETMODE,
		SELRCT,
	};
	movePattern mp = NORMAL;
};

