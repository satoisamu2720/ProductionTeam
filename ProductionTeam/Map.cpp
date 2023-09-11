#include "Map.h"

void Map::Initialize() {

}

void Map::Draw() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 20; j++) {
			Vector3 border[12][20];
			border[i][j] = { float(j * kBlocksize - kblockNumberX * kBlocksize / 2), float(i * -kBlocksize + kblockNumberY * kBlocksize / 2), 10.0f };
			Matrix4x4 matBorder[12][20];
			matBorder[i][j] = MakeAffineMatrix(
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
			Matrix4x4 matWorldViewProjection = Multiply(matBorder[i][j], viewProjectionMatrix);
			border[i][j] = Transform(border[i][j], matWorldViewProjection);
			border[i][j] = Transform(border[i][j], viewportMatrix);

			if (map[i][j] == BORDER) {//マップブロック描画
				Novice::DrawSprite(int(border[i][j].x), int(border[i][j].y),
					Blocka, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
			if (map[i][j] == NONE) {//マップブロック描画
				Novice::DrawSprite(int(border[i][j].x), int(border[i][j].y),
					waku, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
			}
		}
	}
}