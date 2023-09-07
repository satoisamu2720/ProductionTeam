#include "Player.h"

void Player::Initialize() {
	
}

void Player::Updata() {
	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	SelectTimer--;//タイマー開始

	//
	Move();
}

void Player::Draw() {
	if (!isSet) {
		Novice::DrawBox(0, 0, 1380, 768, 0.0f, 0xccffffff, kFillModeSolid);
	}
	else {
		Novice::DrawBox(0, 0, 1380, 768, 0.0f, 0xffccccff, kFillModeSolid);
	}
	if (isSet) {
		Novice::DrawEllipse(int(kPos.x) + 32, int(kPos.y) + 32, 16, 16, 0.0f, WHITE, kFillModeSolid);//仮ボール
	}
	if (isSelectSet) {
		//Novice::DrawSprite(int(sPos.x) * kBlocksize, int(sPos.y) * kBlocksize, maku->waku, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
		Novice::DrawEllipse(int(sPos.x) * kBlocksize, int(sPos.y) * kBlocksize, 16, 16, 0.0f, BLACK, kFillModeSolid);//選択
	}
	Novice::DrawSprite(int(pos.x) * kBlocksize, int(pos.y) * kBlocksize, RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}

void Player::Move() {
	switch (mp)
	{
	case Player::NORMAL:
		SetPlayer();
		Select();
		
		if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//上を押したら
			SelectTimer = 10;
			pos.y -= 1;
		}
		else if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//下を押したら
			SelectTimer = 10;
			pos.y += 1;
		}
		else if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//右を押したら
			SelectTimer = 10;
			pos.x += 1;
		}
		else if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//左を押したら
			SelectTimer = 10;
			pos.x -= 1;
		}
		break;
	case Player::SETMODE:
		if (moveCount < moveMax) {
			if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//上を押したら
				SelectTimer = 10;
				moveCount += 1;
				pos.y -= 1;
			}
			else if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//下を押したら
				SelectTimer = 10;
				moveCount += 1;
				pos.y += 1;
			}
			else if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//右を押したら
				SelectTimer = 10;
				moveCount += 1;
				pos.x += 1;
			}
			else if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//左を押したら
				SelectTimer = 10;
				moveCount += 1;
				pos.x -= 1;
			}
		}
		if (moveCount >= moveMax && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			moveCount = 0;
			isSet = false;
			mp = NORMAL;
		}
		break;
	case Player::SELRCT:
		
		if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && sPos.x <= 18) {//右を押したら
			SelectTimer = 10;
			moveCount += 1;
			sPos.x += 2;
		}
		else if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && sPos.x >= 16) {//左を押したら
			SelectTimer = 10;
			sPos.x -= 2;
		}
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]&& sPos.x == 19) {
			//サル1
			isSelectSet = false;
			mp = NORMAL;
		}
		else if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && sPos.x == 17) {
			//サル2
			isSelectSet = false;
			mp = NORMAL;
		}
		else if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && sPos.x == 15) {
			//サル3
			isSelectSet = false;
			mp = NORMAL;
		}
		break;
	}
}

void Player::SetPlayer() {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		kPos.x = pos.x * 64;
		kPos.y = pos.y * 64;
		isSet = true;
		mp = SETMODE;
	}
}

void Player::FixPlayer() {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		kPos.x = pos.x * 64;
		kPos.y = pos.y * 64;
		isSet = false;
		mp = NORMAL;
	}
}
void Player::ResetPlayer() {

}
void Player::Select() {
	if (keys[DIK_S] && preKeys[DIK_S]) {
		isSelectSet = true;
		sPos.x = pos.x;
		sPos.y = pos.y;
		sPos.x = 17;
		sPos.y = 6;
		mp = SELRCT;
	}
}