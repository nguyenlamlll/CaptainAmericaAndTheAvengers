#pragma once
#include "Scene.h"
#include "TextureManager.h"
#include "Sprite.h"
class OptionScene : public Scene
{
private:
	TextureManager* textureM;
	SpriteData data;

public:
	OptionScene();
	OptionScene(Graphics* graphics, Input* input);
	~OptionScene();

	void init();
	void update();
	void draw();
	void run();
	void release();
};

