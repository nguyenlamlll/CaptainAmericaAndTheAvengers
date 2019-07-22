#pragma once
#include "Sprite.h"
#include "IndexManager.h"

#define TIME_FRAME_ITEM 0.1f

class BaseObject
{
protected:
	Sprite* sprite;
	eID id;
	eStatus status;
	eDirection direction;
	GameRect activeBound;
	GameRect boundCollision;
	VECTOR2 velocity;
	VECTOR2 accelerate;

	bool isActivity;

public:
	BaseObject(eID id);
	BaseObject();
	~BaseObject();

	virtual void setPositionInGrid();

	virtual void update(float dt);
	virtual void draw();

	eID getId();
	eStatus getStatus();
	virtual void setStatus(eStatus status);
	virtual bool isInStatus(eStatus status);

	eDirection getDirection();
	virtual void setDirection(eDirection direct);
	virtual bool isInDirection(eDirection direct);

	virtual VECTOR2 getPosition();
	virtual void setPosition(VECTOR2 position);
	virtual void setPosition(float x, float y);
	virtual void setPositionX(float x);
	virtual void setPositionY(float y);

	virtual VECTOR2 getScale();
	virtual void setScale(VECTOR2 scale);
	virtual void setScaleX(float scaleX);
	virtual void setScaleY(float scaleY);
	virtual void setAccelerate(VECTOR2 accelerate);
	virtual VECTOR2 getAccelerate();
	virtual VECTOR2 getOrigin();
	virtual void setOrigin(VECTOR2 origin);

	virtual float getRotate();
	virtual void setRotate(float rotate);

	Sprite* getSprite();

	//TO DO: update position, velocity... if this object collide with another object(call before update() )
	virtual void onCollision();

	virtual void onCollision(float dt);

	virtual void setBoundCollision(GameRect rect);
	virtual GameRect getBoundCollision();

	virtual void setFlipX(bool flipX) { sprite->setFlipX(flipX); }
	virtual void setFlipY(bool flipY) { sprite->setFlipY(flipY); }
	virtual VECTOR2 getVelocity();
	virtual void setVelocityX(float x);
	virtual void setVelocityY(float y);
	virtual void setVelocity(VECTOR2 velocity);

	virtual GameRect getActiveBound();
	virtual void setActiveBound(GameRect rect);

	virtual void setActivity(bool flag);
	virtual bool isActivitied();
};



struct CollisionReturn
{
	// top, left ,right ,bottom
	CollideDirection direction;
	//time two object collide
	float entryTime;
	//position of side that object collide. For example, when direction = TOP, it means positionCollision = otherBound.top
	float positionCollision;

	BaseObject* object;

	bool operator<(const CollisionReturn& collisionReturn) const
	{
		return this->entryTime < collisionReturn.entryTime;
	}
};
