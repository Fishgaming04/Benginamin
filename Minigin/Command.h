#pragma once
#include "GameObject.h"
#include <string>
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

	class IncreaseCounter final : public Command
	{
	public:

		IncreaseCounter(GameObject* object, std::string counter , int counterIncreaseStep = 1);

		virtual void Execute(float);

		virtual ~IncreaseCounter() {};
		IncreaseCounter(const IncreaseCounter& other) = delete;
		IncreaseCounter(IncreaseCounter&& other) = delete;
		IncreaseCounter& operator=(const IncreaseCounter& other) = delete;
		IncreaseCounter& operator=(IncreaseCounter&& other) = delete;
	protected:
		GameObject* GetGameObject();

	private:

		GameObject* m_GameObjPtr;
		std::string m_Counter;
		int m_CounterIncreaseStep;

	};


}
