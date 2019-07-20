#pragma once
#include "BaseState.h"
class CaptainAmericaStateAttack : public BaseState
{
public:
	CaptainAmericaStateAttack();
	~CaptainAmericaStateAttack();
	CaptainAmericaStateAttack(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

#pragma once
