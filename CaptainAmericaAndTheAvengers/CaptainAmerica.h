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

	Animation* hitAnimation;
	Animation* jumpAnimation;
	Animation* kickAnimation;
	Animation* startAnimation;
	Animation* moveAnimation;
	Animation* sitAttackAnimation;
	Animation* spinAnimation;

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

	Animation* getHitAnimation() { return this->hitAnimation; }
	Animation* getJumpAnimation() { return this->jumpAnimation; }
	Animation* getKickAnimation() { return this->kickAnimation; }
	Animation* getStartAnimation() { return this->startAnimation; }
	Animation* getMoveAnimation() { return this->moveAnimation; }
	Animation* getSitAttackAnimation() { return this->sitAttackAnimation; }
	Animation* getSpinAnimation() { return this->spinAnimation; }
};

