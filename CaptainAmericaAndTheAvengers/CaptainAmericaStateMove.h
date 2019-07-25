#pragma once
#include "BaseState.h"
class CaptainAmericaStateMove : public BaseState
{
public:
	CaptainAmericaStateMove();
	~CaptainAmericaStateMove();
	CaptainAmericaStateMove(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);
	void onCollision(float dt);

	void onStart();
	void onExit();
};

#pragma once
