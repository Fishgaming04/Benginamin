#pragma once
#include "Observers.h"
#include "GameObject.h"
#include "Components.h"

namespace dae {

	struct UpdateCounterEvent
	{
		std::string counterName;
		int IncreaseAmount;
	};


	class CounterIncreaseObserver final : public ObserverComponent
	{
	public:
		CounterIncreaseObserver(GameObject* obj);

		virtual ~CounterIncreaseObserver() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;
		void setCounterName(const std::string& name) { m_CounterName = name; }

		CounterIncreaseObserver(const CounterIncreaseObserver& other) = delete;
		CounterIncreaseObserver(CounterIncreaseObserver&& other) = delete;
		CounterIncreaseObserver& operator=(const CounterIncreaseObserver& other) = delete;
		CounterIncreaseObserver& operator=(CounterIncreaseObserver&& other) = delete;
	private:
		std::string m_CounterName;
	};


}

