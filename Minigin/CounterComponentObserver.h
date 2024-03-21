#pragma once
#include "Observers.h"
#include "GameObject.h"
#include "CounterComponent.h"
#include <string>

namespace dae {

	class CounterComponentObserver : public Observer
	{
	public:
		CounterComponentObserver(GameObject* GameObject, std::string Counter, std::string TextBeforeCounter = "");

		void OnNotify(Event event, GameObject* actor)override;
		virtual ~CounterComponentObserver() {};
		CounterComponentObserver(const CounterComponentObserver& other) = delete;
		CounterComponentObserver(CounterComponentObserver&& other) = delete;
		CounterComponentObserver& operator=(const CounterComponentObserver& other) = delete;
		CounterComponentObserver& operator=(CounterComponentObserver&& other) = delete;
	private:
		GameObject* m_GameObject;
		std::string m_TextBofreCount;
		std::string m_Counter;
	};

}
