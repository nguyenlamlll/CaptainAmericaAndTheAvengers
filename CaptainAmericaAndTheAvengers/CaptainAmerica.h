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

#define CAPTAIN_MIN_SPEED_Y 70
#define CAPTAIN_VERLOCITY_X 100
#define ACELERATE 70
#define CAPTAIN_MAX_SPEED_Y 170
#define CAPTAIN_V0_FALL_Y -60
#define CAPTAIN_VELOCITY_JUMP_X 70

#define MIN_JUMP  32.0f
#define MAX_JUMP 94.0f

#define OFFSET_STAND 19
#define WIDTH_COLLISION 10
#define HEIGHT_COLLISION 30
#define OFFSET_COLLISION_X 0
#define OFFSET_COLLISION_Y 4
#define OFFSET_ROLLING 6.0f

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

