#include "sceneManager.h"

void sceneManager::Initialize() {
	player->Initialize();
}
void sceneManager::Update() {

	Novice::StopAudio(titleVoice);

	if (Novice::IsPlayingAudio(gameVoice) == 0 || gameVoice == -1) {
		gameVoice = Novice::PlayAudio(gameMusic, true, 0.5f);
	}

	player->Updata();
}
void sceneManager::Draw() {
	player->Draw();
	m->Draw();
}

/// <summary>
/// ここからタイトル処理
/// </summary>

void sceneManager::TitleUpdate() {
	//キー受け取り

	if (Novice::IsPlayingAudio(titleVoice) == 0 || titleVoice == -1) {
		titleVoice = Novice::PlayAudio(titleMusic, true, 0.5f);
	}

	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);
	Novice::GetAnalogInputLeft(0, &leftX, &leftY);

	switch (titleState)
	{
	case GAMESTATE:

		if (keys[DIK_DOWN] && !preKeys[DIK_DOWN] || leftY >= 32768 && count1 == 0) {
			titleState = EXSCENE;
			count1 = 1;
		}

		if (keys[DIK_UP] && !preKeys[DIK_UP] || leftY <= -32767 && count1 == 0) {
			titleState = END;
			count1 = 1;
		}

		if (leftY == 0 && count1 == 1) {
			count1 = 0;
		}

		if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] || Novice::IsTriggerButton(0, kPadButton11)) {
			gameScene = PLAY;
		}

		break;

	case EXSCENE:

		if (keys[DIK_DOWN] && !preKeys[DIK_DOWN] || leftY >= 32768 && count1 == 0) {
			titleState = END;
			count1 = 1;
		}

		if (keys[DIK_UP] && !preKeys[DIK_UP] || leftY <= -32767 && count1 == 0) {
			titleState = GAMESTATE;
			count1 = 1;
		}

		if (leftY == 0 && count1 == 1) {
			count1 = 0;
		}

		if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] || Novice::IsTriggerButton(0, kPadButton11)) {
			gameScene = EXPLANATION;
		}

		break;

	case END:

		if (keys[DIK_DOWN] && !preKeys[DIK_DOWN] || leftY >= 32768 && count1 == 0) {
			titleState = GAMESTATE;
			count1 = 1;
		}

		if (keys[DIK_UP] && !preKeys[DIK_UP] || leftY <= -32767 && count1 == 0) {
			titleState = EXSCENE;
			count1 = 1;
		}

		if (leftY == 0 && count1 == 1) {
			count1 = 0;
		}

		if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] || Novice::IsTriggerButton(0, kPadButton11)) {
			gameEnd = true;
		}

		break;
	}

}

void sceneManager::TitleDraw() {

	title->Draw();

	switch (titleState)
	{
	case GAMESTATE:

		Novice::DrawSprite(305, 365, arrowImage, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

		break;
	case EXSCENE:

		Novice::DrawSprite(410, 520, arrowImage, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

		break;

	case END:

		Novice::DrawSprite(390, 655, arrowImage, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

		break;
	}

	Novice::DrawSprite(0, 0, titleSelect, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

}

void sceneManager::ExplanationUpdate() {

	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] || Novice::IsTriggerButton(0, kPadButton11)) {
		gameScene = TITLE;
	}

}

void sceneManager::ExplanationDraw() {

	Novice::DrawSprite(0, 0, EXImage, 1.1f, 1.1f, 0.0f, 0xFFFFFFFF);

}

//ゲームクリア処理

void sceneManager::GameClearUpdate() {

	if ((m->map[int(player->GetPos().y / m->GetBlockSize())][int((player->GetPos().x + m->GetBlockSize() - 1) / m->GetBlockSize())] == m->GOAL) || (m->map[int(player->GetPos().y / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL)) {
		gameScene = CLEAR;
	}

	if ((m->map[int((player->GetPos().y / m->GetBlockSize() + 1))][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL || (m->map[int((player->GetPos().y / m->GetBlockSize()) + 1)][int((player->GetPos().x + m->GetBlockSize() - 1) / m->GetBlockSize())] == m->GOAL))) {
		gameScene = CLEAR;
	}

	if ((m->map[int(player->GetPos().y / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize()) + 1] == m->GOAL || (m->map[int((player->GetPos().y + m->GetBlockSize() - 1) / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize()) + 1] == m->GOAL))) {
		gameScene = CLEAR;
	}

	if (m->map[int(player->GetPos().y / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL || m->map[int((player->GetPos().y + m->GetBlockSize() - 1) / m->GetBlockSize())][int(player->GetPos().x / m->GetBlockSize())] == m->GOAL) {
		gameScene = CLEAR;
	}

}

//ここまで

/// <summary>
/// ここからゲームクリア画面
/// </summary>

void sceneManager::ClearUpdate() {

	Novice::StopAudio(gameVoice);

	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN] || Novice::IsTriggerButton(0, kPadButton11)) {
		gameScene = TITLE;
	}

}

void sceneManager::ClearDraw() {

	clear->Draw();

}