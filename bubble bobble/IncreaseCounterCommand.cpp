#include "IncreaseCounterCommand.h"
#include "CounterComponent.h"
namespace dae{
	IncreaseCounter::IncreaseCounter(GameObject* object, std::string counter, int counterIncreaseStep)
		:Command()
		, m_GameObjPtr{ object }
		, m_Counter{ counter }
		, m_CounterIncreaseStep{ counterIncreaseStep }
	{
	}

	void IncreaseCounter::Execute(float)
	{
		int count = GetGameObject()->GetComponent<CountingComponent>()->GetCounter(m_Counter);
		GetGameObject()->GetComponent<CountingComponent>()->SetCounter(m_Counter, count + m_CounterIncreaseStep);
	}

	GameObject* IncreaseCounter::GetGameObject()
	{
		return m_GameObjPtr;
	}
}