#pragma once
#include "BaseState.h"
class CaptainAmericaStateDash : public BaseState
{
public:
	CaptainAmericaStateDash();
	~CaptainAmericaStateDash();
	CaptainAmericaStateDash(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

