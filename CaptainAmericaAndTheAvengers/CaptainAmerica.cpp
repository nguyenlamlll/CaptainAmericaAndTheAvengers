#include "stdafx.h"
#include "CaptainAmerica.h"
#include "CaptainAmericaStateManager.h"
#include "Camera.h"
//#include "GameDebug.h"
//#include "Sound.h"


//start position
#define START_POS_X 650	
#define START_POS_Y 1770

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

	
	hitAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaHit,
		4,
		0.1f
	);
	jumpAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaJump,
		3,
		0.1f
	);
	kickAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaKick,
		5,
		0.1f
	);
	startAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaStart,
		1,
		0.1f
	);
	moveAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaMove,
		5,
		0.1f
	);
	sitAttackAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaSitAttack,
		5,
		0.1f
	);
	spinAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaSpin,
		7,
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

