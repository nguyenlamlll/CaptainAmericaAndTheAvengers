#include "stdafx.h"
#include "CaptainAmericaStateSitAttack.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateSitAttack::CaptainAmericaStateSitAttack()
{
}


CaptainAmericaStateSitAttack::~CaptainAmericaStateSitAttack()
{
}

CaptainAmericaStateSitAttack::CaptainAmericaStateSitAttack(CaptainAmerica* captainAmerica, Input* input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getSitAttackAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateSitAttack::init()
{
}

void CaptainAmericaStateSitAttack::setBoundCollision()
{
}

void CaptainAmericaStateSitAttack::handleInput(float dt)
{
	if (input->isKeyDown(VK_D)) {
		this->captainAmerica->setStatus(eStatus::MOVE);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
	if (input->isKeyUp(VK_S) && input->isKeyUp(VK_J)) {
		this->captainAmerica->setStatus(eStatus::START);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::START);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateSitAttack::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateSitAttack::onStart()
{
	animation->start();
}

void CaptainAmericaStateSitAttack::onExit()
{
	animation->stop();
}
