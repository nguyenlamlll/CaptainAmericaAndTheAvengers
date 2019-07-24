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
	GameRect rect;
	VECTOR2 position(this->captainAmerica->getPosition().x, captainAmerica->getPosition().y - OFFSET_COLLISION_Y + 1);
	rect.left = position.x - WIDTH_COLLISION * 0.5f;
	rect.right = position.x + WIDTH_COLLISION * 0.5f;
	rect.top = position.y + HEIGHT_COLLISION * 0.5f;
	rect.bottom = position.y - HEIGHT_COLLISION * 0.5f;
	captainAmerica->setBoundCollision(rect);
}

void CaptainAmericaStateStand::handleInput(float dt)
{
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
		if (input->isKeyDown(VK_RIGHT))
		{
			this->captainAmerica->setVelocityX(100);
			CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::DASH);
			CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
		}
			
		else if(input->isKeyDown(VK_LEFT))
		{
			this->captainAmerica->setVelocityX(-100);
			CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::DASH);
			CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
		}
		
	}
}

void CaptainAmericaStateStand::update(float dt)
{
	setBoundCollision();

	animation->update(dt);
}

void CaptainAmericaStateStand::onCollision(float dt)
{
	for (auto i = this->captainAmerica->getListCollide()->begin(); i != this->captainAmerica->getListCollide()->end(); i++) 
	{
		switch (i->object->getId())
		{
		case eID::GROUND:
		{
			switch (i->direction)
			{
			case CollideDirection::TOP:
				this->captainAmerica->setVelocityY(0);
				this->captainAmerica->setPositionY(i->positionCollision + OFFSET_STAND);

				//canRolling = true;
				break;

			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void CaptainAmericaStateStand::onStart()
{
	animation->start();
}

void CaptainAmericaStateStand::onExit()
{
	animation->stop();
}

