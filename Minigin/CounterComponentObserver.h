#pragma once
#include "Observers.h"
#include "GameObject.h"
#include "CounterComponent.h"
#include "Components.h"
#include <string>

namespace dae {

	class CounterComponentObserver : public ObserverComponent
	{
	public:
		CounterComponentObserver(GameObject* GameObject);
		void SetPrefix(std::string prefix) { m_Prefix = prefix; }
		void SetCounter(std::string counter) { m_Counter = counter; }



		void OnNotify(Event event, Subject*, const std::any& args);
		virtual ~CounterComponentObserver() {};
		CounterComponentObserver(const CounterComponentObserver& other) = delete;
		CounterComponentObserver(CounterComponentObserver&& other) = delete;
		CounterComponentObserver& operator=(const CounterComponentObserver& other) = delete;
		CounterComponentObserver& operator=(CounterComponentObserver&& other) = delete;
	private:
		std::string m_Prefix;
		std::string m_Counter;
	};

}
