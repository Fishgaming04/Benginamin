#include "HealthComponent.h"


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

	void CounterComponent::SetCounter(std::string health, int value)
	{
		for (auto& counts: m_Counters)
		{
			if (counts.first == health)
			{
				counts.second = value;
				return;
			}
		}

		m_Counters.insert(std::make_pair(health, value));
	}

}