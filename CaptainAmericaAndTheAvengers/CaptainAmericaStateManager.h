#pragma once
#include "BaseState.h"
#include "CaptainAmericaStateStart.h"
#include "CaptainAmericaStateMove.h"

class CaptainAmericaStateManager
{
private: 
	static CaptainAmericaStateManager* instance;

	CaptainAmericaStateStart* stateStart;
	CaptainAmericaStateMove* stateMove;
	//CaptainAmericaStateHit* stateHit;
	//CaptainAmericaStateJump* stateJump;
	//CaptainAmericaStateKick* stateKick;
	//CaptainAmericaStateSitAttack* stateSitAttack;
	//CaptainAmericaStateSpin* CaptainAmericaSpin;

	BaseState* currentState;

	eStatus oldStatus;
	BaseState* oldState;
public:
	static CaptainAmericaStateManager* getInstance();
	CaptainAmericaStateManager();
	~CaptainAmericaStateManager();

	void init(CaptainAmerica*, Input*);
	void setOldStatus(eStatus);
	eStatus getOldStatus();
	void setOldState(BaseState*);
	BaseState* getOldState();

	BaseState* getCurrentState();

	void changeStateTo(eStatus eStatus);

	void release();
};

