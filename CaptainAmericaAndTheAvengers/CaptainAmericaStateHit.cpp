#include "stdafx.h"
#include "CaptainAmericaStateHit.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateHit::CaptainAmericaStateHit()
{
}


CaptainAmericaStateHit::~CaptainAmericaStateHit()
{
}

CaptainAmericaStateHit::CaptainAmericaStateHit(CaptainAmerica * captainAmerica, Input * input) 
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getHitAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateHit::init()
{
}

void CaptainAmericaStateHit::setBoundCollision()
{
}

void CaptainAmericaStateHit::handleInput(float dt)
{
	if (input->isKeyUp(VK_J)) {
		this->captainAmerica->setStatus(eStatus::START);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::START);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateHit::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateHit::onStart()
{
	animation->start();
}

void CaptainAmericaStateHit::onExit()
{
	animation->stop();
}
