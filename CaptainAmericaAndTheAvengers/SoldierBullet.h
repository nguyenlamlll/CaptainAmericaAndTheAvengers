#pragma once
#include "BaseObject.h"

class Soldier;
class SoldierBullet : public BaseObject
{
private:
	Soldier* soldier;
	bool isCollided;

	int damage;

public:
	SoldierBullet();
	~SoldierBullet();
	SoldierBullet(Graphics* graphics, TextureManager* textureM, Soldier* soldier);

	void init();

	bool getCollided() { return isCollided; }
	void setCollided(bool value) { this->isCollided = value; }

	void setBoundCollision();

	void onCollision(float dt);
	void update(float dt);
	void draw();
};

