#pragma once
#include <Novice.h>

class Title
{
public:

	void Update();

	void Draw();

private:

	int titleImage = Novice::LoadTexture("./NoviceResources/haikei.png");

};

