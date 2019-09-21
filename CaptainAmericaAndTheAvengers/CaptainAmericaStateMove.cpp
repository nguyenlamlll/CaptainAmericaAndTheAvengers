#include "stdafx.h"
#include "CaptainAmericaStateMove.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateMove::CaptainAmericaStateMove()
{
}


CaptainAmericaStateMove::~CaptainAmericaStateMove()
{
}

CaptainAmericaStateMove::CaptainAmericaStateMove(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getMoveAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateMove::init()
{
}

void CaptainAmericaStateMove::setBoundCollision()
{
	GameRect rect;
	VECTOR2 position(this->captainAmerica->getPosition().x, captainAmerica->getPosition().y - OFFSET_COLLISION_Y + 1);
	rect.left = position.x - WIDTH_COLLISION;
	rect.right = position.x + WIDTH_COLLISION;
	rect.top = position.y + HEIGHT_COLLISION;
	rect.bottom = position.y - HEIGHT_COLLISION;
	captainAmerica->setBoundCollision(rect);
}

void CaptainAmericaStateMove::handleInput(float dt)
{

	if (input->isKeyUp(VK_LEFT) && input->isKeyUp(VK_RIGHT))
	{
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
		this->captainAmerica->setVelocityX(0);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateMove::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateMove::onCollision(float dt)
{
	GameRect bound;
	for (auto i = this->captainAmerica->getListCollide()->begin(); i != this->captainAmerica->getListCollide()->end(); i++)
	{
		switch (i->object->getId())
		{
		case eID::GROUND:
		{
			switch (i->direction)
			{
			case CollideDirection::LEFT:
				if (this->captainAmerica->getBoundCollision().bottom < i->object->getBoundCollision().top)
				{
					this->captainAmerica->setVelocityX(0);
					this->captainAmerica->setCanMoveRight(false);
					this->captainAmerica->setStatus(eStatus::STAND);
				}
				break;
			case CollideDirection::RIGHT:

				if (this->captainAmerica->getBoundCollision().bottom < i->object->getBoundCollision().top)
				{
					this->captainAmerica->setVelocityX(0);
					this->captainAmerica->setCanMoveLeft(false);
					this->captainAmerica->setStatus(eStatus::STAND);
				}
				break;
			case CollideDirection::TOP:
				this->captainAmerica->setIsFalling(false);
				//this->samus->setPositionY()
				this->captainAmerica->setPositionY(i->positionCollision + OFFSET_STAND);
				this->captainAmerica->setVelocityY(0);
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

void CaptainAmericaStateMove::onStart()
{
	animation->start();
}

void CaptainAmericaStateMove::onExit()
{
	animation->stop();
}

