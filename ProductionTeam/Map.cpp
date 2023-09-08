#include "Map.h"


void Map::Initialize() {
	
	MapHit.rightTopX = 0;
	MapHit.rightTopY = 0;
	MapHit.leftTopX = 0;
	MapHit.leftTopY = 0;
	MapHit.rightBottomX = 0;
	MapHit.rightBottomY = 0;
	MapHit.leftBottomX = 0;
	MapHit.leftBottomY = 0;

}
void Map::HitJudgment() {

	//右上のマップチップ上での座標を取得
	MapHit.rightTopX = (int(pos->GetPos().x + kBlocksize - 1) / kBlocksize);
	MapHit.rightTopY = int(pos->GetPos().y / kBlocksize);

	//左上のマップチップ上での座標を取得
	MapHit.leftTopX = int(pos->GetPos().x / kBlocksize);
	MapHit.leftTopY = int(pos->GetPos().y / kBlocksize);

	//右下のマップチップ上での座標を取得
	MapHit.rightBottomX = (int(pos->GetPos().x + kBlocksize - 1) / kBlocksize);
	MapHit.rightBottomY = (int(pos->GetPos().y + kBlocksize - 1) / kBlocksize);

	//左下のマップチップ上での座標を取得
	MapHit.leftBottomX = int(pos->GetPos().x / kBlocksize);
	MapHit.leftBottomY = int((pos->GetPos().y + kBlocksize - 1) / kBlocksize);
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
		}
	}
}