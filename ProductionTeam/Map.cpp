#include "Map.h"

void Map::Initialize() {

}

void Map::Draw() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == BORDER) {//マップブロック描画
				Novice::DrawSprite(j * kBlocksize, i * kBlocksize, Blocka, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
			if (map[i][j] == NONE) {//マップブロック描画
				//Novice::DrawSprite(j * kBlocksize, i * kBlocksize, Blockb, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				Novice::DrawSprite(j * kBlocksize, i * kBlocksize, waku, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
			if (map[i][j] == GOAL) {
				Novice::DrawBox(j * kBlocksize, i * kBlocksize, 64, 64, 0.0f, BLACK, kFillModeSolid);
			}
		}
	}
}