#include "PeterCommands.h"
#include "CollisionPlayerComponent.h"
#include "StateMachine.h"
#include "PeterStates.h"

namespace dae {

	//PeterWalkStateCommand
	PeterWalkStateCommand::PeterWalkStateCommand(GameObject* object)
		: GameObjectCommand(object)
	{
	}

	PeterWalkStateCommand::~PeterWalkStateCommand()
	{
	}

	void PeterWalkStateCommand::Execute(float)
	{
		if (GetGameObject()->GetComponent<CollisionPlayersComponent>()->getCanWalk() && !dynamic_cast<PeterWalkingState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()) && !dynamic_cast<PeterHitState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()) ){
			GetGameObject()->GetComponent<StateMachine>()->SetState(new PeterWalkingState{});
		}
	}

	//PeterClimbStateCommand
	PeterClimbStateCommand::PeterClimbStateCommand(GameObject* object)
		: GameObjectCommand(object)
	{
	}

	PeterClimbStateCommand::~PeterClimbStateCommand()
	{
	}

	void PeterClimbStateCommand::Execute(float)
	{
		if (GetGameObject()->GetComponent<CollisionPlayersComponent>()->getCanClimb() && !dynamic_cast<PeterClimbingState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()) && !dynamic_cast<PeterHitState*>(GetGameObject()->GetComponent<StateMachine>()->GetState())) {
			GetGameObject()->GetComponent<StateMachine>()->SetState(new PeterClimbingState{});
		}
	}

	//PeterIdleStateCommand
	PeterIdleStateCommand::PeterIdleStateCommand(GameObject* object)
		: GameObjectCommand(object)
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

	//PeterWalkCommand
	PeterWalkCommand::PeterWalkCommand(GameObject* object, glm::vec3 direction, float speed)
		: GameObjectCommand(object)
		, m_MoveCommand(new MoveCommand(object, direction, speed))
	{
	}

	PeterWalkCommand::~PeterWalkCommand()
	{
		delete m_MoveCommand;
		m_MoveCommand = nullptr;
	}

	void PeterWalkCommand::Execute(float deltaTime)
	{
		if (dynamic_cast<PeterWalkingState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()))
		{
			m_MoveCommand->Execute(deltaTime);
		}
	}

	//PeterClimbCommand
	PeterClimbCommand::PeterClimbCommand(GameObject* object, glm::vec3 direction, float speed)
		: GameObjectCommand(object)
		, m_MoveCommand(new MoveCommand(object, direction, speed))
	{
	}

	PeterClimbCommand::~PeterClimbCommand()
	{
		delete m_MoveCommand;
		m_MoveCommand = nullptr;
	}

	void PeterClimbCommand::Execute(float deltaTime)
	{
		if (dynamic_cast<PeterClimbingState*>(GetGameObject()->GetComponent<StateMachine>()->GetState()))
		{
			m_MoveCommand->Execute(deltaTime);
		}
	}
}