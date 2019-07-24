#include "stdafx.h"
#include "CaptainAmericaStateJump.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateJump::CaptainAmericaStateJump()
{
}


CaptainAmericaStateJump::~CaptainAmericaStateJump()
{
}

CaptainAmericaStateJump::CaptainAmericaStateJump(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getJumpAnimation();
	//init();
	animation->start();
}

void CaptainAmericaStateJump::init()
{
	if (CaptainAmericaStateManager::getInstance()->getOldStatus() != eStatus::SPIN && CaptainAmericaStateManager::getInstance()->getOldStatus() != eStatus::KICK) {
		captainAmerica->setVelocityY(300.0f);
	}
	captainAmerica->setAccelerate(VECTOR2(0, -10));
}

void CaptainAmericaStateJump::setBoundCollision()
{
}

void CaptainAmericaStateJump::handleInput(float dt)
{
	if (input->isKeyDown(VK_LEFT) && input->isKeyUp(VK_RIGHT))
	{

		if (this->captainAmerica->isInDirection(eDirection::left))
		{
			this->captainAmerica->setFlipX(false);
			//set direction to left
			this->captainAmerica->setDirection(eDirection::right);
		}
		this->captainAmerica->setVelocityX(-CAPTAIN_VERLOCITY_Y);

	}

	//handle press right button
	if (input->isKeyDown(VK_RIGHT) && input->isKeyUp(VK_LEFT))
	{

		if (this->captainAmerica->isInDirection(eDirection::right))
		{
			//flipX change to false to turn right
			this->captainAmerica->setFlipX(true);
			this->captainAmerica->setDirection(eDirection::left);

		}
		this->captainAmerica->setVelocityX(CAPTAIN_VERLOCITY_Y);
	}

	if (input->isKeyUp(VK_RIGHT) || input->isKeyUp(VK_LEFT)) {
		this->captainAmerica->setVelocityX(0);
	}

	if (input->isKeyDown(VK_X) && this->captainAmerica->getVelocity().y <= 0 && this->captainAmerica->getVelocity().y >= -20) {
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SPIN);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_Z))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::KICK);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	
}

void CaptainAmericaStateJump::update(float dt)
{
	if (this->captainAmerica->getPosition().y <= 1680) {
		this->captainAmerica->setPositionY(1680);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
	animation->update(dt);
}

void CaptainAmericaStateJump::onStart()
{
	animation->start();
}

void CaptainAmericaStateJump::onExit()
{
	animation->stop();
}

