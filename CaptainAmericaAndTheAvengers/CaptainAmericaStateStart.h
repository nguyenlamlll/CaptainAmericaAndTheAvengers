#pragma once
#include "BaseState.h"
class CaptainAmericaStateStart : public BaseState
{
public:
	CaptainAmericaStateStart();
	CaptainAmericaStateStart(CaptainAmerica*, Input*);
	~CaptainAmericaStateStart();

	void init();
	void setBoundCollision();

	void handleInput(float dt);
	void update(float dt);

	void onStart();
	void onExit();
};

