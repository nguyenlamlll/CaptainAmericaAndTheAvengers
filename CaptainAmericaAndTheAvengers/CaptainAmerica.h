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

#define JUMP_HEIGHT 24
#define JUMP_WIDTH 10

#define OFFSET_JUMP 11

// Start position
#define START_POS_X 240	
#define START_POS_Y 2131

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

	list<CollisionReturn> *listCollide;
	map<int, BaseObject*>* listCanCollide;
	map<int, BaseObject*>* listWallCanCollide;

public:
	CaptainAmerica();
	CaptainAmerica(TextureManager* textureM, Graphics* graphics, Input* input);
	~CaptainAmerica();

	void handleInput(float dt);
	void onCollision(float dt);

	void update(float dt);
	void draw();
	void drawIndicators();
	void release();

	//bool isPressed();

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

	list<CollisionReturn>* getListCollide() { return listCollide; }
	//void setListCollide(list<CollisionReturn>* list) { this->listCollide = list; }

	map<int, BaseObject*>* getListCanCollide() { return listCanCollide; }
	void setListCanCollide(map<int, BaseObject*>* list) { this->listCanCollide = list; }

	map<int, BaseObject*>* getListWallCanCollide() { return listWallCanCollide; }
	void setListWallCanCollide(map<int, BaseObject*>* list) { this->listWallCanCollide = list; }

#pragma region Moveable Directions & Actions

private:
	bool canMoveRight;
	bool canMoveLeft;
	bool isFalling;
	bool canJump;
public:
	void setCanJump(bool value) { canJump = value; }
	bool getCanJump() { return canJump; }
	
	void setCanMoveLeft(bool value) { canMoveLeft = value; }
	bool getCanMoveLeft() { return canMoveLeft; }

	void setCanMoveRight(bool value) { canMoveRight = value; }
	bool getCanMoveRight() { return canMoveRight; }

	void setIsFalling(bool value) { isFalling = value; }
	bool getIsFalling() { return isFalling; }

#pragma endregion
	
};

