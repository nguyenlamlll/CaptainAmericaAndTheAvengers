
#pragma once
#include "BaseState.h"
class CaptainAmericaStateShieldlessAttack : public BaseState
{
public:
	CaptainAmericaStateShieldlessAttack();
	~CaptainAmericaStateShieldlessAttack();
	CaptainAmericaStateShieldlessAttack(CaptainAmerica* captainAmerica, Input* input);

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};


