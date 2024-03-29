#pragma once
#include "Scene.h"
#include "Game.h"
class PlayScene : public Scene
{
private:
	Game* game;

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

