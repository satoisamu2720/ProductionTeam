#pragma once
#include <Novice.h>
#include "Vector2.h"

class Player
{
public:
	void Initialize();

	void Updata();

	void Draw();

	void Move();

	void SetPlayer();

	Vector2 GetPosition();
private:
	char keys[356] = {};
	char preKeys[356] = {};

	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//�{�[�� = 1

	Vector2 pos{};
	bool isSet = false;
	//�u���b�N�T�C�Y�̐ݒ�
	const int kBlocksize = 64;
	int RedBallX = 1; //�ԃ{�[����X���W
	int RedBallY = 10; //�ԃ{�[����Y���W
	int SelectTimer = 1;//�Z�b�g���������p�^�C�}�[
	//int BallSetTimer = 30;//�ԃ{�[�����Z�b�g�������ɓ�����(�A�Ŗh�~);

	int BallPointer[12][13] = { //�{�[���ݒu�\�n�_
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

	//�{�[���̈ʒu
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
		SETPOINTER,//1�ݒu�\�n�_
	};

	enum BallInfo {
		NONEBALL,//0
		REDBALL,//1�ԃ{�[��
	};
};

