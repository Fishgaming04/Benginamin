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

	StateCommand::StateCommand(GameObject* object)
		:Command()
		, m_GameObjPtr{ object }
	{

	}

	StateCommand::~StateCommand()
	{
		m_GameObjPtr = nullptr;
	}


	GameObject* StateCommand::GetGameObject()
	{
		return m_GameObjPtr;
	}


}