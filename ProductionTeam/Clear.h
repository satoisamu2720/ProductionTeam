#pragma once
#include <Novice.h>

class Clear
{
public:

	void Update();

	void Draw();

private:

	int clearImage = Novice::LoadTexture("./NoviceResources/gameClear.png");

};

