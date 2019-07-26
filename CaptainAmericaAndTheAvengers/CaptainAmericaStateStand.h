#pragma once
#include "BaseState.h"
class CaptainAmericaStateStand : public BaseState
{
private:
	float timerToRunning;
public:
	CaptainAmericaStateStand();
	~CaptainAmericaStateStand();
	CaptainAmericaStateStand(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);
	void onCollision(float dt);

	void onStart();
	void onExit();
};

#pragma once
