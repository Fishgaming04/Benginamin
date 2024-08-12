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

	GameObjectCommand::GameObjectCommand(GameObject* object)
		:Command()
		, m_GameObjPtr{ object }
	{
	}

	GameObjectCommand::~GameObjectCommand()
	{
		m_GameObjPtr = nullptr;
	}


	GameObject* GameObjectCommand::GetGameObject()
	{
		return m_GameObjPtr;
	}


}