#pragma once
#include "GameObject.h"

namespace dae {
	

	class Command
	{
	public:
		explicit Command();
		virtual ~Command() {};
		
		virtual void Execute(float) = 0;
		
		Command(const Command& other) = delete;
		Command(Command&& other) = delete;
		Command& operator=(const Command& other) = delete;
		Command& operator=(Command&& other) = delete;


	};

	class MoveHorizontal : public Command
	{
	public:

		MoveHorizontal(GameObject* object, glm::vec3 direction, float speed = 20.0f);
		virtual ~MoveHorizontal() {};

		virtual void Execute(float deltaTime);

		MoveHorizontal(const MoveHorizontal& other) = delete;
		MoveHorizontal(MoveHorizontal&& other) = delete;
		MoveHorizontal& operator=(const MoveHorizontal& other) = delete;
		MoveHorizontal& operator=(MoveHorizontal&& other) = delete;
	protected:
		GameObject* GetGameObject();

	private:

		GameObject* m_GameObjPtr;
		glm::vec3 m_Direction;
		float m_Speed;

	};


}
