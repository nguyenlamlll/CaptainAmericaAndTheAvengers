#include "stdafx.h"
#include "CaptainAmericaStateMove.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateMove::CaptainAmericaStateMove()
{
}


CaptainAmericaStateMove::~CaptainAmericaStateMove()
{
}

CaptainAmericaStateMove::CaptainAmericaStateMove(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getMoveAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateMove::init()
{
}

void CaptainAmericaStateMove::setBoundCollision()
{
}

void CaptainAmericaStateMove::handleInput(float dt)
{
	/*if (input->isKeyUp(VK_A)) {
		this->captainAmerica->setStatus(eStatus::MOVE);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}*/

	if (input->isKeyUp(VK_LEFT) || input->isKeyUp(VK_RIGHT))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
		this->captainAmerica->setVelocityX(0);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateMove::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateMove::onStart()
{
	animation->start();
}

void CaptainAmericaStateMove::onExit()
{
	animation->stop();
}

