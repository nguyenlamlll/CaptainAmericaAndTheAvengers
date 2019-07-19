#include "stdafx.h"
#include "CaptainAmericaStateJump.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateJump::CaptainAmericaStateJump()
{
}


CaptainAmericaStateJump::~CaptainAmericaStateJump()
{
}

CaptainAmericaStateJump::CaptainAmericaStateJump(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getJumpAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateJump::init()
{
}

void CaptainAmericaStateJump::setBoundCollision()
{
}

void CaptainAmericaStateJump::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::START);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::START);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateJump::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateJump::onStart()
{
	animation->start();
}

void CaptainAmericaStateJump::onExit()
{
	animation->stop();
}

