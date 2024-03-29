#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "Sprite.h"
class OptionScene : public Scene
{
private:
	TextureManager* textureM;
	SpriteData data;

	SceneManager* sceneManager;
public:
	OptionScene();
	OptionScene(Graphics* graphics, Input* input);
	OptionScene(Graphics* graphics, Input* input, SceneManager* sceneManager);
	~OptionScene();

	void init();
	void update();
	void draw();
	void run();
	void release();
};

