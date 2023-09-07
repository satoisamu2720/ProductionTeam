#pragma once
#include <Novice.h>

class Map
{
public:
	void Initialize();

	void Draw();

private:
	const int kBlocksize = 64;//

	int Blocka = Novice::LoadTexture("./NoviceResources/blocka.png");//�u���b�N

	enum MapInfo {
		NONE,// 0
		SETPOINT,//1�u����ꏊ
		BLOCKTILE,//2�u���b�N�^�C��
		BORDER,//3�}�b�v���E��
	};

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
};

