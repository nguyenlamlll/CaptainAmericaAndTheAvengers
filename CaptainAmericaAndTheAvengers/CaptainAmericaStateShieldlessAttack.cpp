
#include "stdafx.h"
#include "CaptainAmericaStateShieldlessAttack.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateShieldlessAttack::CaptainAmericaStateShieldlessAttack()
{
}


CaptainAmericaStateShieldlessAttack::~CaptainAmericaStateShieldlessAttack()
{
}

CaptainAmericaStateShieldlessAttack::CaptainAmericaStateShieldlessAttack(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getShieldlessAttackAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateShieldlessAttack::init()
{
}

void CaptainAmericaStateShieldlessAttack::setBoundCollision()
{
}

void CaptainAmericaStateShieldlessAttack::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::SHILEDLESSATTACK);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SHILEDLESSATTACK);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateShieldlessAttack::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateShieldlessAttack::onStart()
{
	animation->start();
}

void CaptainAmericaStateShieldlessAttack::onExit()
{
	animation->stop();
}

