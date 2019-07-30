#include "stdafx.h"
#include "SoldierBullet.h"
#include "Soldier.h"

SoldierBullet::SoldierBullet()
{
}


SoldierBullet::~SoldierBullet()
{
	delete sprite;
}

SoldierBullet::SoldierBullet(Graphics * graphics, TextureManager * textureM, Soldier * soldier)
	: BaseObject(eID::SOLDIER_BULLET)
{
	this->sprite = new Sprite();
	this->soldier = soldier;
	if (!this->sprite->initialize(graphics, textureM, SpriteManager::getInstance()))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Could not initialize sprite soldier bullet");
	}
	this->sprite->setData(IndexManager::getInstance()->soldierBullet);
	this->sprite->setOrigin(VECTOR2(0.5, 0.5));
	isActivity = false;

}

void SoldierBullet::init()
{
	this->setPosition(VECTOR2(soldier->getBoundCollision().right, soldier->getBoundCollision().top - 5.f));
	this->velocity = VECTOR2(-0.5f, 0);
	isCollided = false;
	isActivity = true;
	setBoundCollision();
}

void SoldierBullet::setBoundCollision()
{
	GameRect rect;
	VECTOR2 position(this->getPosition().x, this->getPosition().y);
	rect.left = position.x - this->sprite->getWidth() * 0.5f;
	rect.right = position.x + this->sprite->getWidth() * 0.5f;
	rect.top = position.y + this->sprite->getHeight() * 0.5f;
	rect.bottom = position.y - this->sprite->getHeight() * 0.5f;

	this->boundCollision = rect;
}

void SoldierBullet::onCollision(float dt)
{
}

void SoldierBullet::update(float dt)
{
	if (isActivity)
	{
		this->setPosition(VECTOR2(this->getPosition().x + this->velocity.x*dt, this->getPosition().y + this->velocity.y*dt));
		setBoundCollision();
	}
}

void SoldierBullet::draw()
{
	if (isActivity)
	{
		sprite->draw();
	}
}

