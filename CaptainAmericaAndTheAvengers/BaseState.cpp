#include "stdafx.h"
#include "BaseState.h"

BaseState::BaseState()
{
	this->captainAmerica = nullptr;
}

BaseState::BaseState(CaptainAmerica * captainAmerica, Input* input)
{
	this->captainAmerica = captainAmerica;
	this->input = input;
}


BaseState::~BaseState()
{
}

void BaseState::setBoundCollision()
{
}

void BaseState::onCollision(float dt)
{
}

eStatus BaseState::getName()
{
	return this->captainAmerica->getStatus();
}

