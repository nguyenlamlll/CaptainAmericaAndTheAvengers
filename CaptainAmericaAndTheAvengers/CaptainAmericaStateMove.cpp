#include "stdafx.h"
#include "CaptainAmericaStateMove.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateMove::CaptainAmericaStateMove()
{
}


CaptainAmericaStateMove::~CaptainAmericaStateMove()
{
}

CaptainAmericaStateMove::CaptainAmericaStateMove(CaptainAmerica* captainAmerica, Input* input)
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
	if (input->isKeyDown(VK_A)) {
		this->captainAmerica->setStatus(eStatus::START);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::START);
	}

	if (input->isKeyDown(VK_S) && input->isKeyDown(VK_J)) {
		this->captainAmerica->setStatus(eStatus::SITATTACK);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SITATTACK);
	}

	if (input->isKeyUp(VK_D)) {
		this->captainAmerica->setStatus(eStatus::START);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::START);
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
