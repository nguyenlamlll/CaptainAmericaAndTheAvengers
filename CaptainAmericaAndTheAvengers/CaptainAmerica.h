#pragma once
#include "BaseObject.h"
#include "Sprite.h"
#include "Graphics.h"
#include "Input.h"
#include "SpriteManager.h"
#include "TextureManager.h"
#include "GameError.h"
#include "Animation.h"

#include <list>
#include <map>

class CaptainAmerica : public BaseObject
{
private:
	Input* input;
	TextureManager* textureManager;
	Graphics* graphics;

	Animation* startAnimation;
	Animation* moveAnimation;

	bool visible;

public:
	CaptainAmerica();
	CaptainAmerica(TextureManager* textureM, Graphics* graphics, Input* input);
	~CaptainAmerica();

	void handleInput(float dt);
	//void onCollision(float dt);

	void update(float dt);
	void draw();
	void drawIndicators();
	void release();

	//void updateHorizontal(float dt);
	//void updateVertical(float dt);

	Animation* getStartAnimation();
	Animation* getMoveAnimation();
};

