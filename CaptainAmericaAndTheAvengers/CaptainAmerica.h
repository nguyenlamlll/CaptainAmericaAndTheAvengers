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

	Animation* attackAnimation;
	Animation* dashAnimation;
	Animation* dieAnimation;
	Animation* jumpAnimation;
	Animation* kickAnimation;
	Animation* lookUpAnimation;
	Animation* moveAnimation;
	Animation* shieldlessAttackAnimation;
	Animation* sitAnimation;
	Animation* sitAttackAnimation;
	Animation* spinAnimation;
	Animation* standAnimation;


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

	Animation* getAttackAnimation() { return this->attackAnimation; }
	Animation* getDashAnimation() { return this->dashAnimation; }
	Animation* getDieAnimation() { return this->dieAnimation; }
	Animation* getJumpAnimation() { return this->jumpAnimation; }
	Animation* getKickAnimation() { return this->kickAnimation; }
	Animation* getLookUpAnimation() { return this->lookUpAnimation; }
	Animation* getMoveAnimation() { return this->moveAnimation; }
	Animation* getShieldlessAttackAnimation() { return this->shieldlessAttackAnimation; }
	Animation* getSitAnimation() { return this->sitAnimation; }
	Animation* getSitAttackAnimation() { return this->sitAttackAnimation; }
	Animation* getSpinAnimation() { return this->spinAnimation; }
	Animation* getStandAnimation() { return this->standAnimation; }


	
};

