#include "Player.h"

void Player::Initialize() {
	for (int i = 0; i < 100; i++) {
		ball[i].position = {0,0};
		ball[i].ballState = STABLE;
		ball[i].isActive = false;
		ball[i].color = WHITE;
	}
}

void Player::Updata() {
	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	SelectTimer--;//タイマー開始

	//
	Move();
	ballUpdata();
	CheckSafety();
}

void Player::Draw() {
	Novice::ScreenPrintf(0, 0, "%f, %f",pos.x, pos.y);
	Novice::ScreenPrintf(0, 20, "%d", kCount);
	Novice::ScreenPrintf(0, 40, "%f , %f", ball[0].position.x, ball[0].position.y);
	Novice::ScreenPrintf(0, 60, "%f , %f", ball[1].position.x, ball[1].position.y);
	Novice::ScreenPrintf(0, 100, "%f, %f", delta.x, delta.y);
	Novice::ScreenPrintf(0, 120, "%f", length);

	if (!isSet) {
		Novice::DrawBox(0, 0, 1380, 768, 0.0f, 0xccffffff, kFillModeSolid);
	}
	else {
		Novice::DrawBox(0, 0, 1380, 768, 0.0f, 0xffccccff, kFillModeSolid);
		Novice::DrawEllipse(int(ball[kCount].position.x) + kBlocksize / 2, int(ball[kCount].position.y) + kBlocksize / 2, 100, 100, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
	Novice::DrawSprite(int(pos.x), int(pos.y), RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
	for (int i = 0; i < 100; i++) {
		if (ball[i].isActive) {
			Novice::DrawEllipse(int(ball[i].position.x) + 32, int(ball[i].position.y) + 32, 16, 16, 0.0f, ball[i].color, kFillModeSolid);//仮ボール
		}
	}
}

void Player::Move() {
	switch (mp)
	{
	case Player::NORMAL:
		RollBack();//一手前へ戻る
		SetPlayer();
		//if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] != m->BORDER) {//上を押したら
		//	pos.y -= 1;
		//	if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
		//		pos.y = int(pos.y / kBlocksize) * kBlocksize + kBlocksize;
		//	}
		//}
		//if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int((pos.y / kBlocksize) + 1)][int(pos.x / kBlocksize)] != m->BORDER) {//下を押したら
		//	pos.y += 1;
		//}
		//if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y / kBlocksize)][int((pos.x / kBlocksize) + 1)] != m->BORDER) {//右を押したら
		//	pos.x += 1;
		//}
		//if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] != m->BORDER) {//左を押したら
		//	pos.x -= 1;
		//	if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
		//		pos.x = int(pos.x / kBlocksize) * kBlocksize + kBlocksize;
		//	}
		//}
		break;
	case Player::SETMODE:
		if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] != m->BORDER) {//上を押したら
			pos.y -= 1;
			if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize + kBlocksize;
			}
		}
		if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int((pos.y / kBlocksize) + 1)][int(pos.x / kBlocksize)] != m->BORDER) {//下を押したら
			pos.y += 1;
		}
		if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y / kBlocksize)][int((pos.x / kBlocksize) + 1)] != m->BORDER) {//右を押したら
			pos.x += 1;
		}
		if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] != m->BORDER) {//左を押したら
			pos.x -= 1;
			if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize + kBlocksize;
			}
		}
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && (pos.x!=ball[kCount].position.x || pos.y != ball[kCount].position.y)) {
			moveCount = 0;
			isSet = false;
			MoveLimit();
			kCount += 1;
			mp = NORMAL;
		}
		break;
	}
}

void Player::MoveLimit() {
	//float Limit = 10000;

	delta = Subtract(pos, ball[kCount].position);
	length = Length(delta);
	delta.x /= length;
	delta.y /= length;
	if (length <= 100) {
		pos = pos;
	}
	else {
		pos.x = ball[kCount].position.x + delta.x * 100;
		pos.y = ball[kCount].position.y + delta.y * 100;
	}
}

void Player::SetPlayer() {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		ball[kCount].position = pos;
		isSet = true;
		ball[kCount].isActive = true;
		mp = SETMODE;

		//kCount += 1;
	}
}

void Player::RollBack() {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] && kCount>=1) {
		kCount -= 1;

		pos = ball[kCount].position;
		ball[kCount].position = {};
		ball[kCount].isActive = false;
	}
}

void Player::CheckSafety() {
	for (int i = 0; i < 100; i++){
		if (ball[i].isActive) {
			if (m->map[int(ball[i].position.y)][int(ball[i].position.x) - 1] == m->BORDER) {
				ball[i].ballState = STABLE;
				ball[i].color = WHITE;
			}
			else if (m->map[int(ball[i].position.y)][int(ball[i].position.x) + 1] == m->BORDER) {
				ball[i].ballState = STABLE;
				ball[i].color = WHITE;
			}
			else if (m->map[int(ball[i].position.y) - 1][int(ball[i].position.x)] == m->BORDER) {
				ball[i].ballState = STABLE;
				ball[i].color = WHITE;
			}
			else if (m->map[int(ball[i].position.y) + 1][int(ball[i].position.x)] == m->BORDER) {
				ball[i].ballState = STABLE;
				ball[i].color = WHITE;
			}
			else if (ball[i - 1].ballState == UNSTABLE || ball[i - 1].ballState == DANGER) {
				ball[i].ballState = DANGER;
				ball[i].color = RED;
			}
			else {
				ball[i].ballState = UNSTABLE;
				ball[i].color = 0xff9999ff;
			}
		}
	}
}

void Player::ballUpdata() {
	for (int i = 0; i < 100; i++)
	{
		if (ball[i].ballState == DANGER) {

		}
	}
}