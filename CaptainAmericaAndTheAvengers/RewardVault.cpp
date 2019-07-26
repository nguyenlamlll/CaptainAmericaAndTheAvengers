#include "RewardVault.h"
#include "stdafx.h"

RewardVault::RewardVault()
{
}

RewardVault::RewardVault(TextureManager * textureM, Graphics * graphics) : BaseObject(eID::REWARDVAULT)
{
	this->sprite = new Sprite();
	if (!this->sprite->initialize(graphics, textureM, SpriteManager::getInstance()))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not init sprite RewardVault");
	}

	this->anim = new Animation(
		sprite,
		IndexManager::getInstance()->rewardVault,
		1,
		0
	);
	this->anim->start();

	this->isActivity = true;
}


RewardVault::~RewardVault()
{
	delete this->anim;
	delete this->sprite;
}

void RewardVault::update(float dt)
{
	if (isActivity)
	{
		this->anim->update(dt);
	}
}

void RewardVault::draw()
{
	if (isActivity)
	{
		this->sprite->draw();
	}
}

void RewardVault::setActivity(bool flag)
{
	this->isActivity = flag;

	if (this->isActivity == true)
	{
		GameRect bound;

		bound.left = this->getPosition().x;
		bound.top = this->getPosition().y;
		bound.right = bound.left + this->getSprite()->getWidth();
		bound.bottom = bound.top - this->getSprite()->getHeight();

		this->setBoundCollision(bound);
		this->setActiveBound(bound);
	}
	else
	{
		GameRect bound(0, 0, 0, 0);

		this->setBoundCollision(bound);
		this->setActiveBound(bound);

		/*Game::getInstance()->setJustCollectItem(true);*/
	}
}

bool RewardVault::getActivity()
{
	return this->isActivity;
}
