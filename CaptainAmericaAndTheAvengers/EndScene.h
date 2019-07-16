#pragma once
#include "Scene.h"
#include "TextureManager.h"
class EndScene : public Scene
{
private:
	TextureManager* textureM;
	SpriteData data;
public:
	EndScene();
	EndScene(Graphics* graphics, Input* input);
	~EndScene();

	void init();

	void update();

	void draw();

	void release();

	void run();
};

