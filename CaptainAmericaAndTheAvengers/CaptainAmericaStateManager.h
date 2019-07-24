#pragma once
#include "BaseState.h"
#include "CaptainAmericaStateAttack.h"
#include "CaptainAmericaStateDash.h"
#include "CaptainAmericaStateDie.h"
#include "CaptainAmericaStateJump.h"
#include "CaptainAmericaStateKick.h"
#include "CaptainAmericaStateLookUp.h"
#include "CaptainAmericaStateMove.h"
#include "CaptainAmericaStateShieldlessAttack.h"
#include "CaptainAmericaStateSit.h"
#include "CaptainAmericaStateSitAttack.h"
#include "CaptainAmericaStateSpin.h"
#include "CaptainAmericaStateStand.h"



class CaptainAmericaStateManager
{
private: 
	static CaptainAmericaStateManager* instance;

	CaptainAmericaStateAttack* stateAttack;
	CaptainAmericaStateDash* stateDash;
	CaptainAmericaStateDie* stateDie;
	CaptainAmericaStateJump* stateJump;
	CaptainAmericaStateKick* stateKick;
	CaptainAmericaStateLookUp* stateLookUp;
	CaptainAmericaStateMove* stateMove;
	CaptainAmericaStateShieldlessAttack* stateShieldlessAttack;
	CaptainAmericaStateSit* stateSit;
	CaptainAmericaStateSitAttack* stateSitAttack;
	CaptainAmericaStateSpin* stateSpin;
	CaptainAmericaStateStand* stateStand;

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

