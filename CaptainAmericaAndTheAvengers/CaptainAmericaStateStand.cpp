#include "stdafx.h"
#include "CaptainAmericaStateStand.h"
#include "CaptainAmericaStateManager.h"

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
}

void CaptainAmericaStateStand::setBoundCollision()
{
}

void CaptainAmericaStateStand::handleInput(float dt)
{
	/*if (input->iskeyup(vk_w)) {
		this->captainamerica->setstatus(estatus::stand);
		onexit();
		captainamericastatemanager::getinstance()->changestateto(estatus::stand);
		captainamericastatemanager::getinstance()->getcurrentstate()->onstart();
	}*/

	if (input->isKeyDown(VK_RIGHT)) {
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::MOVE);
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

