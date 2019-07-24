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
#define CAPTAIN_VERLOCITY_X 100
#define CAPTAIN_VELOCITY_JUMP_X 70
#define CAPTAIN_VERLOCITY_Y 100
#define CAPTAIN_VELOCITY_JUMP_Y 70

#define WIDTH_COLLISION 10
#define HEIGHT_COLLISION 30

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

	bool moveRight;
	bool moveLeft;
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

	bool canMoveLeft();

	bool canMoveRight();

	bool isPressed();

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

