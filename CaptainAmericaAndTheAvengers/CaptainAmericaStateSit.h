
#pragma once
#include "BaseState.h"
class CaptainAmericaStateSit : public BaseState
{
public:
	CaptainAmericaStateSit();
	~CaptainAmericaStateSit();
	CaptainAmericaStateSit(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
