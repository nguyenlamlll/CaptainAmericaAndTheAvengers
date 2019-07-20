#include "stdafx.h"
#include "CaptainAmericaStateSit.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateSit::CaptainAmericaStateSit()
{
}


CaptainAmericaStateSit::~CaptainAmericaStateSit()
{
}

CaptainAmericaStateSit::CaptainAmericaStateSit(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getSitAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateSit::init()
{
}

void CaptainAmericaStateSit::setBoundCollision()
{
}

void CaptainAmericaStateSit::handleInput(float dt)
{
	if (input->isKeyUp(VK_W)) {
		this->captainAmerica->setStatus(eStatus::SIT);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SIT);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateSit::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateSit::onStart()
{
	animation->start();
}

void CaptainAmericaStateSit::onExit()
{
	animation->stop();
}
