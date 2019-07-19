#pragma once
#include "BaseState.h"
class CaptainAmericaStateHit : public BaseState
{
public:
	CaptainAmericaStateHit();
	~CaptainAmericaStateHit();
	CaptainAmericaStateHit(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

