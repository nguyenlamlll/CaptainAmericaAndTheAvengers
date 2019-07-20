#pragma once
#include "BaseState.h"
class CaptainAmericaStateStand : public BaseState
{
public:
	CaptainAmericaStateStand();
	~CaptainAmericaStateStand();
	CaptainAmericaStateStand(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
