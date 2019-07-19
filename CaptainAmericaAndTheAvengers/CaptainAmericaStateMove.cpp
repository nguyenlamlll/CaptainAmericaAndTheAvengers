#include "stdafx.h"
#include "CaptainAmericaStateMove.h"


CaptainAmericaStateMove::CaptainAmericaStateMove()
{
}


CaptainAmericaStateMove::~CaptainAmericaStateMove()
{
}

CaptainAmericaStateMove::CaptainAmericaStateMove(CaptainAmerica* captainAmerica, Input* input)
	: BaseState(captainAmerica, input)
{
	captainAmerica->setOrigin(VECTOR2(0.5, 0.5));
	animation = captainAmerica->getMoveAnimation();
	init();
	animation->start();
}

void CaptainAmericaStateMove::init()
{
}

void CaptainAmericaStateMove::setBoundCollision()
{
}

void CaptainAmericaStateMove::handleInput(float dt)
{
}

void CaptainAmericaStateMove::update(float dt)
{
	animation->update(dt);
}

void CaptainAmericaStateMove::onStart()
{
}

void CaptainAmericaStateMove::onExit()
{
	animation->stop();
}
