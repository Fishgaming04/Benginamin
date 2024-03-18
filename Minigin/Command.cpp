#include "Command.h"
#include <glm/glm.hpp>
#include <iostream>
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
}