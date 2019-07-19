#include "stdafx.h"
#include "CaptainAmericaStateManager.h"

CaptainAmericaStateManager* CaptainAmericaStateManager::instance = nullptr;
CaptainAmericaStateManager * CaptainAmericaStateManager::getInstance()
{
	if (instance == nullptr)
		instance = new CaptainAmericaStateManager();

	return instance;
}
CaptainAmericaStateManager::CaptainAmericaStateManager()
{
	stateStart = new CaptainAmericaStateStart();
	currentState = stateStart;
	instance = this;
}


CaptainAmericaStateManager::~CaptainAmericaStateManager()
{
}

void CaptainAmericaStateManager::init(CaptainAmerica* captainAmerica, Input* input)
{
	stateStart = new CaptainAmericaStateStart(captainAmerica, input);
	stateMove = new CaptainAmericaStateMove(captainAmerica, input);
	stateHit = new CaptainAmericaStateHit(captainAmerica, input);
	stateKick = new CaptainAmericaStateKick(captainAmerica, input);
	stateSitAttack = new CaptainAmericaStateSitAttack(captainAmerica, input);
	stateSpin = new CaptainAmericaStateSpin(captainAmerica, input);
	stateJump = new CaptainAmericaStateJump(captainAmerica, input);
	currentState = stateStart;
}

void CaptainAmericaStateManager::setOldStatus(eStatus status)
{
	this->oldStatus = status;
}

eStatus CaptainAmericaStateManager::getOldStatus()
{
	return this->oldStatus;
}

void CaptainAmericaStateManager::setOldState(BaseState * state)
{
	this->oldState = state;
}

BaseState * CaptainAmericaStateManager::getOldState()
{
	return this->oldState;
}

BaseState * CaptainAmericaStateManager::getCurrentState()
{
	return this->currentState;
}

void CaptainAmericaStateManager::changeStateTo(eStatus eStatus)
{
	if (currentState != nullptr)
		currentState->onExit();

	switch (eStatus)
	{
	case eStatus::START:
	{
		currentState = stateStart;
		break;
	}
	case eStatus::MOVE:
		currentState = stateMove;
		break;
	case eStatus::SITATTACK:
		currentState = stateSitAttack;
		break;
	case eStatus::SPIN:
		currentState = stateSpin;
		break;
	case eStatus::HIT:
		currentState = stateHit;
		break;
	case eStatus::JUMP:
		currentState = stateJump;
		break;
	case eStatus::KICK:
		currentState = stateKick;
		break;
	default:
		break;
	}


	currentState->init();
	currentState->onStart();
}

void CaptainAmericaStateManager::release()
{
	delete stateStart;
	delete stateMove;
	delete instance;
}