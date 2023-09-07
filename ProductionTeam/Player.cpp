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
	if (!isSet) {
		Novice::DrawBox(0, 0, 1380, 768, 0.0f, 0xccffffff, kFillModeSolid);
	}
	else {
		Novice::DrawBox(0, 0, 1380, 768, 0.0f, 0xffccccff, kFillModeSolid);
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
		if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//上を押したら
			pos.y -= 1;
		}
		if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//下を押したら
			pos.y += 1;
		}
		if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//右を押したら
			pos.x += 1;
		}
		if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//左を押したら
			pos.x -= 1;
		}
		break;
	case Player::SETMODE:
		if (moveCount < moveMax) {
			if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//上を押したら
				moveCount += 1;
				pos.y -= 1;
			}
			if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//下を押したら
				moveCount += 1;
				pos.y += 1;
			}
			if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//右を押したら
				moveCount += 1;
				pos.x += 1;
			}
			if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//左を押したら
				moveCount += 1;
				pos.x -= 1;
			}
		}
		if (moveCount >= 1 && keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			moveCount = 0;
			isSet = false;
			mp = NORMAL;
		}
		break;
	}
}

void Player::SetPlayer() {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		ball[kCount].position = pos;
		isSet = true;
		ball[kCount].isActive = true;
		mp = SETMODE;

		kCount += 1;
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