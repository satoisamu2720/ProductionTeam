#include <Novice.h>

const char kWindowTitle[] = "サルノ橋";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1380, 768);

	// キー入力結果を受け取る箱
	char keys[356] = {0};
	char preKeys[356] = {0};

	//ブロックサイズの設定
	const int kBlocksize = 64;
	int RedBallX = 6; //赤ボールのX座標
	int RedBallY = 6; //赤ボールのY座標
	int SelectTimer = 1;//セット時長押し用タイマー
	//int BallSetTimer = 30;//赤ボールをセットした時に動かす(連打防止)
	int map[12][13] = {
		{3,3,3,3,3,3,3,3,3,3,3,3,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,0,0,0,0,0,0,0,0,0,0,0,3},
		{3,3,3,3,3,3,3,3,3,3,3,3,3}
	};
	int BallPointer[12][13] = { //ボール設置可能地点
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	//int Destination[12][13] = { //ボール設置可能地点
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0}
	//};

	//ボールの位置
	int BallPoint[12][13] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	enum MapPinterInfo {
		NONEPOINTER,//0
		SETPOINTER,//1設置可能地点
	};

	enum BallInfo {
		NONEBALL,//0
		REDBALL,//1赤ボール
	};

	//マップの定義
	enum MapInfo {
		NONE,// 0
		SETPOINT,//1置ける場所
		BLOCKTILE,//3ブロックタイル
		BORDER,//3マップ境界線
	};
	int Blocka = Novice::LoadTexture("./NoviceResources/blocka.png");//ブロック
	//int Blockb = Novice::LoadTexture("./NoviceResources/blockb.png");//ブロック
	int RedBall = Novice::LoadTexture("./NoviceResources/RedBall.png");//ボール = 1

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 356);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (keys[DIK_D] && preKeys[DIK_D]) {
			RedBallX += 1;
		}
		//プレイヤー左に移動
		if (keys[DIK_A] && preKeys[DIK_A]) {
			RedBallX -= 1;
		}
		if (keys[DIK_S] && preKeys[DIK_S]) {
			RedBallY += 1;
		}
		if (keys[DIK_W] && preKeys[DIK_W]) {
			RedBallY -= 1;
		}
		if (keys[DIK_UP] && preKeys[DIK_UP]  && RedBallY >= 2) {//上を押したら
			
				SelectTimer--;//タイマー開始
				if (BallPoint[RedBallY - 1][RedBallX] == NONEBALL && SelectTimer <= 0) {//ボールの位置-1へないことを確認
					BallPoint[RedBallY - 1][RedBallX] = REDBALL;//ボールの位置をY-1へ移動
					BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす

					
					SelectTimer = 10;
					RedBallY -= 1;
				}
			
		}

		if (keys[DIK_DOWN] && preKeys[DIK_DOWN]&& RedBallY <= 9) {//下を押したら
			
				SelectTimer--;//タイマー開始
				if (BallPoint[RedBallY + 1][RedBallX] == NONEBALL && SelectTimer <= 0) {//ボールの位置+1へないことを確認
					BallPoint[RedBallY + 1][RedBallX] = REDBALL;//ボールの位置をY+1へ移動
					BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす

					
					SelectTimer = 10;
					RedBallY += 1;
				}
			
		}
		if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT]  && RedBallX <= 10) {//右を押したら
			
				SelectTimer--;//タイマー開始
				if (BallPoint[RedBallY][RedBallX + 1] == NONEBALL && SelectTimer <= 0) {//ボールの位置+1へないことを確認
					BallPoint[RedBallY][RedBallX + 1] = REDBALL;//ボールの位置をX+1へ移動
					BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす

				
					SelectTimer = 10;
					RedBallX += 1;
				}
			
		}
		if (keys[DIK_LEFT] && preKeys[DIK_LEFT] && RedBallX >= 2) {//左を押したら
			
				SelectTimer--;//タイマー開始
				if (BallPoint[RedBallY][RedBallX - 1] == NONEBALL && SelectTimer <= 0) {//ボールの位置-1へないことを確認
					BallPoint[RedBallY][RedBallX - 1] = REDBALL;//ボールの位置をX-1へ移動
					BallPoint[RedBallY][RedBallX] = NONEBALL;//ボールの元の位置からボールをなくす

					
					SelectTimer = 10;
					RedBallX -= 1;
				}
			
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 13;j++) {
				if (map[i][j] == BORDER) {//マップブロック描画
					Novice::DrawSprite(j*kBlocksize,i*kBlocksize, Blocka, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				}
				if (map[i][j] == NONE) {//マップブロック描画
					//Novice::DrawSprite(j * kBlocksize, i * kBlocksize, Blockb, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				}
				if (BallPoint[j][i] == REDBALL) {//赤ボール描画

					Novice::DrawSprite(i * kBlocksize, j * kBlocksize, RedBall, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
				}
					
			}
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
