#include "stdafx.h"
#include "Soldier.h"


Soldier::Soldier()
{
}

Soldier::Soldier(TextureManager * textureM, Graphics * graphics)
	: BaseObject(eID::SOLDIER)
{
	this->sprite = new Sprite();
	if (!this->sprite->initialize(graphics, textureM, SpriteManager::getInstance()))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Could not initialize sprite Soldier.");
	}
	this->sprite->setData(IndexManager::getInstance()->soldierStand);
	this->getSprite()->setOrigin(VECTOR2(0.5, 0.5));

	moveAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->soldierMove,
		3,
		0.2f
	);

	bullet = new SoldierBullet(graphics, textureM, this);
}


Soldier::~Soldier()
{
}

void Soldier::setBoundCollision()
{
	GameRect rect;
	VECTOR2 position(this->getPosition().x, this->getPosition().y);
	rect.left = position.x - this->getSprite()->getWidth() * 0.5f;
	rect.right = position.x + this->getSprite()->getWidth() * 0.5f;
	rect.top = position.y + this->getSprite()->getHeight() * 0.5f;
	rect.bottom = position.y - this->getSprite()->getHeight() * 0.5f;

	this->boundCollision = rect;
}

void Soldier::onCollision(float dt)
{

}

// Cycle from: --> Move --> Stand --> Shoot --> 
#define TIME_DELAY_TO_MOVE 3.f
#define TIME_DELAY_TO_STAND 5.f
#define TIME_DELAY_TO_SHOOT 5.5f
void Soldier::update(float dt)
{
	timer += dt;
	if (timer >= 0 && timer < TIME_DELAY_TO_MOVE)
	{
		this->sprite->setData(IndexManager::getInstance()->soldierStand);
	}
	if (timer >= TIME_DELAY_TO_MOVE)
	{
		//timer = 0;

		moveAnimation->start();
		moveAnimation->update(dt);
		this->setPositionX(this->getPosition().x - 1.f);
	}
	if (timer >= TIME_DELAY_TO_STAND)
	{
		moveAnimation->stop();
		this->sprite->setData(IndexManager::getInstance()->soldierStand);
	}
	if (timer >= TIME_DELAY_TO_SHOOT)
	{
		timer = 0;
		// Shooting...
		if (!isFired)
		{
			this->bullet->init();
			isFired = true;
		}
	}
}

void Soldier::draw()
{
	this->sprite->draw();
	this->bullet->draw();
}
