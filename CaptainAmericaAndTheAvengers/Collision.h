#pragma once
#include "Constants.h"
#include "BaseObject.h"
#include "CaptainAmerica.h"

class Collision
{
private: 
	static Collision* instance;
public:
	static Collision * getInstance();

	Collision();
	~Collision();

	// Return true if the two rectangles are colliding with each other.
	bool isColliding(GameRect myRect, GameRect otherRect);


	//Return true if one object will collide with another
	bool willCollide(BaseObject* myObj, BaseObject* otherObj, float dt);
	bool willCollide(BaseObject* myObj, BaseObject* otherObj, float dt, CollisionReturn& result);

	//bool willCollide(BaseObject* myObj, CaptainAmerica* captainAmerica, float dt);

	//TO DO: calculate collision rect
	//GameRect CalculateCollisionRect(GameRect rect1, GameRect rect2);

	//GameRect getSweptBroadphaseRect(GameRect myRect, VECTOR2 myVelocity, float frametime);

	GameRect getSweptBroadphaseRect(BaseObject* entity, float frametime);

	void release();
};

