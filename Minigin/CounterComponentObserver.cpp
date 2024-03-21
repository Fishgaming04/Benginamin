#include "CounterComponentObserver.h"
#include "TextComponent.h"


dae::CounterComponentObserver::CounterComponentObserver(GameObject* GameObject, std::string Counter, std::string prefix)
	:m_GameObject{GameObject}
	, m_Prefix{prefix}
	, m_Counter{Counter}
{
}

void dae::CounterComponentObserver::OnNotify(Event event, GameObject* actor)
{
	if(event == Event::CounterUpdate && actor->GetComponent<CounterComponent>())
	{
		if(m_GameObject->GetComponent<TextComponent>())
		{
			m_GameObject->GetComponent<TextComponent>()->SetText(m_Prefix + std::to_string(actor->GetComponent<CounterComponent>()->GetCounter(m_Counter)));
		}
	}
}
