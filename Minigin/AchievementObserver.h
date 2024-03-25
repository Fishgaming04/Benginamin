#pragma once
#include "Components.h"
#include "CounterComponent.h"
#include "Achievements.h"
#include "Observers.h"

namespace dae {

	class AchievementObserver final : public Observer
	{
    public:
        AchievementObserver() {};
        virtual ~AchievementObserver();
        void setAchievements(CSteamAchievements* Achievements);



        virtual void OnNotify(Event event, GameObject*);

        AchievementObserver(const AchievementObserver& other) = delete;
        AchievementObserver(AchievementObserver&& other) = delete;
        AchievementObserver& operator=(const AchievementObserver& other) = delete;
        AchievementObserver& operator=(AchievementObserver&& other) = delete;
    private:
        CSteamAchievements* m_AchievementsPtr{};
        bool win = false;
	};
}

