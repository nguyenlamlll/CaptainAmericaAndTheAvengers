#pragma once
#include "Scene.h"
class PlayScene : public Scene
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

