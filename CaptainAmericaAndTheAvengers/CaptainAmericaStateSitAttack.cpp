
#include "stdafx.h"
#include "CaptainAmericaStateSitAttack.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateSitAttack::CaptainAmericaStateSitAttack()
{
}


CaptainAmericaStateSitAttack::~CaptainAmericaStateSitAttack()
{
}

CaptainAmericaStateSitAttack::CaptainAmericaStateSitAttack(CaptainAmerica * captainAmerica, Input * input)
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
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::SITATTACK);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SITATTACK);
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

