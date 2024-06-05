#include "CounterComponentObserver.h"
#include "TextComponent.h"


dae::CounterComponentObserver::CounterComponentObserver(GameObject* GameObject)
	: ObserverComponent(GameObject)
	, m_Prefix{}
	, m_Counter{}
{
}

void dae::CounterComponentObserver::OnNotify(Event event, GameObject* actor)
{
	if(event == Event::CounterUpdate && actor->GetComponent<CounterComponent>())
	{
		if(GetGameObject()->GetComponent<TextComponent>())
		{
			GetGameObject()->GetComponent<TextComponent>()->SetText(m_Prefix + std::to_string(actor->GetComponent<CounterComponent>()->GetCounter(m_Counter)));
		}
	}
}


