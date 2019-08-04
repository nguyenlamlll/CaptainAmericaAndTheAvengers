#pragma once
#include "BaseObject.h"
#include "Animation.h"
#include <list>

#define DISTANCE_MAX 70
#define VELOCITY_BULLET 180
#define EXPLOSION_TIME_FRAME_DELAY 0.1f
#define WIDTH_BULLET_HALF 1
#define HEIGHT_BULLET_HALF 1

class Bullet : public BaseObject
{
private:
	float distance;
	float distanceMax;
	
	list<CollisionReturn> *listCollide;
	bool isCollided;
	float timer;

	Animation* anim;

	float dame;

	int indexSprite;
	int indexEffect;
	bool isBack;
	bool isFly;
public:
	Bullet(TextureManager* textureM, Graphics* graphics);
	Bullet();
	~Bullet();

	void handleVelocity(float dt);
	void update(float dt);
	void draw();

	void onCollision();

	void setBoundCollision();
	void init(VECTOR2 stPosition);

	// Use object pool
	void returnPool();

	list<CollisionReturn> *getListCollide();

	float getDistanceMax();
	void setDistanceMax(float distan);
	void setDistance(float distan) { distance = distan; }

	void setIceBullet();

	void setFly(bool fly) { isFly = fly; }
	void setBack(bool back) {isBack = back;}
	bool getFly() { return isFly; }
	bool getBack() { return isBack; }
};

