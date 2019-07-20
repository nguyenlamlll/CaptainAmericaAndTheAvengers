#pragma once
#include "BaseState.h"
class CaptainAmericaStateKick : public BaseState
{
public:
	CaptainAmericaStateKick();
	~CaptainAmericaStateKick();
	CaptainAmericaStateKick(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
