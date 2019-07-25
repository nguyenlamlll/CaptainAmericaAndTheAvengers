#include "stdafx.h"
#include "CaptainAmericaStateJump.h"
#include "CaptainAmericaStateManager.h"
#include "CaptainAmerica.h"

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
	GameRect rect;
	VECTOR2 position(this->captainAmerica->getPosition().x, captainAmerica->getPosition().y);
	rect.left = position.x - JUMP_WIDTH * 0.5f;
	rect.right = position.x + JUMP_WIDTH * 0.5f;
	rect.top = position.y + JUMP_HEIGHT * 0.5f;
	rect.bottom = position.y - JUMP_HEIGHT * 0.5f;
	captainAmerica->setBoundCollision(rect);
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
		this->captainAmerica->setVelocityX(-CAPTAIN_VERLOCITY_X);

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
		this->captainAmerica->setVelocityX(CAPTAIN_VERLOCITY_X);
	}

	//if (input->isKeyUp(VK_RIGHT) || input->isKeyUp(VK_LEFT)) {
	//	this->captainAmerica->setVelocityX(0);
	//}

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
	if (this->captainAmerica->getPosition().y <= START_POS_Y) {
		this->captainAmerica->setPositionY(START_POS_Y);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
	animation->update(dt);
	setBoundCollision();
}

void CaptainAmericaStateJump::onCollision(float dt)
{
	float addX = 0, addY = 0;
	for (auto i = this->captainAmerica->getListCollide()->begin(); i != this->captainAmerica->getListCollide()->end(); i++)
	{
		switch (i->object->getId())
		{
		case eID::GROUND:
		{
			switch (i->direction)
			{
			case CollideDirection::LEFT:

				this->captainAmerica->setCanMoveRight(false);
				this->captainAmerica->setVelocityX(0);
				break;
			case CollideDirection::RIGHT:
				this->captainAmerica->setCanMoveLeft(false);
				this->captainAmerica->setVelocityX(0);
				break;
			case CollideDirection::TOP:
				//jumpDistance = 0;
				//set jump = false, when user release jump button set to true
				this->captainAmerica->setCanJump(false);
				//set fall to false
				this->captainAmerica->setIsFalling(false);
				//reset velocity
				this->captainAmerica->setVelocityY(0);
				//positionCollide = i->positionCollision;
				//if(this->samus->getStatus()!)
				this->captainAmerica->setStatus(eStatus::STAND);

				onExit();
				CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
				CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
				break;
			case CollideDirection::BOTTOM:
				//jumpDistance = 0;
				this->captainAmerica->setIsFalling(true);
				this->captainAmerica->setVelocityY(0);
				addY = i->positionCollision;

				this->captainAmerica->setPositionY(addY - OFFSET_JUMP);
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

void CaptainAmericaStateJump::onStart()
{
	animation->start();
}

void CaptainAmericaStateJump::onExit()
{
	animation->stop();
}

