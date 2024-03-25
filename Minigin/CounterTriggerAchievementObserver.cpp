#include "CounterTriggerAchievementObserver.h"

dae::CounterTriggerAchievementObserver::CounterTriggerAchievementObserver(GameObject* obj)
	:ObserverComponent(obj)
	, m_AchievementObserver(nullptr)
	, m_Counter("")
	, m_TriggerValue(0)
	, m_AchievementEvent()
{
}

void dae::CounterTriggerAchievementObserver::SetAchievementObserver(AchievementObserver* observer)
{
	m_AchievementObserver = observer;
}

void dae::CounterTriggerAchievementObserver::SetCounterTrigger(std::string counter, int triggerValue)
{
	m_Counter = counter;
	m_TriggerValue = triggerValue;
}

void dae::CounterTriggerAchievementObserver::SetAchievement(Event event)
{	
	m_AchievementEvent = event;
}

void dae::CounterTriggerAchievementObserver::OnNotify(Event event, GameObject* actor)
{
	if (event == Event::CounterUpdate)
	{
		auto counter = actor->GetComponent<CounterComponent>()->GetCounter(m_Counter);
		if (counter >= m_TriggerValue)
		{
			m_AchievementObserver->OnNotify(m_AchievementEvent, GetGameObject());

		}
	}
}