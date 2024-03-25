#include "AchievementObserver.h"
#include <iostream>




dae::AchievementObserver::~AchievementObserver()
{
}

void dae::AchievementObserver::setAchievements(CSteamAchievements* Achievements)
{
	m_AchievementsPtr = Achievements;
}

void dae::AchievementObserver::OnNotify(Event event, GameObject*)
{
	if (event == Event::Win)
	{
		// Check if the player has won 1 game
		if (!win) {
			if (m_AchievementsPtr) {
				m_AchievementsPtr->SetAchievement("ACH_WIN_ONE_GAME");
				win = true;
			}
		}

	}
	else if (event == Event::Win100)
	{
		// Check if the player has won 100 games
		if (m_AchievementsPtr)
			m_AchievementsPtr->SetAchievement("ACH_WIN_100_GAMES");
	}
	else if (event == Event::TravelFarAccum)
	{
		// Check if the player has traveled far
		if (m_AchievementsPtr)
			m_AchievementsPtr->SetAchievement("ACH_TRAVEL_FAR_ACCUM");
	}
	else if (event == Event::TravelFarSingle)
	{
		// Check if the player has traveled far in a single game
		if (m_AchievementsPtr)
			m_AchievementsPtr->SetAchievement("ACH_TRAVEL_FAR_SINGLE");
	}
}