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
	//�L�[�󂯎��
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	SelectTimer--;//�^�C�}�[�J�n

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
	Novice::DrawSprite(int(pos.x) * kBlocksize, int(pos.y) * kBlocksize, RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
	for (int i = 0; i < 100; i++) {
		if (ball[i].isActive) {
			Novice::DrawEllipse(int(ball[i].position.x)*64 + 32, int(ball[i].position.y)*64 + 32, 16, 16, 0.0f, ball[i].color, kFillModeSolid);//���{�[��
		}
	}
}

void Player::Move() {
	switch (mp)
	{
	case Player::NORMAL:
		RollBack();//���O�֖߂�
		SetPlayer();
		//if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//�����������
		//	SelectTimer = 10;
		//	pos.y -= 1;
		//}
		//else if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//������������
		//	SelectTimer = 10;
		//	pos.y += 1;
		//}
		//else if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//�E����������
		//	SelectTimer = 10;
		//	pos.x += 1;
		//}
		//else if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//������������
		//	SelectTimer = 10;
		//	pos.x -= 1;
		//}
		break;
	case Player::SETMODE:
		if (moveCount < moveMax) {
			if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//�����������
				SelectTimer = 10;
				moveCount += 1;
				pos.y -= 1;
			}
			else if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//������������
				SelectTimer = 10;
				moveCount += 1;
				pos.y += 1;
			}
			else if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//�E����������
				SelectTimer = 10;
				moveCount += 1;
				pos.x += 1;
			}
			else if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//������������
				SelectTimer = 10;
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

void Player::FixPlayer() {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isSet = false;
		mp = NORMAL;
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