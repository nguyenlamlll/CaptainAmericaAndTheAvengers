#include "stdafx.h"
#include "CaptainAmericaStateDie.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateDie::CaptainAmericaStateDie()
{
}


CaptainAmericaStateDie::~CaptainAmericaStateDie()
{
}

CaptainAmericaStateDie::CaptainAmericaStateDie(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getDieAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateDie::init()
{
}

void CaptainAmericaStateDie::setBoundCollision()
{
}

void CaptainAmericaStateDie::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::DIE);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::DIE);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateDie::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateDie::onStart()
{
	animation->start();
}

void CaptainAmericaStateDie::onExit()
{
	animation->stop();
}

