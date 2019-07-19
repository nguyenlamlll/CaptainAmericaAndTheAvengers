#include "stdafx.h"
#include "CaptainAmericaStateSpin.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateSpin::CaptainAmericaStateSpin()
{
}

CaptainAmericaStateSpin::CaptainAmericaStateSpin(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getSpinAnimation();
	init();
	animation->start();
}


CaptainAmericaStateSpin::~CaptainAmericaStateSpin()
{
}

void CaptainAmericaStateSpin::init()
{
}

void CaptainAmericaStateSpin::setBoundCollision()
{
}

void CaptainAmericaStateSpin::handleInput(float dt)
{

	if (input->isKeyUp(VK_X)) {
		this->captainAmerica->setStatus(eStatus::START);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::START);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateSpin::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateSpin::onStart()
{
	animation->start();
}

void CaptainAmericaStateSpin::onExit()
{
	animation->stop();
}
