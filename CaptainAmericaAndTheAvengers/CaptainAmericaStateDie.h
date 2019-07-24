#pragma once
#include "BaseState.h"
class CaptainAmericaStateDie : public BaseState
{
public:
	CaptainAmericaStateDie();
	~CaptainAmericaStateDie();
	CaptainAmericaStateDie(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
