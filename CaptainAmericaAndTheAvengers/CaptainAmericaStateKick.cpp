#include "stdafx.h"
#include "CaptainAmericaStateKick.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateKick::CaptainAmericaStateKick()
{
}


CaptainAmericaStateKick::~CaptainAmericaStateKick()
{
}

CaptainAmericaStateKick::CaptainAmericaStateKick(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getKickAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateKick::init()
{
}

void CaptainAmericaStateKick::setBoundCollision()
{
}

void CaptainAmericaStateKick::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::KICK);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::KICK);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateKick::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateKick::onStart()
{
	animation->start();
}

void CaptainAmericaStateKick::onExit()
{
	animation->stop();
}

