#pragma once
#include "CaptainAmerica.h"
#include "Input.h"
#include "Animation.h"

class BaseState
{
protected:
	CaptainAmerica* captainAmerica;
	Input* input;
	Animation* animation;

public:
	BaseState();
	BaseState(CaptainAmerica* captainAmerica, Input* input);
	~BaseState();

	virtual void init() = 0;
	virtual void handleInput(float dt) = 0;
	virtual void update(float dt) = 0;

	virtual void onStart() = 0;
	virtual void onExit() = 0; // Call captainAmerica do anthing before exit state

	virtual void setBoundCollision();
	virtual void onCollision(float dt);

	virtual eStatus getName();

};

