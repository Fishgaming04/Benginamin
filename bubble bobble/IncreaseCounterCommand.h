#pragma once
#include "Command.h"

namespace dae {

	class IncreaseCounter final : public Command
	{
	public:

		IncreaseCounter(GameObject* object, std::string counter, int counterIncreaseStep = 1);

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