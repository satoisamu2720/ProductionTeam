#include "Map.h"

void Map::Initialize() {

}

void Map::Draw() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 13; j++) {
			if (map[i][j] == BORDER) {//�}�b�v�u���b�N�`��
				Novice::DrawSprite(j * kBlocksize, i * kBlocksize, Blocka, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
			if (map[i][j] == NONE) {//�}�b�v�u���b�N�`��
				//Novice::DrawSprite(j * kBlocksize, i * kBlocksize, Blockb, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				Novice::DrawSprite(j * kBlocksize, i * kBlocksize, waku, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
		}
	}
}