#pragma once
#include <Novice.h>
#include"Player.h"

class Map
{
public:
	void Initialize();
	
	void Draw();

	void HitJudgment();

	
public:
	int map[12][20] = {
		{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,4,3},
        {3,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3},
        {3,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,3,3,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,3},
        {3,3,3,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,3}
	};

	struct MAP
	{
		int rightTopX;
		int rightTopY;
		int leftTopX;
		int leftTopY;
		int rightBottomX;
		int rightBottomY;
		int leftBottomX;
		int leftBottomY;
	};
	MAP MapHit;

	enum MapInfo {
		NONE,// 0
		SETPOINT,//1置ける場所
		BLOCKTILE,//2ブロックタイル
		BORDER,//3マップ境界線
		GOAL//4

	};
private:

	Player* pos = new Player;

	const int kBlocksize = 64;//

	int Blocka = Novice::LoadTexture("./NoviceResources/blocka.png");//ブロック
	int waku = Novice::LoadTexture("./NoviceResources/waku.png");//ブロック

};