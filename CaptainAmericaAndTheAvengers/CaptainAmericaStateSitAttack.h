
#pragma once
#include "BaseState.h"
class CaptainAmericaStateSitAttack : public BaseState
{
public:
	CaptainAmericaStateSitAttack();
	~CaptainAmericaStateSitAttack();
	CaptainAmericaStateSitAttack(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
