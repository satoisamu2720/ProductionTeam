#pragma once
#include <Novice.h>

class Map
{
public:
	void Initialize();

	void Draw();

public:

	int map[12][13] = {
		{3,3,3,3,3,3,3,3,3,3,3,3,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,3,3,3,3,3,3,3,3,3,3,3,3}
	};
	enum MapInfo {
		NONE,// 0
		SETPOINT,//1�u����ꏊ
		BLOCKTILE,//2�u���b�N�^�C��
		BORDER,//3�}�b�v���E��
		DESTTINATION,//4�s���J�E���g
	};
private:
	const int kBlocksize = 64;//

	int Blocka = Novice::LoadTexture("./NoviceResources/blocka.png");//�u���b�N
	int waku = Novice::LoadTexture("./NoviceResources/waku.png");//�u���b�N


};