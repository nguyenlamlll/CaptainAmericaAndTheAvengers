#include "stdafx.h"
#include "CaptainAmericaStateStand.h"
#include "CaptainAmericaStateManager.h"
#define TIME_TO_NORMAL 0.1f

CaptainAmericaStateStand::CaptainAmericaStateStand()
{
}


CaptainAmericaStateStand::~CaptainAmericaStateStand()
{
}

CaptainAmericaStateStand::CaptainAmericaStateStand(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getStandAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateStand::init()
{
	this->captainAmerica->setVelocity(VECTOR2(0, 0));
	this->captainAmerica->setAccelerate(VECTOR2(0, 0));
}

void CaptainAmericaStateStand::setBoundCollision()
{
}

void CaptainAmericaStateStand::handleInput(float dt)
{
	if (input->isKeyDown(VK_D))
	{

		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::DASH);
		this->captainAmerica->setVelocityX(100);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}


	if (input->isKeyDown(VK_LEFT) && input->isKeyUp(VK_RIGHT))
	{
		
		if (this->captainAmerica->isInDirection(eDirection::left))
		{
			this->captainAmerica->setFlipX(false);
			//set direction to left
			this->captainAmerica->setDirection(eDirection::right);
		}
		
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
		this->captainAmerica->setVelocityX(-100);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
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
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
		this->captainAmerica->setVelocityX(100);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_UP))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::LOOKUP);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
	if (input->isKeyDown(VK_DOWN))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SIT);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_X))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::JUMP);
		this->captainAmerica->setVelocityX(0);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_Z))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::ATTACK);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_D))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::DASH);
		this->captainAmerica->setVelocityX(100);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateStand::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateStand::onStart()
{
	animation->start();
}

void CaptainAmericaStateStand::onExit()
{
	animation->stop();
}

