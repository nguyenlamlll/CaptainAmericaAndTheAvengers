#include "stdafx.h"
#include "CaptainAmerica.h"
#include "CaptainAmericaStateManager.h"
#include "Camera.h"
//#include "GameDebug.h"
//#include "Sound.h"


//start position
#define START_POS_X 760	
#define START_POS_Y 1680

CaptainAmerica::CaptainAmerica()
{
}

CaptainAmerica::CaptainAmerica(TextureManager * textureM, Graphics * graphics, Input * input) :
	BaseObject(eID::SAMUS)
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
		0.1f
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
}


CaptainAmerica::~CaptainAmerica()
{
}

void CaptainAmerica::handleInput(float dt)
{
	CaptainAmericaStateManager::getInstance()->getCurrentState()->handleInput(dt);
}

void CaptainAmerica::update(float dt)
{
	this->setPositionX(this->getPosition().x + this->getVelocity().x*dt);
	CaptainAmericaStateManager::getInstance()->getCurrentState()->update(dt);
}

void CaptainAmerica::draw()
{
	if (visible) {
		this->sprite->draw();
	}
}

void CaptainAmerica::drawIndicators()
{
}

void CaptainAmerica::release()
{
}

