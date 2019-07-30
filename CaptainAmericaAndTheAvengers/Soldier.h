#pragma once
#include "BaseObject.h"
#include "Animation.h"
#include "SoldierBullet.h"

class Soldier : public BaseObject
{
private:
	float timer;
	Animation* moveAnimation;
	
	SoldierBullet* bullet;
	bool isFired;

public:
	Soldier();
	Soldier(TextureManager* textureM, Graphics* graphics);
	~Soldier();

	void setBoundCollision();
	void onCollision(float dt);

	void update(float dt);
	void draw();
};

