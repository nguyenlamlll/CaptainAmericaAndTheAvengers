#include "stdafx.h"
#include "CaptainAmericaStateAttack.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateAttack::CaptainAmericaStateAttack()
{
}


CaptainAmericaStateAttack::~CaptainAmericaStateAttack()
{
}

CaptainAmericaStateAttack::CaptainAmericaStateAttack(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getAttackAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateAttack::init()
{
}

void CaptainAmericaStateAttack::setBoundCollision()
{
}

void CaptainAmericaStateAttack::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::ATTACK);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::ATTACK);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateAttack::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateAttack::onStart()
{
	animation->start();
}

void CaptainAmericaStateAttack::onExit()
{
	animation->stop();
}

