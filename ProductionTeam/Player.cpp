#include "Player.h"

void Player::Initialize() {

}

void Player::Updata(char keys[],char preKeys[]) {
	Move(keys,preKeys);
	SetPlayer(keys, preKeys);
}

void Player::Draw() {
	if (isSet) {
		Novice::DrawEllipse(int(pos.x) + 32, int(pos.y) + 32, 32, 32, 0.0f, WHITE, kFillModeSolid);
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 13; j++) {
			if (BallPoint[j][i] == REDBALL) {//赤ボール描画
				Novice::DrawSprite(i * kBlocksize, j * kBlocksize, RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
		}
	}
}

void Player::Move(char keys[], char preKeys[]) {
	if (keys[DIK_UP] && preKeys[DIK_UP] && RedBallY >= 2) {//上を押したら
		SelectTimer--;//タイマー開始
		if (BallPoint[RedBallY - 1][RedBallX] == NONEBALL && SelectTimer <= 0) {//ボールの位置-1へないことを確認
			BallPoint[RedBallY - 1][RedBallX] = REDBALL;//ボールの位置をY-1へ移動
			BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす

			SelectTimer = 10;
			RedBallY -= 1;
		}
	}

	else if (keys[DIK_DOWN] && preKeys[DIK_DOWN] && RedBallY <= 9) {//下を押したら

		SelectTimer--;//タイマー開始
		if (BallPoint[RedBallY + 1][RedBallX] == NONEBALL && SelectTimer <= 0) {//ボールの位置+1へないことを確認
			BallPoint[RedBallY + 1][RedBallX] = REDBALL;//ボールの位置をY+1へ移動
			BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす


			SelectTimer = 10;
			RedBallY += 1;
		}

	}
	else if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] && RedBallX <= 10) {//右を押したら

		SelectTimer--;//タイマー開始
		if (BallPoint[RedBallY][RedBallX + 1] == NONEBALL && SelectTimer <= 0) {//ボールの位置+1へないことを確認
			BallPoint[RedBallY][RedBallX + 1] = REDBALL;//ボールの位置をX+1へ移動
			BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす


			SelectTimer = 10;
			RedBallX += 1;
		}

	}
	else if (keys[DIK_LEFT] && preKeys[DIK_LEFT] && RedBallX >= 2) {//左を押したら

		SelectTimer--;//タイマー開始
		if (BallPoint[RedBallY][RedBallX - 1] == NONEBALL && SelectTimer <= 0) {//ボールの位置-1へないことを確認
			BallPoint[RedBallY][RedBallX - 1] = REDBALL;//ボールの位置をX-1へ移動
			BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす


			SelectTimer = 10;
			RedBallX -= 1;
		}
	}
}

void Player::SetPlayer(char keys[], char preKeys[]) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		pos = GetPosition();
		isSet = true;
	}
}

Vector2 Player::GetPosition() {
	Vector2 pos;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 13; j++) {
			if (BallPoint[j][i] == REDBALL) {//赤ボール描画
				pos.x = i * kBlocksize;
				pos.y = j * kBlocksize;
				return pos;
			}
		}
	}
}