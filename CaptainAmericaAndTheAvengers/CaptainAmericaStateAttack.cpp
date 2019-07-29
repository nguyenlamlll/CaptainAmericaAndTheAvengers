#include "stdafx.h"
#include "CaptainAmericaStateAttack.h"
#include "CaptainAmericaStateManager.h"
#include "TextureManager.h"
#include "BulletPool.h"
CaptainAmericaStateAttack::CaptainAmericaStateAttack()
{
}


CaptainAmericaStateAttack::~CaptainAmericaStateAttack()
{
}

CaptainAmericaStateAttack::CaptainAmericaStateAttack(CaptainAmerica * captainAmerica, Input * input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getAttackAnimation();
	//init();
	animation->start();
}

void CaptainAmericaStateAttack::init()
{
	/*Bullet *bullet = BulletPool::getInstance()->getBullet();*/
	/*captainAmerica->setBullet(new Bullet(new TextureManager(), captainAmerica->getGraphics()));*/

}

void CaptainAmericaStateAttack::setBoundCollision()
{
}

void CaptainAmericaStateAttack::handleInput(float dt)
{
	if (input->isKeyUp(VK_Z)) {
		this->captainAmerica->setStatus(eStatus::STAND);
		CaptainAmericaStateManager::getInstance()->changeStateTo(eStatus::STAND);
		CaptainAmericaStateManager::getInstance()->getCurrentState()->onStart();
	}
}

void CaptainAmericaStateAttack::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateAttack::onStart()
{
	animation->start();
}

void CaptainAmericaStateAttack::onExit()
{
	animation->stop();
}

