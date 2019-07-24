#pragma once
#include "BaseState.h"
class CaptainAmericaStateLookUp : public BaseState
{
public:
	CaptainAmericaStateLookUp();
	~CaptainAmericaStateLookUp();
	CaptainAmericaStateLookUp(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
