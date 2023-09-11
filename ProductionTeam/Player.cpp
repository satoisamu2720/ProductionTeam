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

	Vector3 newPlayer;
	newPlayer = { pos.x,pos.y,10.0f };
	Matrix4x4 matPlayer;
	matPlayer = MakeAffineMatrix(
		{ 1.0f,1.0f,1.0f },
		{ 0.0f,0.0f,0.0f },
		{ 0.0f,0.0f,0.0f });

	Matrix4x4 CameraMatworld = MakeAffineMatrix(
		{ 1.0f,1.0f,1.0f },
		{ 0.0f,0.0f,0.0f },
		{ 0.0f,0.0f,-2.5f }
	);
	Matrix4x4 viewMatrix = Inverse(CameraMatworld);

	Matrix4x4 ProjectionMatrix = MakePerspectiveFovMatrix(
		0.45f,
		float(kWindowWidth) / float(kWindowHeight),
		0.1f,
		100.0f);

	Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, ProjectionMatrix);

	Matrix4x4 viewportMatrix = MakeViewportMatrix(
		0.0f,
		0.0f,
		float(kWindowWidth),
		float(kWindowHeight),
		0,
		1);
	Matrix4x4 matWorldViewProjection = Multiply(matPlayer, viewProjectionMatrix);
	newPlayer = Transform(newPlayer, matWorldViewProjection);
	newPlayer = Transform(newPlayer, viewportMatrix);

	Novice::DrawSprite(int(newPlayer.x), int(newPlayer.y), RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

	for (int i = 0; i < 100; i++) {
		
		Vector3 newBall[100];
		newBall[i] = { ball[i].position.x,ball[i].position.y,10.0f };
		Matrix4x4 matBall[100];
		matBall[i] = MakeAffineMatrix(
			{ 1.0f,1.0f,1.0f },
			{ 0.0f,0.0f,0.0f },
			{ 0.0f,0.0f,0.0f });

		Matrix4x4 CameraMatworld = MakeAffineMatrix(
			{ 1.0f,1.0f,1.0f },
			{ 0.0f,0.0f,0.0f },
			{ 0.0f,0.0f,-2.5f }
		);
		Matrix4x4 viewMatrix = Inverse(CameraMatworld);

		Matrix4x4 ProjectionMatrix = MakePerspectiveFovMatrix(
			0.45f,
			float(kWindowWidth) / float(kWindowHeight),
			0.1f,
			100.0f);

		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, ProjectionMatrix);

		Matrix4x4 viewportMatrix = MakeViewportMatrix(
			0.0f,
			0.0f,
			float(kWindowWidth),
			float(kWindowHeight),
			0,
			1);
		Matrix4x4 matWorldViewProjection = Multiply(matBall[i], viewProjectionMatrix);
		newBall[i] = Transform(newBall[i], matWorldViewProjection);
		newBall[i] = Transform(newBall[i], viewportMatrix);

		if (ball[i].isActive) {
			Novice::DrawEllipse(int(newBall[i].x) + 32, int(newBall[i].y) + 32, ball[i].radius, ball[i].radius, 0.0f, ball[i].color, kFillModeSolid);//仮ボール
		}
	}
}

void Player::Move() {
	

	Novice::GetAnalogInputLeft(0, &playerVX, &playerVY);

	pos.x += float(playerVX)/ moveDenominator;
	pos.y -= float(playerVY)/ moveDenominator;
	switch (mp)
	{
	case Player::NORMAL:
		RollBack();//一手前へ戻る
		SetPlayer();
		//if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//上を押したら
		//	pos.y += 0.1f;
		//}
		//if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//下を押したら
		//	pos.y -= 0.1f;
		//}
		//if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//右を押したら
		//	pos.x += 0.1f;
		//}
		//if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//左を押したら
		//	pos.x -= 0.1f;
		//}
		if (m->map[int(pos.y - float(playerVY) / moveDenominator)][int(pos.x+ float(playerVX) / moveDenominator)] != m->BORDER) {//上を押したら
			pos.x += float(playerVX) / moveDenominator;
			pos.y -= float(playerVY) / moveDenominator;
		}
		break;
	case Player::SETMODE:
		if (moveCount < moveMax) {
			if (keys[DIK_UP] && preKeys[DIK_UP] && SelectTimer <= 0 && m->map[int(pos.y - 1)][int(pos.x)] != m->BORDER) {//上を押したら
				moveCount += 1;
				pos.y += 0.1f;
			}
			if (keys[DIK_DOWN] && SelectTimer <= 0 && preKeys[DIK_DOWN] && m->map[int(pos.y + 1)][int(pos.x)] != m->BORDER) {//下を押したら
				moveCount += 1;
				pos.y -= 0.1f;
			}
			if (keys[DIK_RIGHT] && SelectTimer <= 0 && preKeys[DIK_RIGHT] && m->map[int(pos.y)][int(pos.x + 1)] != m->BORDER) {//右を押したら
				moveCount += 1;
				pos.x += 0.1f;
			}
			if (keys[DIK_LEFT] && SelectTimer <= 0 && preKeys[DIK_LEFT] && m->map[int(pos.y)][int(pos.x - 1)] != m->BORDER) {//左を押したら
				moveCount += 1;
				pos.x -= 0.1f;
			}
		}
		if (moveCount >= 1 && keys[DIK_SPACE] && !preKeys[DIK_SPACE]||Novice::IsTriggerButton(0,kPadButton8)) {
			moveCount = 0;
			isSet = false;
			mp = NORMAL;
		}
		break;
	}
}

void Player::SetPlayer() {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] || Novice::IsTriggerButton(0, kPadButton8)) {
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