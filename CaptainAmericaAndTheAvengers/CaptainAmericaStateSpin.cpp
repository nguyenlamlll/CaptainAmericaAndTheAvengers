#include "stdafx.h"
#include "CaptainAmericaStateSpin.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateSpin::CaptainAmericaStateSpin()
{
}


CaptainAmericaStateSpin::~CaptainAmericaStateSpin()
{
}

CaptainAmericaStateSpin::CaptainAmericaStateSpin(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getSpinAnimation();
	//init();
	animation->start();
}

void CaptainAmericaStateSpin::init()
{
	captainAmerica->setVelocityY(200.0f);
	captainAmerica->setAccelerate(VECTOR2(0, -10));
}

void CaptainAmericaStateSpin::setBoundCollision()
{
}

void CaptainAmericaStateSpin::handleInput(float dt)
{
	/*if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::SPIN);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SPIN);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}*/
}

void CaptainAmericaStateSpin::update(float dt)
{
	if (this->captainAmerica->getVelocity().y <= -200) {
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::JUMP);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
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

