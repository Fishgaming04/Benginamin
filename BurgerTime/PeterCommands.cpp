#include "PeterCommands.h"
#include "CollisionPlayerComponent.h"
#include "StateMachine.h"
#include "PeterStates.h"

namespace dae {

	//PeterWalkStateCommand
	PeterWalkStateCommand::PeterWalkStateCommand(GameObject* object)
		: StateCommand(object)
	{
	}

	PeterWalkStateCommand::~PeterWalkStateCommand()
	{
	}

	void PeterWalkStateCommand::Execute(float)
	{
		if (GetGameObject()->GetComponent<CollisionPlayersComponent>()->getCanWalk() && !dynamic_cast<PeterHitState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()) ){
			GetGameObject()->GetComponent<StateMachine>()->SetState(new PeterWalkingState{});
		}
	}

	//PeterClimbStateCommand
	PeterClimbStateCommand::PeterClimbStateCommand(GameObject* object)
		: StateCommand(object)
	{
	}

	PeterClimbStateCommand::~PeterClimbStateCommand()
	{
	}

	void PeterClimbStateCommand::Execute(float)
	{
		if (GetGameObject()->GetComponent<CollisionPlayersComponent>()->getCanClimb() && !dynamic_cast<PeterHitState*>(GetGameObject()->GetComponent<StateMachine>()->GetState())) {
			GetGameObject()->GetComponent<StateMachine>()->SetState(new PeterClimbingState{});
		}
	}

	//PeterIdleStateCommand
	PeterIdleStateCommand::PeterIdleStateCommand(GameObject* object)
		: StateCommand(object)
	{
	}

	PeterIdleStateCommand::~PeterIdleStateCommand()
	{
	}

	void PeterIdleStateCommand::Execute(float)
	{
		if (!dynamic_cast<PeterHitState*>(GetGameObject()->GetComponent<StateMachine>()->GetState())) {
			GetGameObject()->GetComponent<StateMachine>()->SetState(new PeterIdleState{});
		}
	}
}