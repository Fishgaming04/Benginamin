#include "Command.h"
#include <glm/glm.hpp>
#include <iostream>
#include "CounterComponent.h"

namespace dae {


	Command::Command()
	{
	}


	MoveCommand::MoveCommand(GameObject* object, glm::vec3 direction, float speed)
		:Command()
		,m_Direction{direction}
		,m_GameObjPtr{object}
		,m_Speed{speed}
	{
		
	}


	void dae::MoveCommand::Execute(float deltaTime){
		GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getLocalposition() + m_Direction * m_Speed * deltaTime);
	}

	GameObject* MoveCommand::GetGameObject()
	{
		return m_GameObjPtr;
	}


	IncreaseCounter::IncreaseCounter(GameObject* object, std::string counter, int counterIncreaseStep)
		:Command()
		,m_GameObjPtr{object}
		,m_Counter{counter}
		,m_CounterIncreaseStep{counterIncreaseStep}
	{
	}

	void IncreaseCounter::Execute(float)
	{
		int count = GetGameObject()->GetComponent<CounterComponent>()->GetCounter(m_Counter);
		GetGameObject()->GetComponent<CounterComponent>()->SetCounter(m_Counter, count + m_CounterIncreaseStep);
	}

	GameObject* IncreaseCounter::GetGameObject()
	{
		return m_GameObjPtr;
	}

	StateCommand::~StateCommand()
	{
		if (m_StatePtr)
		{
			delete m_StatePtr;
			m_StatePtr = nullptr;
		}
		m_StateMachinePtr = nullptr;
	}

	void StateCommand::SetState(State* state)
	{
		if (m_StatePtr)
		{
			delete m_StatePtr;
		}
		m_StatePtr = state;

	}
	
	void StateCommand::setStateMachine(StateMachine* stateMachine)
	{
		m_StateMachinePtr = stateMachine;
	}

	void StateCommand::setGameObject(GameObject* gameObject)
	{
		m_GameObjPtr = gameObject;
	}
	
	State* StateCommand::GetState()
	{
		return m_StatePtr;
	}

	StateMachine* StateCommand::GetStateMachine()
	{
		return m_StateMachinePtr;
	}

	GameObject* StateCommand::GetGameObject()
	{
		return m_GameObjPtr;
	}
}