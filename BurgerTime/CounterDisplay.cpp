#include "CounterDisplay.h"
#include "CounterIncreaseObserver.h"
#include "TextComponent.h"

namespace dae {
	CounterDisplay::CounterDisplay(GameObject* GameObject)
		:ObserverComponent(GameObject)
		, m_Prefix("")
		, m_Counter("")
	{
	}

	void CounterDisplay::OnNotify(Event event, Subject*, const std::any& args)
	{

		if(event == Event::CounterUpdate)
		{
			auto counter{ std::any_cast<UpdateCounterEvent>(args) };
			if(GetGameObject()->GetComponent<TextComponent>() && counter.counterName == m_Counter)
			{
				GetGameObject()->GetComponent<TextComponent>()->SetText(m_Prefix + std::to_string(counter.IncreaseAmount));
			}
		}
	}



}
