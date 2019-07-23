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
	stateStand = new CaptainAmericaStateStand();
	currentState = stateStand;
	instance = this;
}


CaptainAmericaStateManager::~CaptainAmericaStateManager()
{
}

void CaptainAmericaStateManager::init(CaptainAmerica* captainAmerica, Input* input)
{
	stateAttack = new CaptainAmericaStateAttack(captainAmerica, input);
	stateDash = new CaptainAmericaStateDash(captainAmerica, input);
	stateDie = new CaptainAmericaStateDie(captainAmerica, input);
	stateJump = new CaptainAmericaStateJump(captainAmerica, input);
	stateKick = new CaptainAmericaStateKick(captainAmerica, input);
	stateLookUp = new CaptainAmericaStateLookUp(captainAmerica, input);
	stateMove = new CaptainAmericaStateMove(captainAmerica, input);
	stateShieldlessAttack = new CaptainAmericaStateShieldlessAttack(captainAmerica, input);
	stateSit = new CaptainAmericaStateSit(captainAmerica, input);
	stateSitAttack = new CaptainAmericaStateSitAttack(captainAmerica, input);
	stateSpin = new CaptainAmericaStateSpin(captainAmerica, input);
	stateStand = new CaptainAmericaStateStand(captainAmerica, input);


	currentState = stateStand;
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
	if (currentState != nullptr) {
		oldStatus = currentState->getName();
		currentState->onExit();
	}

	switch (eStatus)
	{
	case eStatus::ATTACK:
		currentState = stateAttack;
		break;
	case eStatus::DASH:
		currentState = stateDash;
		break;
	case eStatus::DIE:
		currentState = stateDie;
		break;
	case eStatus::JUMP:
		currentState = stateJump;
		break;
	case eStatus::KICK:
		currentState = stateKick;
		break;
	case eStatus::LOOKUP:
		currentState = stateLookUp;
		break;
	case eStatus::MOVE:
		currentState = stateMove;
		break;
	case eStatus::SHILEDLESSATTACK:
		currentState = stateShieldlessAttack;
		break;
	case eStatus::SIT:
		currentState = stateSit;
		break;
	case eStatus::SITATTACK:
		currentState = stateSitAttack;
		break;
	case eStatus::SPIN:
		currentState = stateSpin;
		break;
	case eStatus::STAND:
		currentState = stateStand;
		break;
	default:
		break;
	}


	currentState->init();
	currentState->onStart();
}

void CaptainAmericaStateManager::release()
{
	delete stateStand;
	delete stateMove;
	delete instance;
}