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
	//		//GameRect bound = samus->getBoundCollision();
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

	if (input->isKeyDown(VK_W)) {
		this->captainAmerica->setStatus(eStatus::JUMP);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::JUMP);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_J)) {
		this->captainAmerica->setStatus(eStatus::HIT);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::HIT);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_X)) {
		this->captainAmerica->setStatus(eStatus::SPIN);
		onExit();
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SPIN);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}

	if (input->isKeyDown(VK_S) && input->isKeyDown(VK_J)) {
		this->captainAmerica->setStatus(eStatus::SITATTACK);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::SITATTACK);
	}
}

void CaptainAmericaStateStart::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateStart::onStart()
{
	animation->start();
}

void CaptainAmericaStateStart::onExit()
{
	animation->stop();
}
