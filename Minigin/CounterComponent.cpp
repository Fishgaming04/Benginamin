#include "CounterComponent.h"


namespace dae
{


	CounterComponent::CounterComponent(GameObject* obj)
		:UpdatingComponent(obj)
	{
	}


	int CounterComponent::GetCounter(std::string health)
	{
		for (auto& counts : m_Counters)
		{
			if (counts.first == health)
			{
				return counts.second;
			}
		}
		return 0;
	}

	void CounterComponent::SetCounter(std::string name, int value)
	{

		for (auto& counts: m_Counters)
		{
			if (counts.first == name)
			{
				counts.second = value;
				return;
			}
		}
		GetGameObject()->NotifyObservers(Event::CounterUpdate);
		m_Counters.insert(std::make_pair(name, value));

	}
}