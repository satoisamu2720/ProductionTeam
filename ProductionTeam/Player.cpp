#include "Player.h"

void Player::Initialize() {
	pos = { 1.0f * kBlocksize,9.0f * kBlocksize };
	for (int i = 0; i < 100; i++) {
		ball[i].position = { 1.0f * kBlocksize,9.0f * kBlocksize };
		ball[i].ballState = NEUTRAL;
		ball[i].isActive = false;
		ball[i].color = 0x00000000;
		ball[i].fallTimer = ball[i].fallTimerMax;
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
	FallBlock();


	for (int i = 0; i < 100; i++) {
		if (ball[i].ballState == STABLE) {
			ball[i].Image = NEUTRALImage;
		}
		else if (ball[i].ballState == NEUTRAL) {
			ball[i].Image = NEUTRALImage;
		}
		else if (ball[i].ballState == UNSTABLE) {
			ball[i].Image = UNSTABLEImage;
		}
		else {
			ball[i].Image = DANGERImage;
		}
	}
}

void Player::Draw() {
	Novice::ScreenPrintf(0, 0, "%f, %f", pos.x, pos.y);
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
	for (int i = 0; i < 100; i++) {
		if (ball[i].isActive) {
			Novice::DrawEllipse(int(ball[i].position.x) + kBlocksize / 2, int(ball[i].position.y) + kBlocksize / 2, 16, 16, 0.0f, ball[i].color, kFillModeSolid);//仮ボール
			Novice::DrawBox(int(ball[i].position.x), int(ball[i].position.y), 64, 64, 0.0f, ball[i].color, kFillModeSolid);//仮ボール
			
			Novice::DrawSprite(int(ball[i].position.x), int(ball[i].position.y), ball[i].Image, 1, 1, 0.0f ,0xFFFFFFFF);
		}
	}
	Novice::DrawSprite(int(pos.x), int(pos.y), RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}

void Player::Move() {
	switch (mp)
	{
	case Player::NORMAL:

		RollBack();//一手前へ戻る
		SetPlayer();

		break;

	case Player::SETMODE:

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

		MoveLimit();

		/*if ((righty <= -10000 || keys[DIK_UP] && preKeys[DIK_UP]) || (righty >= 10000 || keys[DIK_DOWN] && preKeys[DIK_DOWN])) {
			if ((m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize) + 1] == m->BORDER || (m->map[int((pos.y + kBlocksize - 1) / kBlocksize)][int(pos.x / kBlocksize) + 1] == m->BORDER))) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize;
			}
			if (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER || m->map[int((pos.y + kBlocksize - 1) / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER) {
				pos.x = int(pos.x / kBlocksize) * kBlocksize + kBlocksize;
			}
		}

		if ((rightx >= 10000 || keys[DIK_RIGHT] && preKeys[DIK_RIGHT]) || (rightx <= -10000 || keys[DIK_LEFT] && preKeys[DIK_LEFT])) {
			if ((m->map[int(pos.y / kBlocksize)][int((pos.x + kBlocksize - 1) / kBlocksize)] == m->BORDER) || (m->map[int(pos.y / kBlocksize)][int(pos.x / kBlocksize)] == m->BORDER)) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize + kBlocksize;
			}
			if ((m->map[int((pos.y / kBlocksize) + 1)][int(pos.x / kBlocksize)] == m->BORDER || (m->map[int((pos.y / kBlocksize) + 1)][int((pos.x + kBlocksize - 1) / kBlocksize)] == m->BORDER))) {
				pos.y = int(pos.y / kBlocksize) * kBlocksize;
			}
		}*/

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] || Novice::IsTriggerButton(0, kPadButton10) && (pos.x != ball[kCount].position.x || pos.y != ball[kCount].position.y)) {
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
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] || Novice::IsTriggerButton(0, kPadButton10)) {
		ball[kCount].position = pos;
		ball[kCount].center = { ball[kCount].position.x + kBlocksize / 2,ball[kCount].position.y + kBlocksize / 2 };

		isSet = true;
		ball[kCount].isActive = true;
		mp = SETMODE;

		//kCount += 1;
	}
}

void Player::RollBack() {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] && kCount >= 1) {
		kCount -= 1;

		pos = ball[kCount].position;
		ball[kCount].position = {};
		ball[kCount].isActive = false;
		ball[kCount + 1].fallTimer = ball[kCount].fallTimerMax;
		ball[kCount + 1].ballState = NEUTRAL;
	}
}

void Player::CheckSafety() {
	for (int i = 0; i < 100; i++) {//ball
		for (int j = 0; j < 20; j++) {//mapX
			for (int k = 0; k < 12; k++) {//mapY
				if (ball[i].isActive) {
					if (m->map[k][j] == m->BORDER)
					{
						int mapChipCenterX = kBlocksize * j + kBlocksize / 2;
						int mapChipCenterY = kBlocksize * k + kBlocksize / 2;
						float distanceX = sqrt((ball[i].center.x - mapChipCenterX) * (ball[i].center.x - mapChipCenterX));
						float distanceY = sqrt((ball[i].center.y - mapChipCenterY) * (ball[i].center.y - mapChipCenterY));
						if (distanceX <= kBlocksize && distanceY <= kBlocksize)
						{
							ball[i].ballState = STABLE;
							ball[i].color = WHITE;

							if (ball[i - 1].ballState == DANGER) {
								ball[i - 1].ballState = UNSTABLE;
								ball[i - 1].color = 0xff9999ff;
								ball[i - 1].fallTimer = ball[i].fallTimerMax;
							}
						};

					}
					else if (ball[i - 1].ballState == UNSTABLE || ball[i - 1].ballState == DANGER)
					{
						if (ball[i].ballState != STABLE)
						{
							ball[i].ballState = DANGER;
							ball[i].color = RED;
						}
					}
					else if (ball[i].ballState != STABLE)
					{
						ball[i].ballState = UNSTABLE;
						ball[i].color = 0xff9999ff;
					}
				}
			}
		}
	}
}

void Player::FallBlock()
{
	for (int i = 0; i < 100; i++)
	{
		if (ball[i].ballState == DANGER)
		{
			ball[i].fallTimer--;
		}
		if (kCount < i && ball[kCount + 1].isActive == false)
		{
			ball[i].position = {};
			ball[i].isActive = false;
			ball[i].ballState = NEUTRAL;
			ball[i].color = 0x00000000;
			ball[i].fallTimer = ball[i].fallTimerMax;

		}
		if (ball[i].fallTimer <= 0)
		{
			kCount = i - 1;
			isSet = true;
			mp = SETMODE;
			pos = ball[kCount].position;
			ball[i].position = {};
			ball[i].isActive = false;
			ball[i].fallTimer = ball[i].fallTimerMax;
			ball[i].ballState = NEUTRAL;
			ball[i].color = 0x00000000;
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
