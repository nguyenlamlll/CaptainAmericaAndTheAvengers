#pragma once
#include "BaseState.h"
class CaptainAmericaStateSpin : public BaseState
{
public:
	CaptainAmericaStateSpin();
	CaptainAmericaStateSpin(CaptainAmerica* captainAmerica, Input* input);
	~CaptainAmericaStateSpin();

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

