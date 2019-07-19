#include "stdafx.h"
#include "CaptainAmerica.h"
#include "CaptainAmericaStateManager.h"
#include "Camera.h"
//#include "GameDebug.h"
//#include "Sound.h"


//start position
#define START_POS_X 500	
#define START_POS_Y 500

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

	startAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaStart,
		1,
		0.1f);
	moveAnimation = new Animation(
		sprite,
		IndexManager::getInstance()->captainAmericaMove,
		5,
		0.1f
	);

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

Animation * CaptainAmerica::getStartAnimation()
{
	return this->startAnimation;
}

Animation * CaptainAmerica::getMoveAnimation()
{
	return this->moveAnimation;
}
