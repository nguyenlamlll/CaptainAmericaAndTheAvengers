#pragma once
#include "Scene.h"
class PlayScene
{
private:

public:
	PlayScene();
	PlayScene(Graphics* graphics, Input* input);
	~PlayScene();

	void init();
	void update();
	void draw();
	void run();
	void release();


};

