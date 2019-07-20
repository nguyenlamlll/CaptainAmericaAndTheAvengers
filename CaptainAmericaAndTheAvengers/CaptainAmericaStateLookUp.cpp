#include "stdafx.h"
#include "CaptainAmericaStateLookUp.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateLookUp::CaptainAmericaStateLookUp()
{
}


CaptainAmericaStateLookUp::~CaptainAmericaStateLookUp()
{
}

CaptainAmericaStateLookUp::CaptainAmericaStateLookUp(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getLookUpAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateLookUp::init()
{
}

void CaptainAmericaStateLookUp::setBoundCollision()
{
}

void CaptainAmericaStateLookUp::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::LOOKUP);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::LOOKUP);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateLookUp::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateLookUp::onStart()
{
	animation->start();
}

void CaptainAmericaStateLookUp::onExit()
{
	animation->stop();
}

