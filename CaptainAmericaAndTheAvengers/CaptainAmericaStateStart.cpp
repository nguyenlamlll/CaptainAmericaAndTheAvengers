#include "stdafx.h"
#include "CaptainAmericaStateStart.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateStart::CaptainAmericaStateStart()
{
}

CaptainAmericaStateStart::CaptainAmericaStateStart(CaptainAmerica* captainAmerica, Input* input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getStartAnimation();
	init();
	animation->start();
}


CaptainAmericaStateStart::~CaptainAmericaStateStart()
{
}

void CaptainAmericaStateStart::init()
{
}

void CaptainAmericaStateStart::setBoundCollision()
{
}

void CaptainAmericaStateStart::handleInput(float dt)
{
	//if (animation->isFinished()) {
	//	if (input->isKeyDown(VK_RIGHT) || input->isKeyDown(VK_LEFT))
	//	{
	//		//MetroidRect bound = samus->getBoundCollision();
	//		if (input->isKeyDown(VK_RIGHT) && input->isKeyUp(VK_LEFT))
	//		{
	//			//samus->setDirection(eDirection::right);
	//		}
	//		if (input->isKeyDown(VK_LEFT) && input->isKeyUp(VK_RIGHT))
	//		{
	//			//this->samus->setFlipX(true);
	//			////set direction to left
	//			//this->samus->setDirection(eDirection::left);
	//		}
	//		this->captainAmerica->setStatus(eStatus::MOVE);
	//		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
	//	}

	if (input->isKeyDown(VK_D)) {
		this->captainAmerica->setStatus(eStatus::MOVE);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
	}
}

void CaptainAmericaStateStart::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateStart::onStart()
{
}

void CaptainAmericaStateStart::onExit()
{
	animation->stop();
}
