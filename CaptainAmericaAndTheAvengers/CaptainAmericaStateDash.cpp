#include "stdafx.h"
#include "CaptainAmericaStateDash.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateDash::CaptainAmericaStateDash()
{
}


CaptainAmericaStateDash::~CaptainAmericaStateDash()
{
}

CaptainAmericaStateDash::CaptainAmericaStateDash(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getDashAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateDash::init()
{
}

void CaptainAmericaStateDash::setBoundCollision()
{
}

void CaptainAmericaStateDash::handleInput(float dt)
{
	if (input->isKeyUp(VK_D)) {
		if (input->isKeyDown(VK_LEFT) && input->isKeyUp(VK_RIGHT))
		{

			if (this->captainAmerica->isInDirection(eDirection::left))
			{
				this->captainAmerica->setFlipX(false);
				//set direction to left
				this->captainAmerica->setDirection(eDirection::right);
			}
			this->captainAmerica->setStatus(eStatus::STAND);
			this->captainAmerica->setVelocityX(0);

			CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
			CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
		}
		
		if (input->isKeyDown(VK_RIGHT) && input->isKeyUp(VK_LEFT))
		{

			if (this->captainAmerica->isInDirection(eDirection::right))
			{
				this->captainAmerica->setFlipX(false);
				//set direction to left
				this->captainAmerica->setDirection(eDirection::left);
			}
			this->captainAmerica->setStatus(eStatus::STAND);
			this->captainAmerica->setVelocityX(0);

			CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
			CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
		}
	}
}

void CaptainAmericaStateDash::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateDash::onStart()
{
	animation->start();
}

void CaptainAmericaStateDash::onExit()
{
	animation->stop();
}

