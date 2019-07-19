#pragma once
#include "BaseState.h"
class CaptainAmericaStateJump : public BaseState
{
public:
	CaptainAmericaStateJump();
	~CaptainAmericaStateJump();
	CaptainAmericaStateJump(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

