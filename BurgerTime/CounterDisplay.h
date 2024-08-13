#pragma once
#include "Observers.h"
#include "GameObject.h"
#include "CounterComponent.h"
#include "Components.h"
#include <string>

namespace dae {

	class CounterDisplay : public ObserverComponent
	{
	public:
		CounterDisplay(GameObject* GameObject);
		void SetPrefix(std::string prefix) { m_Prefix = prefix; }
		void SetCounter(std::string counter) { m_Counter = counter; }



		void OnNotify(Event event, Subject*, const std::any& args);
		virtual ~CounterDisplay() {};
		CounterDisplay(const CounterDisplay& other) = delete;
		CounterDisplay(CounterDisplay&& other) = delete;
		CounterDisplay& operator=(const CounterDisplay& other) = delete;
		CounterDisplay& operator=(CounterDisplay&& other) = delete;
	private:
		std::string m_Prefix;
		std::string m_Counter;
	};

}