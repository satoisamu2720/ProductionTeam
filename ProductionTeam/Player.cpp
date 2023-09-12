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
	Novice::GetAnalogInputLeft(0, &leftx, &lefty);
	Novice::GetAnalogInputRight(0, &rightx, &righty);

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
	Novice::ScreenPrintf(1100, 240, "x = %d,y = %d", rightx, righty);
	




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
			Novice::DrawEllipse(int(ball[i].position.x) + kBlocksize / 2, int(ball[i].position.y) + kBlocksize / 2, 16, 16, 0.0f, ball[i].color, kFillModeSolid);//仮ボール
		}
	}
}

void Player::Move() {
	switch (mp)
	{
	case Player::NORMAL:
		RollBack();//一手前へ戻る
		SetPlayer();
		if (lefty <= -10000 || keys[DIK_UP] && preKeys[DIK_UP]) {//上を押したら
			pos.y -= speed;
			if ((m->map[int(pos.y / kBlocksize)][int((pos.x + kBlocksize - 1) / kBlocksize)] == m->BORDER) || (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER)) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize + kBlocksize;
			}
		}
		if (lefty >= 10000 || keys[DIK_DOWN] && preKeys[DIK_DOWN]) {//下を押したら
			pos.y += speed;
			if ((m->map[int((pos.y / kBlocksize) + 1)][int(pos.x / kBlocksize)] == m->BORDER || (m->map[int((pos.y / kBlocksize) + 1)][int((pos.x + kBlocksize - 1) / kBlocksize)] == m->BORDER))) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize;
			}
		}
		if (leftx >= 10000 || keys[DIK_RIGHT] && preKeys[DIK_RIGHT]) {//右を押したら
			pos.x += speed;
			if ((m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize) + 1] == m->BORDER || (m->map[int((pos.y + kBlocksize - 1) / kBlocksize)][int(pos.x / kBlocksize) + 1] == m->BORDER))) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize;
			}
		}
		if (leftx <= -10000 || keys[DIK_LEFT] && preKeys[DIK_LEFT]) {//左を押したら
			pos.x -= speed;
			if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER || m->map[int((pos.y + kBlocksize - 1) / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize + kBlocksize;
			}
		}
		break;
	case Player::SETMODE:
		if (righty <= -10000||keys[DIK_UP] && preKeys[DIK_UP]) {//上を押したら
			pos.y -= speed;
			if ((m->map[int(pos.y / kBlocksize)][int((pos.x + kBlocksize - 1) / kBlocksize)] == m->BORDER) || (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER)) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize + kBlocksize;
			}
		}
		if (righty >= 10000||keys[DIK_DOWN] && preKeys[DIK_DOWN]) {//下を押したら
			pos.y += speed;
			if ((m->map[int((pos.y / kBlocksize) + 1)][int(pos.x / kBlocksize)] == m->BORDER || (m->map[int((pos.y / kBlocksize) + 1)][int((pos.x + kBlocksize - 1) / kBlocksize)] == m->BORDER))) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize;
			}
		}
		if (rightx >= 10000||keys[DIK_RIGHT] && preKeys[DIK_RIGHT]) {//右を押したら
			pos.x += speed;
			if ((m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize) + 1] == m->BORDER || (m->map[int((pos.y + kBlocksize - 1) / kBlocksize)][int(pos.x / kBlocksize) + 1] == m->BORDER))) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize;
			}
		}
		if (rightx <= -10000||keys[DIK_LEFT] && preKeys[DIK_LEFT]) {//左を押したら
			pos.x -= speed;
			if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER || m->map[int((pos.y + kBlocksize - 1) / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize + kBlocksize;
			}
		}
		MoveLimit();
		if (Novice::IsPressButton(0, kPadButton10)||keys[DIK_SPACE] && !preKeys[DIK_SPACE] && moveCount <= 10 &&(pos.x!=ball[kCount].position.x || pos.y != ball[kCount].position.y)) {
			moveCount = 0;
			isSet = false;
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
	if (Novice::IsPressButton(0, kPadButton10) || keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
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