#include "stdafx.h"
#include "CaptainAmerica.h"
#include "CaptainAmericaStateManager.h"
#include "Camera.h"
#include "Collision.h"
//#include "GameDebug.h"
//#include "Sound.h"


CaptainAmerica::CaptainAmerica()
{
}

CaptainAmerica::CaptainAmerica(TextureManager * textureM, Graphics * graphics, Input * input) :
	BaseObject(eID::CAPTAINAMERICA)
{
	this->input = input;
	this->textureManager = textureM;
	this->graphics = graphics;

	this->sprite = new Sprite();
	if (!this->sprite->initialize(graphics, textureM, SpriteManager::getInstance()))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not init sprite Samus");
	}

	this->setPosition(VECTOR2(START_POS_X, START_POS_Y));

	attackAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaAttack,
		2,
		0.2f
	);

	dashAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaDash,
		3,
		0.1f
	);

	dieAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaDie,
		2,
		0.1f
	);

	jumpAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaJump,
		1,
		0.1f
	);

	kickAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaKick,
		1,
		0.1f
	);

	lookUpAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaLookUp,
		1,
		0.1f
	);

	moveAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaMove,
		4,
		0.1f
	);

	shieldlessAttackAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaShieldlessAttack,
		2,
		0.1f
	);

	sitAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaSit,
		1,
		0.1f
	);

	sitAttackAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaSitAttack,
		2,
		0.1f
	);

	spinAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaSpin,
		2,
		0.1f
	);

	standAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaStand,
		1,
		0.1f
	);

	
	


	// Initialize the states and their manager class.
	CaptainAmericaStateManager::getInstance()->init(this, input);

	visible = true;
	this->isHaveShield = true;

	shield = new Bullet(textureM, graphics);
	shield->init(VECTOR2(this->getPosition().x, this->getPosition().y + 1));

	listCollide = new list<CollisionReturn>();
}


CaptainAmerica::~CaptainAmerica()
{
}

void CaptainAmerica::handleInput(float dt)
{
	CaptainAmericaStateManager::getInstance()->getCurrentState()->handleInput(dt);
}

void CaptainAmerica::onCollision(float dt)
{
	CaptainAmericaStateManager::getInstance()->getCurrentState()->onCollision(dt);
	this->listCollide->clear();
}

void CaptainAmerica::update(float dt)
{
	this->setVelocityX(this->getVelocity().x + this->getAccelerate().x);
	float deltaX = this->getVelocity().x * dt;
	this->setPositionX(this->getPosition().x + deltaX);

	this->setVelocityY(this->getVelocity().y + this->getAccelerate().y);
	float deltaY = this->getVelocity().y * dt;
	this->setPositionY(this->getPosition().y + deltaY);

	// Gravity
	//this->setVelocityY(this->getVelocity().y + this->getAccelerate().y);

	CaptainAmericaStateManager::getInstance()->getCurrentState()->update(dt);
	if (!this->shield->getFly()) {
		this->shield->setPositionX(this->getPosition().x + 12);
		this->shield->setPositionY(this->getPosition().y + 8);
	}
	else {
		this->shield->update(dt);
		if(this->shield->getBack()) 
		{
			if (Collision::getInstance()->isColliding(this->getBoundCollision(), this->shield->getBoundCollision())) {
				this->shield->setFly(false);
				this->shield->setBack(false);
				this->shield->setVelocity(VECTOR2(0, 0));
			}
		}
	}


#pragma region handle camera
	bool isCameraMoving = false;
	if (!Camera::getInstance()->moveWhenSamusOnPort())
	{
		if (Camera::getInstance()->canFolowOnLeft())
		{
			if (this->getPosition().x < Camera::getInstance()->getActiveArea().left)
			{
				Camera::getInstance()->setVelocity(VECTOR2(this->getVelocity().x, 0));
				isCameraMoving = true;
			}
		}

		if (Camera::getInstance()->canFolowOnRight())
		{
			if (this->getPosition().x > Camera::getInstance()->getActiveArea().right)
			{
				Camera::getInstance()->setVelocity(VECTOR2(this->getVelocity().x, 0));
				isCameraMoving = true;
			}
		}

		if (Camera::getInstance()->canFolowUp() && this->getVelocity().y > 0)
		{
			if (this->getPosition().y > Camera::getInstance()->getActiveArea().top)
			{
				Camera::getInstance()->setVelocity(VECTOR2(0, this->getVelocity().y));
				isCameraMoving = true;
			}
		}

		if (Camera::getInstance()->canFolowDown() && this->getVelocity().y < 0)
		{
			if (this->getPosition().y < Camera::getInstance()->getActiveArea().bottom)
			{
				Camera::getInstance()->setVelocity(VECTOR2(0, this->getVelocity().y));
				isCameraMoving = true;
			}
		}

		if (!isCameraMoving)
			Camera::getInstance()->setVelocity(VECTOR2(0, 0));
	}

	//if (isCollidingPort)
	//	this->setVelocityX(Camera::getInstance()->getVelocity().x);

	//if (moveToFontGate && !Camera::getInstance()->moveWhenSamusOnPort())
	//{
	//	float dis = dt * SAMUS_VERLOCITY_X;
	//	this->distance += dis;

	//	if (this->distance < DISTANCE_MOVE_FRONT_GATE)
	//		this->setPositionX(this->getPosition().x + dis * this->getDirection());
	//	else
	//	{
	//		this->distance = 0;
	//		moveToFontGate = false;
	//		this->setCanMoveLeft(true);
	//		this->setCanMoveRight(true);
	//	}
	//}
#pragma endregion
}

void CaptainAmerica::draw()
{
	if (visible) {
		this->sprite->draw();
		this->shield->draw();
	}
}

void CaptainAmerica::drawIndicators()
{
}

void CaptainAmerica::release()
{
}



