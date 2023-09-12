#include "Title.h"

void Title::Initialize() {

}

void Title::Updata(int scene) {
	//キー受け取り
	memcpy(preKeys, keys, 356);
	Novice::GetHitKeyStateAll(keys);

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		scene = PLAY;
	}

}

void Title::Draw() {

}