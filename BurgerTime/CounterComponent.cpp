#include "CounterComponent.h"
#include "CounterIncreaseObserver.h"

namespace dae
{


	CounterComponent::CounterComponent(GameObject* obj)
		:UpdatingComponent(obj)
		, m_Subject()
	{
	}


	int CounterComponent::GetCounter(std::string name)
	{
		for (auto& counts : m_Counters)
		{
			if (counts.first == name)
			{
				return counts.second;
			}
		}
		return 0;
	}

	void CounterComponent::SetCounter(std::string name, int value)
	{

		for (auto& counts : m_Counters)
		{
			if (counts.first == name && m_Subject.get())
			{
				counts.second += value;
				m_Subject->Notify(Event::CounterUpdate, m_Subject.get(), UpdateCounterEvent{name, counts.second});
				return;
			}
		}
		m_Counters.insert(std::make_pair(name, value));
		GetGameObject()->NotifyObservers(Event::CounterUpdate);

	}
}