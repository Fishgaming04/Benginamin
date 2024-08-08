#pragma once
#include "GameObject.h"
#include <string>
#include "StateMachine.h"

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

	class StateCommand : public Command
	{
	public:
		StateCommand(GameObject* object);
		virtual ~StateCommand() override;
		virtual void Execute(float) override = 0;
	protected:
		GameObject* GetGameObject();
	private:
		GameObject* m_GameObjPtr;
	};

	class MoveCommand final : public Command
	{
	public:

		MoveCommand(GameObject* object, glm::vec3 direction, float speed = 20.0f);
		virtual ~MoveCommand() {};

		virtual void Execute(float deltaTime);

		MoveCommand(const MoveCommand& other) = delete;
		MoveCommand(MoveCommand&& other) = delete;
		MoveCommand& operator=(const MoveCommand& other) = delete;
		MoveCommand& operator=(MoveCommand&& other) = delete;
	protected:
		GameObject* GetGameObject();

	private:

		GameObject* m_GameObjPtr;
		glm::vec3 m_Direction;
		float m_Speed;

	};



}
