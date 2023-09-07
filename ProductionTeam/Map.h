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
		SETPOINT,//1置ける場所
		BLOCKTILE,//2ブロックタイル
		BORDER,//3マップ境界線
		DESTTINATION,//4行動カウント
	};
private:
	const int kBlocksize = 64;//

	int Blocka = Novice::LoadTexture("./NoviceResources/blocka.png");//ブロック
	int waku = Novice::LoadTexture("./NoviceResources/waku.png");//ブロック


};