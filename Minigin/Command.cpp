#include "Command.h"
#include <glm/glm.hpp>
#include <iostream>
namespace dae {


	Command::Command()
	{
	}


	MoveHorizontal::MoveHorizontal(GameObject* object, glm::vec3 direction, float speed)
		:Command()
		,m_Direction{direction}
		,m_GameObjPtr{object}
		,m_Speed{speed}
	{
		
	}


	void dae::MoveHorizontal::Execute(float deltaTime){
		GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getLocalposition() + m_Direction * m_Speed * deltaTime);
	}

	GameObject* MoveHorizontal::GetGameObject()
	{
		return m_GameObjPtr;
	}
}