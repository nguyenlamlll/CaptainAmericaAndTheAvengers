#include "stdafx.h"
#include "CaptainAmericaStateDash.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateDash::CaptainAmericaStateDash()
{
}


CaptainAmericaStateDash::~CaptainAmericaStateDash()
{
}

CaptainAmericaStateDash::CaptainAmericaStateDash(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getDashAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateDash::init()
{
}

void CaptainAmericaStateDash::setBoundCollision()
{
}

void CaptainAmericaStateDash::handleInput(float dt)
{
	if (input->isKeyUp(VK_D)) {
		this->captainAmerica->setStatus(eStatus::STAND);
		this->captainAmerica->setVelocityX(0);

		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateDash::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateDash::onStart()
{
	animation->start();
}

void CaptainAmericaStateDash::onExit()
{
	animation->stop();
}

