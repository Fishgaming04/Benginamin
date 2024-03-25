#pragma once
#include "Components.h"
#include "AchievementObserver.h"
#include "Observers.h"
#include <string>
namespace dae {


	class CounterTriggerAchievementObserver final: public ObserverComponent
	{
		public:
		CounterTriggerAchievementObserver(GameObject* obj);
		virtual ~CounterTriggerAchievementObserver() = default;

		void SetAchievementObserver(AchievementObserver* observer);
		void SetCounterTrigger(std::string counter, int triggerValue);
		void SetAchievement(Event event);

		virtual void OnNotify(Event event, GameObject* actor) override;
		CounterTriggerAchievementObserver(const CounterTriggerAchievementObserver& other) = delete;
		CounterTriggerAchievementObserver(CounterTriggerAchievementObserver&& other) = delete;
		CounterTriggerAchievementObserver& operator=(const CounterTriggerAchievementObserver& other) = delete;
		CounterTriggerAchievementObserver& operator=(CounterTriggerAchievementObserver&& other) = delete;
	private:
		AchievementObserver* m_AchievementObserver;
		std::string m_Counter;
		int m_TriggerValue;
		Event m_AchievementEvent;
	};

}
