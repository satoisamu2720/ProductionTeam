#pragma once
#include <Novice.h>
#include "sceneManager.h"

class Title
{
public:

	void Initialize();

	void Updata(int scene);

	void Draw();

private:

	char keys[356] = {};
	char preKeys[356] = {};

};

