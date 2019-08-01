#include "stdafx.h"
#include "Bullet.h"
#include "BulletPool.h"
#include "Collision.h"




Bullet::Bullet(TextureManager * textureM, Graphics * graphics) : BaseObject(eID::BULLET)
{
	this->sprite = new Sprite();
	if (!this->sprite->initialize(graphics, textureM, SpriteManager::getInstance()))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not init sprite Bullet");
	}

	anim = new Animation(
		sprite,
		IndexManager::getInstance()->captainBullet,
		3,
		0.1f
	);
	this->anim->start();
	this->indexSprite = IndexManager::getInstance()->captainBullet[1];
	//this->indexEffect = IndexManager::getInstance()->samusYellowBulletNormalColliding;
	// Set Data for sprite
	this->sprite->setData(indexSprite);
	this->setOrigin(VECTOR2(0.5f, 0.5f));
	
	this->setPosition(700,700);
	this->setStatus(eStatus::STAND);

	this->distance = 0;
	this->isCollided = false;
	this->timer = 0;
	this->isBack = false;
	this->isFly = false;
	//this->listCollide = new list<CollisionReturn>();


	this->dame = 1; // se setup lai sau

	this->distanceMax = DISTANCE_MAX;
}

Bullet::Bullet()
{

}


Bullet::~Bullet()
{
	delete this->sprite;
	delete this->listCollide;
}

void Bullet::onCollision()
{
	
}


void Bullet::handleVelocity(float dt)
{

	if (this->distance < this->distanceMax)
	{
		this->distance += VELOCITY_BULLET * dt;

		setBoundCollision();
	}
	else
	{
		//BulletPool::getInstance()->returnPool(this);
	}

}

void Bullet::update(float dt)
{
	/*if (this->isCollided)
	{
		timer += dt;
		if (timer > 0.1)
		{
			BulletPool::getInstance()->returnPool(this);
		}
	}*/
	float vx = this->getVelocity().x;

	if (!this->isBack) {
		this->distance += abs(vx*dt);
	}
	if (this->distance >= this->distanceMax && this->isBack == false) {
		this->setVelocityX(-vx);
		this->isBack = true;
	}

	this->setPosition(this->getPosition().x - this->getVelocity().x*dt, this->getPosition().y + this->getVelocity().y*dt);
}

void Bullet::draw()
{
	this->sprite->draw();
}

void Bullet::setBoundCollision()
{
	boundCollision.left = getPosition().x - WIDTH_BULLET_HALF;
	boundCollision.right = getPosition().x + WIDTH_BULLET_HALF;
	boundCollision.top = getPosition().y + HEIGHT_BULLET_HALF;
	boundCollision.bottom = getPosition().y - HEIGHT_BULLET_HALF;
}

void Bullet::init(VECTOR2 stPosition)
{
	//if (BulletPool::getInstance()->getCurrentIceBullet())
	//{
	//	Sound::getInstance()->stop(SOUND_BULLET_ICE);
	//	Sound::getInstance()->play(SOUND_BULLET_ICE, false);
	//}
	//else
	//{
	//	Sound::getInstance()->stop(SOUND_BULLET_NORMAL);
	//	Sound::getInstance()->play(SOUND_BULLET_NORMAL, false);
	//}


	this->setPosition(stPosition);
	setBoundCollision();

	this->distance = 0;
	this->setStatus(eStatus::STAND);
	this->isActivity = true;
}

void Bullet::returnPool()
{
	this->setStatus(eStatus::STAND);
	this->setPosition(VECTOR2ZERO);
	setBoundCollision();
	this->sprite->setData(indexSprite);
	isCollided = false;
	this->timer = 0;
	this->isActivity = false;
	this->velocity = VECTOR2ZERO;
}

list<CollisionReturn>* Bullet::getListCollide()
{
	return this->listCollide;
}

float Bullet::getDistanceMax()
{
	return this->distanceMax;
}

void Bullet::setDistanceMax(float distan)
{
	this->distanceMax = distan;
}

void Bullet::setIceBullet()
{
	this->indexSprite = IndexManager::getInstance()->captainBullet[0];
	this->sprite->setData(indexSprite);
	/*this->indexSprite = IndexManager::getInstance()->samusPinkBulletIce;
	this->indexEffect = IndexManager::getInstance()->samusPinkBulletIceColliding;
	this->sprite->setData(indexSprite);*/
}

