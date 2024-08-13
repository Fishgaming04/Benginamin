#include "CounterIncreaseObserver.h"
//#include "CounterComponent.h"
#include "GameObject.h"

namespace dae {
	CounterIncreaseObserver::CounterIncreaseObserver(GameObject* obj)
		:ObserverComponent(obj)
	{
	}

	void CounterIncreaseObserver::OnNotify(Event event, Subject*, const std::any& args)
	{
		if (event == Event::UpdateCounter)
		{
			UpdateCounterEvent counter{ std::any_cast<UpdateCounterEvent>(args) };

			if (counter.counterName == m_CounterName)
			{
				//if (!GetGameObject()->GetComponent<CounterComponent>()) {
					//GetGameObject()->AddComponent<CounterComponent>();
				//}
				GetGameObject()->GetComponent<CounterComponent>()->SetCounter(m_CounterName, counter.IncreaseAmount);
			}
		}
	}
}
